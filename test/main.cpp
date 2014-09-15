//!
//! @file 			main.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-09-05
//! @last-modified 	2014-09-15
//! @brief 			Contains main entry point for unit tests.
//! @details
//!					See README.rst in root dir for more info.

// System libraries
#include <iostream>

// User libraries
#include "MUnitTest/api/MUnitTestApi.hpp"

// User source
// none


int main()
{

	// Run all unit tests and return the result
	return MbeddedNinja::TestRegister::RunAllTests();
	
}
