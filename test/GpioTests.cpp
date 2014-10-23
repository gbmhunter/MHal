//!
//! @file 			GpioTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-24
//! @last-modified 	2014-10-24
//! @brief 			Contains GPIO unit tests.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
// none

//===== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

#include "../api/MHalApi.hpp"
#include "../port/Linux/LinuxGpio.hpp"

//===== USER SOURCE =====//



using namespace MbeddedNinja;

namespace MHalTestsNs
{

	MTEST(BasicWriteTest)
	{
		MHalNs::LinuxGpio linuxGpio;

		// Set the pin to the high state
		linuxGpio.Write(1);

		CHECK_EQUAL(linuxGpio.Read(), 1);

		// Set the pin to the low state
		linuxGpio.Write(0);

		CHECK_EQUAL(linuxGpio.Read(), 0);
	}

	MTEST(ToggleTest)
	{
		MHalNs::LinuxGpio linuxGpio;

		// Pin should start of in the low state
		CHECK_EQUAL(linuxGpio.Read(), 0);

		// Lets toggle the pin, and make sure it changes state
		linuxGpio.Toggle();

		CHECK_EQUAL(linuxGpio.Read(), 1);

		linuxGpio.Toggle();

		CHECK_EQUAL(linuxGpio.Read(), 0);
	}

} // namespace MHalTestsNs
