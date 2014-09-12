//!
//! @file 		    	PsocHalUart.hpp
//! @author 	    	Geoffrey Hunter (gbmhunter@gmail.com) (www.mbedded.ninja)
//! @created	    	2014-07-29
//! @last-modified  	2014-09-12
//! @brief
//!

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MHAL_PSOC_HAL_UART_H
#define MHAL_PSOC_HAL_UART_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MHalNs
{
	class PsocHalUart;
}

//===============================================================================================//
//================================== HEADER INCLUSIONS ==========================================//
//===============================================================================================//

// System libraries
// none

// User libraries
// none

// User source
#include "../../include/HalUart.hpp"

//===============================================================================================//
//===================================== PUBLIC MACROS ===========================================//
//===============================================================================================//

// none

//===============================================================================================//
//==================================== FILE-SCOPE TYPEDEF's =====================================//
//===============================================================================================//

namespace MHalNs
{

	//! @brief		HAL UART object. Used by the UartDvr class.
	//! @details	Each platform can implement it's own specific constructor depending on the hardware.
	//!				Currently implemented for the PSoC architecture.
	class PsocHalUart : public HalUart
	{
		public:
		
		
			//! @brief		PSoC constructor for a HAL UART object.		
			//! @param		start		Pointer to HAL function which starts the UART.
			//! @param		stop		Pointer to HAL function which stops the UART.
			//! @param		putChar		Pointer to HAL function which sends a character.
			//! @param		putString	Pointer to HAL function which sends a string of characters. Can be blocking.
			//! @param		isRxData	Pointer to HAL function which returns true if there is data present
			//!							in the RX hardware buffer.
			//! @param		getByte		Pointer to HAL function which returns a character from the RX hardware buffer.
			//! @note		NOT thread-safe. NOT re-entrant. NOT ISR safe.			
			PsocHalUart(			
				void (*start)(),
				void (*stop)(),
				void (*putChar)(uint8_t putChar),
				void (*putString)(const char * string),
				uint8_t (*getRxBufferSize)(),
				uint16_t (*getByte)())
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
			
			// See constructor for info on following functions.
			
			//! @brief	Interface functions between HAL layer and the higher-level drivers.
			//! @note 	These functions declarations need to remain constant across different platforms!
			//! @{
			bool Start()
			{
				if(!this->isInitSuccess)
					return false;
				
				if(this->start == nullptr)
					return false;
										
				this->start();
				return true;

			}
			
			bool Stop()
			{
				if(!this->isInitSuccess)
					return false;
				
				if(this->stop == nullptr)
					return false;
				
				this->stop();
				return true;
			}
			
			bool PutChar(char myChar)
			{
				if(!this->isInitSuccess)
					return false;
				
				if(this->putChar == nullptr)
					return false;
				
				this->putChar(myChar);
				return true;
			}
			
			bool PutString(const char * string)
			{
				if(!this->isInitSuccess)
					return false;
				
				if(this->putString == nullptr)
					return false;
				
				this->putString(string);
				return true;
			}
			
			bool IsRxData()
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
			
			char GetChar()
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
			}
			
			//! @}
								
		private:
			
			// See constructor for info on following variables.
			
			void (*start)();
			void (*stop)();
			void (*putChar)(uint8_t myChar);
			void (*putString)(const char * string);
			
			//! @brief		Used with the PSoC implementation.
			uint8_t (*getRxBufferSize)();
			uint16_t (*getByte)();
		
	}; // class PsocHalUart

} // namespace MHalNs


#endif // #ifndef MHAL_PSOC_HAL_UART_H
    
// EOF
