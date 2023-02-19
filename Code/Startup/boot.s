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
  \brief  entry point
  
  \param  void
  
  \return void
********************************************************************************************/
.section .text
.type _start, @function
.align 4
.extern __STACK_TOP
.extern Startup_Init
.globl _start

_start:
        /* setup the stack pointer */
        la sp, __STACK_TOP

        /* enable both the global interrupt flag and the FPU 
        li x1, 0x2008
        csrw mstatus, x1*/

        /* jump to the C runtime initialization */
        j Startup_Init

.size _start, .-_start
