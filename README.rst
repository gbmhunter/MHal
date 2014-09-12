====
MHal
====

---------------------------------------------------------------------------------
A C++ hardware abstraction layer for embedded systems (such as microcontrollers).
---------------------------------------------------------------------------------

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- Created: 2014-08-18
- Last Modified: 2014-09-12
- Version: v1.0.0.0
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

Supported Compilers
===================

- GCC v4.7 or later


Installation
============

1. Clone the git repo onto your local storage.
2. Include the relevant platform-specific headers from :code:'port/'. For example, if you are using PSoC, you would include:

- :code:`PsocHalGpio.hpp`
- :code:`PsocHalUart.hpp`


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
	#include "MHal/port/PSoC/PsocHalGpio.hpp"
	
	using namespace MbeddedNinja;
	
	int main()
	{
		// Create a new PSoC GPIO object
		MHalNs::HalGpio * myGpioPin = new MHalNs::PsocHalGpio(
			&MyGpioOnTopDesign_Read,		// These are pointers to the pin API functions PSoC Creator automatically produces
			&MyGpioOnTopDesign_Write);
		
		// Note, if I was on an Arduino instead, I could just of easily typed this...
		// MHalNs::HalGpio * myArduinoPin = new MHalNs::ArduinoHalGpio(...);
		
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
v1.0.0.0  2014-09-12 Initial commit, added code, closes #1. GPIO and UART HAL objects added. PSoC-specific child classes for these objects added. Added example to README.
========= ========== ===================================================================================================