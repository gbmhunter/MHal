//!
//! @file				PsocGpio.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-09-12
//! @last-modified		2014-09-23
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
#include "MAssert/api/MAssertApi.hpp"		// M_ASSERT(), M_ASSERT_FAIL()

extern "C"
{
	// PSoC generated project file, contains the definitions for PIN_DM_STRONG and other
	// drive mode macros
	#include <project.h>
}

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
					void (* writePin)(uint8_t lowHigh),
					void (* setDriveMode)(uint8_t mode))
				{
					M_ASSERT(readPin);
					this->readPin = readPin;

					M_ASSERT(writePin);
					this->writePin = writePin;

					M_ASSERT(setDriveMode);
					this->setDriveMode = setDriveMode;
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

				void SetDriveMode(DriveMode driveMode)
				{
					switch(driveMode)
					{
						case DriveMode::STRONG_DRIVE:
							this->setDriveMode(PIN_DM_STRONG);
							break;
						case DriveMode::OPEN_DRAIN_DRIVE_LOW:
							this->setDriveMode(PIN_DM_OD_LO);
							break;
						case DriveMode::OPEN_DRAIN_DRIVE_HIGH:
							this->setDriveMode(PIN_DM_OD_HI);
							break;
						case DriveMode::RES_PULL_UP:
							this->setDriveMode(PIN_DM_RES_UP);
							break;
						case DriveMode::RES_PULL_DOWN:
							this->setDriveMode(PIN_DM_RES_DWN);
							break;
						case DriveMode::RES_PULL_UPDOWN:
							this->setDriveMode(PIN_DM_RES_UPDWN);
							break;
						case DriveMode::HIGH_Z_DIGITAL:
							this->setDriveMode(PIN_DM_DIG_HIZ);
							break;
						case DriveMode::HIGH_Z_ANALOG:
							this->setDriveMode(PIN_DM_ALG_HIZ);
							break;
						default:
							M_ASSERT_FAIL("%s", "Specified drive mode not supported.");
							break;
					}
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

				//! @brief		Function pointer to PSoC Pin_SetDriveMode() function.
				//! @details	Initialised in the constructor.
				void (* setDriveMode)(uint8_t mode);

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
