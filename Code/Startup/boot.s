/******************************************************************************************
  Filename    : boot.s
  
  Core        : QingKe V4 (RISC-V)
  
  MCU         : CH32V307VCT6 (WCH)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 20.01.2023
  
  Description : boot routine 

******************************************************************************************/

.file "boot.s"

/*******************************************************************************************
  \brief  
  
  \param  
  
  \return 
********************************************************************************************/
.section .text
.type _start, @function
.align 4
.extern __STACK_TOP
.extern Startup_Init
.globl _start

_start:
        /* disable all interrupts flag */
        csrw mstatus, x0

        /* disable all specific interrupt sources */
        csrw mie, x0

        /* setup the stack pointer */
        la sp, __STACK_TOP


        j Startup_Init

.size _start, .-_start
