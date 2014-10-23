//!
//! @file				Gpio.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-08-18
//! @last-modified		2014-10-24
//! @brief 				Hardware abstraction layer (HAL) for a GPIO pin.
//! @details
//!						

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
// none

//===== USER LIBRARIES =====//
#include "MAssert/api/MAssertApi.hpp"

//===== USER SOURCE =====//
#include "../include/Gpio.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MHalNs
	{

		void Gpio::Toggle()
		{
			// Lets call the Write() method to perform the change
			if(this->isHigh)
				this->Write(false);
			else
				this->Write(true);
		}

	} // namespace MHalNs
} // namespace MbeddedNinja

// EOF
