//!
//! @file 		    	PsocAdc.hpp
//! @author 	    	Geoffrey Hunter (gbmhunter@gmail.com) (www.mbedded.ninja)
//! @created	    	2014-09-15
//! @last-modified  	2014-09-15
//! @brief				A PSoC implementation of a HAL ADC.
//!

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MHAL_PSOC_ADC_H
#define MHAL_PSOC_ADC_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MHalNs
	{
		class PsocAdc;
	}
}

//===============================================================================================//
//================================== HEADER INCLUSIONS ==========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
// none

//===== USER LIBRARIES =====//
#include "MAssert/api/MAssertApi.hpp"		// M_ASSERT() macro
#include "MOsal/api/MOsalApi.hpp"			//

//===== USER SOURCE =====//
#include "../../include/Adc.hpp"			// Adc class

//===============================================================================================//
//===================================== PUBLIC MACROS ===========================================//
//===============================================================================================//

// none

//===============================================================================================//
//=========================================== CLASS =============================================//
//===============================================================================================//


namespace MbeddedNinja
{
	namespace MHalNs
	{

		//! @brief		A PSoC implementation of a HAL ADC.
		//! @note		NOT thread-safe. NOT re-entrant. NOT ISR safe, except for EocIsr().
		class PsocAdc : public Adc
		{
			public:

				//! @brief		PSoC constructor for a ADC object.
				//! @param		adcMode			The desired ADC run mode.
				//! @param		eocMutex		Pointer to mutex to use for blocking until
				//!								ADC "end-of-conversion".
				//! @param		eocMutexTimeoutMs	Maximum time (in milliseconds) to wait for
				//!									ADC conversion to complete before timeout occurs.
				//! @param		start			Pointer to PSoC API function which starts the ADC.
				//! @param		stop			Pointer to PSoC API function which stops the ADC.
				//! @param		startConvert	Pointer to PSoC API fuction which starts an ADC
				//!								conversion
				//! @param		getResult16		Pointer to PSoC API fuction which returns a signed
				//!								16-bit conversion result.
				//! @param		adcCountsToVolts	Pointer to PSoC API fuction which converts the raw ADC counts
				//!									into a float with units volts and returns the result.
				//! @note		NOT thread-safe. NOT re-entrant. NOT ISR safe.
				PsocAdc(
					AdcMode adcMode,
					MOsalNs::Mutex * eocMutex,
					double eocMutexTimeout,
					void (*start)(),
					void (*stop)(),
					void (*startConvert)(),
					int16_t (*getResult16)(),
					float (*adcCountsToVolts)(int16_t)) :
						Adc(adcMode)
				{
					this->adcMode = adcMode;

					// Currently, the user is force to provide the mutex
					// for blocking until EOC. However, this could change
					// in the future.
					M_ASSERT(eocMutex);
					this->eocMutex = eocMutex;

					M_ASSERT(start);
					this->start = start;

					M_ASSERT(stop);
					this->stop = stop;

					M_ASSERT(startConvert);
					this->startConvert = startConvert;

					M_ASSERT(getResult16);
					this->getResult16 = getResult16;

					M_ASSERT(adcCountsToVolts);
					this->adcCountsToVolts = adcCountsToVolts;
				}

				//! @brief		Starts the PSoC ADC.
				bool Start()
				{
					// Starts the ADC
					this->start();
					return true;
				}
				
				//! @brief		Stops the PSoC ADC.
				bool Stop()
				{
					// Stops the ADC
					this->stop();
					return true;
				}

				float MeasureVoltage()
				{
					// Start ADC conversion
					this->startConvert();

					// Now lets block until the "on completion" interrupt
					// frees the mutex
					M_ASSERT(this->eocMutex->Get(eocMutexTimeout));

					// Call PSoC API to get result
					int16_t result = this->getResult16();

					// Convert the result into a double with the units volts,
					// then return
					return this->adcCountsToVolts(result);
				}

				//! @brief		Call from the EOC interrupt. This frees the EOC mutex.
				//! @note		ISR safe.
				void EocIsr()
				{
					// Release EOC ISR
					this->eocMutex->Release();
				}


			private:
				
				//! @brief		Pointer to mutex to use for blocking until
				//!				ADC "end-of-conversion".
				MOsalNs::Mutex * eocMutex;

				//! @brief		Maximum time (in milliseconds) to wait for
				//!				ADC conversion to complete before timeout occurs.
				double eocMutexTimeout;

				void (*start)();
				void (*stop)();
				void (*startConvert)();
				int16_t (*getResult16)();
				float (*adcCountsToVolts)(int16_t);
			
		}; // class PsocAdc

	} // namespace MHalNs
} // namespace MbeddedNinja


#endif // #ifndef MHAL_PSOC_ADC_H
    
// EOF
