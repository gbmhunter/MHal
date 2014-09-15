//!
//! @file 		    		Uart.hpp
//! @author 	    		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created	    		2014-07-29
//! @last-modified  		2014-09-15
//! @brief
//!

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MHAL_UART_H
#define MHAL_UART_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MHalNs
	{
		class Uart;
	}
}

//===============================================================================================//
//================================== HEADER INCLUSIONS ==========================================//
//===============================================================================================//

// System libraries
// none

// User libraries
// none

// User source

//===============================================================================================//
//===================================== PUBLIC MACROS ===========================================//
//===============================================================================================//

// none


namespace MbeddedNinja
{

	namespace MHalNs
	{

		//! @brief		Hardware abstraction layer (HAL) for a UART.
		//! @details	Each platform can implement it's own specific constructor depending on the hardware.
		//!				Currently implemented for the PSoC architecture.
		class Uart
		{

		public:

			//! @brief		Virtual destructor.
			virtual ~Uart(){};

			//! @brief		Use to check if initialisation was successful.
			//! @returns	Returns true if initialisation successful, otherwise false.
			//! @note		Thread-safe. Re-entrant. NOT ISR safe.
			bool IsInitSuccess()
			{
				return this->isInitSuccess;
			};

			// See constructor for info on following functions.

			//! @brief	Interface functions between HAL layer and the higher-level drivers.
			//! @note 	These functions declarations need to remain constant across different platforms!
			//! @{
			virtual bool Start() = 0;
			virtual bool Stop() = 0;
			virtual bool PutChar(char myChar) = 0;
			virtual bool PutString(const char * string) = 0;
			virtual bool IsRxData() = 0;
			virtual char GetChar() = 0;
			//! @}

		protected:

			//! @brief		Constructor protected to force inheritance.
			Uart() :
				isInitSuccess(false)
			{};

			//! @brief		Set by constructor when initialisation is complete.
			//! @details	The user can read this variable by calling IsInitSuccess().
			bool isInitSuccess;

		private:
		
			// none
			
		}; // class Uart
	
	} // namespace MHalNs
} // namespace MbeddedNinja

#endif // #ifndef MHAL_UART_H
    
// EOF
