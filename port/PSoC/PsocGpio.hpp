//!
//! @file				PsocGpio.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-12
//! @last-modified		2014-09-15
//! @brief 				
//! @details
//!						

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MHAL_PSOC_GPIO_H
#define MHAL_PSOC_GPIO_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MHalNs
	{
		class PsocGpio;
	}
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// int8_t, int32_t e.t.c

//===== USER LIBRARIES =====//
// none

//===== USER HEADERS =====//
#include "../../include/Gpio.hpp"

namespace MbeddedNinja
{

	namespace MHalNs
	{
		
		class PsocGpio : public Gpio
		{
			
			public:

				//======================================================================================//
				//==================================== PUBLIC METHODS ==================================//
				//======================================================================================//

				//! @brief 		PSoC HAL GPIO constructor.
				//! @param		readPin		Function pointer to PSoC Pin_Read() function.
				//! @param		writePin	Function pointer to PSoC Pin_Write() function.
				PsocGpio(
					uint8_t (* readPin)(),
					void (* writePin)(uint8_t lowHigh))
				{
					this->readPin = readPin;
					this->writePin = writePin;
				};
			
				//! @brief		Destructor doesn't need to do anything.
				~PsocGpio(){}

				//! @brief		Sets the GPIO low or high.
				void Write(bool lowHigh)
				{
					// Call PSoC API function
					this->writePin((uint8_t)lowHigh);
				}

				//! @brief		Reads the value of the pin.
				bool Read()
				{
					// Call PSoC API function
					return (bool)this->readPin();
				}

				//======================================================================================//
				//================================= PUBLIC VARIABLES ===================================//
				//======================================================================================//

				// none

			private:

				//======================================================================================//
				//=================================== PRIVATE METHODS ==================================//
				//======================================================================================//

				// none

				//======================================================================================//
				//================================== PRIVATE VARIABLES =================================//
				//======================================================================================//

				//! @brief		Function pointer to PSoC Pin_Read() function.
				//! @details	Initialised in the constructor.
				uint8_t (* readPin)();

				//! @brief		Function pointer to PSoC Pin_Write() function.
				//! @details	Initialised in the constructor.
				void (* writePin)(uint8_t lowHigh);

			protected:

				//======================================================================================//
				//=================================== PROTECTED METHODS ================================//
				//======================================================================================//
				
				// none
				
				//======================================================================================//
				//================================== PROTECTED VARIABLES ===============================//
				//======================================================================================//

				// none
			
		}; // class PsocGpio


	} // namespace MHalNs
} // namespace MbeddedNinja

#endif	// #ifndef MHAL_PSOC_GPIO_H

// EOF
