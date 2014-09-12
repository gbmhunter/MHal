//!
//! @file 		    	HalUart.cpp
//! @author 	    	Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-07-29
//! @last-modified  	2014-09-12
//! @brief 		    	
//!

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//================================== HEADER INCLUSIONS ==========================================//
//===============================================================================================//

// System libraries
//#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//#include <stdlib.h>		// malloc(), free()
//#include <string.h>		// memset(), memcpy()

// User libraries
// none

// User source
#include "../include/HalUart.hpp"

//===============================================================================================//
//==================================== PRECOMPILER CHECKS =======================================//
//===============================================================================================//

// none

//===============================================================================================//
//===================================== FILE-SCOPE MACROS =======================================//
//===============================================================================================//


namespace UartDvrNs
{


	//===============================================================================================//
	//=================================== PUBLIC METHOD DEFINITIONS =================================//
	//===============================================================================================//
/*
	HalUart::HalUart(			
		void (*start)(),
		void (*stop)(),
		void (*putChar)(uint8_t putChar),
		void (*putString)(const char * string),
		uint8_t (*getRxBufferSize)(),
		uint16_t (*getByte)()) :
			isInitSuccess(false)
	{
		//CyDebugUart_PutString("Debug 1...\r\n");
		if(start == nullptr)
		{
			// FATAL
			return;		
		}
		this->start = start;
		//CyDebugUart_PutString("Debug 2...\r\n");
		if(stop == nullptr)
			// FATAL
			return;	
		this->stop = stop;
		
		if(putChar == nullptr)
		{
			//! @todo Add warning message	
		}
		this->putChar = putChar;
		
		if(putString == nullptr)
		{
			//! @todo Add warning message	
		}
		this->putString = putString;
		
		if(getRxBufferSize == nullptr)
		{
			//! @todo Add warning message	
		}
		this->getRxBufferSize = getRxBufferSize;
		
		if(getByte == nullptr)
		{
			//! @todo Add warning message
		}
		this->getByte = getByte;
		
		// If we get here, initialisation was successful
		this->isInitSuccess = true;
	}
	
	bool HalUart::IsInitSuccess()
	{
		return this->isInitSuccess;	
	}

	bool HalUart::Start()
	{
		if(!this->isInitSuccess)
			return false;
		
		if(this->start == nullptr)
			return false;
								
		this->start();
		return true;
	}
	
	bool HalUart::Stop()
	{
		if(!this->isInitSuccess)
			return false;
		
		if(this->stop == nullptr)
			return false;
		
		this->stop();
		return true;
	}
	
	bool HalUart::PutChar(char myChar)
	{
		if(!this->isInitSuccess)
			return false;
		
		if(this->putChar == nullptr)
			return false;
		
		this->putChar(myChar);
		return true;
	}
	
	bool HalUart::PutString(const char * string)
	{
		if(!this->isInitSuccess)
			return false;
		
		if(this->putString == nullptr)
			return false;
		
		this->putString(string);
		return true;
	}
	
	bool HalUart::IsRxData()
	{
		if(!this->isInitSuccess)
			return false;
		
		if(this->getRxBufferSize == nullptr)
			return false;
		
		// PSoC implementation
		if(this->getRxBufferSize() > 0)
			// There is at least one element in the RX hardware buffer
			return true;
		else
			// There is no data
			return false;
	}
	
	char HalUart::GetChar()
	{
		if(!this->isInitSuccess)
			return false;
		
		if(this->getByte == nullptr)
			return '\0';
		
		// PSoC implementation
		
		uint16_t returnVal = this->getByte();
		// HSB contains error codes
		//! @todo Add error checking
		
		// LSB contains the actual UART data, let's return this
		return (char)returnVal;
	}*/
	
	//===============================================================================================//
	//=================================== PRIVATE METHOD DEFINITIONS ================================//
	//===============================================================================================//



} // namespace UartDvrNs

// EOF
