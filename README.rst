====
MHal
====

---------------------------------------------------------------------------------
A C++ hardware abstraction layer for embedded systems (such as microcontrollers).
---------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MHal.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MHal

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- Created: 2014-08-18
- Last Modified: 2014-10-14
- Version: v2.2.3.0
- Company: MbeddedNinja
- Project: The Mbedded toolkit (MToolkit) project.
- Language: C++
- Compiler: GCC	
- uC Model: Any
- Computer Architecture: Any
- Operating System: Any (currently FreeRTOS and Linux have the port--specific code written for you!)
- Documentation Format: Doxygen
- License: GPLv3

.. role:: bash(code)
	:language: bash

Description
===========

A C++ hardware abstraction layer for embedded systems (such as microcontrollers). Allows you to use a consistent hardware calling interface through-out your code, keeping your code portable across many platforms.

Uses inhertiance from an abstract iterface class, to provide implementations for various hardware platforms. 

Provided Hardware Abstraction Layers
------------------------------------

- ADC
- GPIO
- UART

Easy To Use
------------

All you have to pretty much have to do is download this repo, and include the relevant headers in your embedded (or otherwise) project!

See the Installation section for more details...

Currently Supported Platforms
-----------------------------

- PSoC

Note it is easy and encourged for you to port this to a specific platform! Just copy the header files in :code:'port/', but replace the methods with the platform-specific code!

Using The ADC
-------------

The ADC currently supports the "SOFTWARE_TRIGGER_INT_ON_COMPLETION" mode. This is where the ADC is started via a software call, and waits until the ADC is complete via an "end-of-completion" (EOC) interrupt firing, at which point the ADC value is read and returned from the method call.

The ADC supports an non-exhaustive block by use of a mutex provided by the OSAL (operating system abstraction layer).

Supported Compilers
===================

- GCC v4.7 or later


Installation
============

1. Clone the git repo onto your local storage.
2. Include the relevant platform-specific headers from :code:'port/'. For example, if you are using PSoC, you would include:

- :code:`PsocAdc.hpp`
- :code:`PsocGpio.hpp`
- :code:`PsocUart.hpp`


Code Dependencies
=================

The following table lists all of MHal's dependencies. Note that this EXCLUDES the dependecies relevant to the specific platform you are going to use (i.e. excludes all dependecies of files in :code:'port/').

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================
<ctsdint>              C standard library   For platform agnostic fixed-width integers.
MAssert                External module      Providing runtime csafety checks against this module.
MUnitTest              External module      Framework for unit tests.
====================== ==================== ======================================================================

Issues
======

See GitHub Issues.

Examples
========

Basic Example Using PSoC As Our Platform
----------------------------------------

::

	// Is we were on a PSoC platform, include this, so we have access to the pin API fuctions
	// that PSoC Creator produces for us (inputted into the PsocHalGpio constructor below)
	#include <project.h>

	// Include the generic OSAL API
	#include "MHal/api/MHalApi.hpp"
	
	// Say we are on a PSoC, so we include the PSoC-specific headers from port/
	#include "MHal/port/PSoC/PsocGpio.hpp"
	
	using namespace MbeddedNinja;
	
	int main()
	{
		// Create a new PSoC GPIO object
		MHalNs::Gpio * myGpioPin = new MHalNs::PsocGpio(
			&MyGpioOnTopDesign_Read,		// These are pointers to the pin API functions PSoC Creator automatically produces
			&MyGpioOnTopDesign_Write);
		
		// Note, if I was on an Arduino instead, I could just of easily typed this...
		// MHalNs::Gpio * myArduinoPin = new MHalNs::ArduinoGpio(...);
		
		// All done! 
		// Now we can pass the generic HalGpio object to other modules
		// that need to make use of the hardware features.
		// They don't care whether we are using a PSoC or Arduino (or any
		// other platform for that matter)!
		CoolModule1 * coolModule1 = new CoolModule1(myGpioPin);
		CoolModule2 * coolModule2 = new CoolModule2(myGpioPin);
	}
	
FAQ
===

Nothing here yet...

Changelog
=========

========= ========== ===================================================================================================
Version    Date       Comment
========= ========== ===================================================================================================
v2.2.3.0  2014-10-14 Makefile now compiles with C++11, closes #8. Added Linux GPIO implementation, closes #9.
v2.2.2.0  2014-10-14 Makefile generates output file libMOsal.a when it really should be libMHal.a, closes #7.
v2.2.1.0  2014-09-23 Fixed Makefile so that hopefully TravisCI will build properly.
v2.2.0.0  2014-09-23 Add .travis.yml file and build image to README, closes #6.
v2.1.0.0  2014-09-23 Added the 'Gpio::SetDriveMode()' method and implementation for the PSoC platform, closes #5. Updated URL in Makefile.
v2.0.0.0  2014-09-15 Added hardware abstraction layer for a ADC, closes #2. Wrapped all code in the MbeddedNinja namespace, closes #3. Dropped the Hal prefix on code files and classes, as it is not needed, closes #4.
v1.0.0.0  2014-09-12 Initial commit, added code, closes #1. GPIO and UART HAL objects added. PSoC-specific child classes for these objects added. Added example to README.
========= ========== ===================================================================================================