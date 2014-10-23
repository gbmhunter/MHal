//!
//! @file				LinuxGpio.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-14
//! @last-modified		2014-10-14
//! @brief 				
//! @details
//!						

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MHAL_LINUX_GPIO_H
#define MHAL_LINUX_GPIO_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MHalNs
	{
		class LinuxGpio;
	}
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// int8_t, int32_t e.t.c

//===== USER LIBRARIES =====//
#include "MAssert/api/MAssertApi.hpp"		// M_ASSERT(), M_ASSERT_FAIL()

//===== USER HEADERS =====//
#include "../../include/Gpio.hpp"

namespace MbeddedNinja
{

	namespace MHalNs
	{
		
		class LinuxGpio : public Gpio
		{
			
			public:

			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//

			//! @brief 		Linux HAL GPIO constructor.
			LinuxGpio()
			{
				// Don't need to do anything here
			}

			//! @brief		Destructor doesn't need to do anything.
			~LinuxGpio(){}

			//! @brief		Sets the GPIO low or high.
			void Write(bool setHigh)
			{
				if(setHigh)
				{
					this->isHigh = true;
					std::cout << "GPIO set high." << std::endl;
				}
				else
				{
					this->isHigh = false;
					std::cout << "GPIO set low." << std::endl;
				}
			}

			//! @brief		Reads the value of the pin.
			bool Read()
			{
				std::cout << __PRETTY_FUNCTION__ << " called." << std::endl;

				if(this->isHigh)
				{
					return true;
				}
				else
				{
					return false;
				}

			}

			void SetDriveMode(DriveMode driveMode)
			{
				M_ASSERT_FAIL("%s", "SetDriveMode() not supported with LinuxGpio.");
			}
			
		}; // class LinuxGpio


	} // namespace MHalNs
} // namespace MbeddedNinja

#endif	// #ifndef MHAL_LINUX_GPIO_H

// EOF
