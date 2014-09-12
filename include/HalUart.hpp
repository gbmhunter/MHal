//!
//! @file 		    		HalUart.hpp
//! @author 	    		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created	    		2014-07-29
//! @last-modified  		2014-09-12
//! @brief
//!

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MHAL_HAL_UART_H
#define MHAL_HAL_UART_H

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//================================== HEADER INCLUSIONS ==========================================//
//===============================================================================================//

// System libraries
// none

// User libraries
// none

// User source

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
	class HalUart
	{
		
	public:
		
		//! @brief		Use to check if initialisation was successful.
		//! @returns	Returns true if initialisation successful, otherwise false.
		//! @note		Thread-safe. Re-entrant. NOT ISR safe.
		bool IsInitSuccess()
		{
			return this->isInitSuccess;	
		};
		
		// See constructor for info on following functions.
		
		//! @brief	Interface functions between HAL layer and the higher-level drivers.
		//! @note 	These functions declarations need to remain constant across different platforms!
		//! @{
		virtual bool Start() = 0;
		virtual bool Stop() = 0;
		virtual bool PutChar(char myChar) = 0;
		virtual bool PutString(const char * string) = 0;
		virtual bool IsRxData() = 0;
		virtual char GetChar() = 0;
		//! @}
			
	protected:
		
		HalUart() :
			isInitSuccess(false)
		{};
		
		//! @brief		Set by constructor when initialisation is complete.
		//! @details	The user can read this variable by calling IsInitSuccess().
		bool isInitSuccess;
								
	private:
	
		// none	
		
	}; // class HalUart

} // namespace MHalNs


#endif // #ifndef UART_DVR_HAL_UART_H
    
// EOF
