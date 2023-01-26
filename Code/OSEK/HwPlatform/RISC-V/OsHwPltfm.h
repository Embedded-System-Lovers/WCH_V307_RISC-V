// *****************************************************************************
// Filename    : OsHwPltfm.h
// 
// Author      : Chalandi Amine
//
// Owner       : Chalandi Amine
// 
// Date        : 18.01.2023
// 
// Description : Hardware platform header file for SiFive RISC-V FE310 SoC
// 
// *****************************************************************************

#ifndef __HARDWARE_PLATFORM_H__
#define __HARDWARE_PLATFORM_H__

//=========================================================================================
// Includes
//=========================================================================================
#include"Platform_Types.h"
#include"OsAsm.h"

#define OS_GEN_NOT
#include"OsGenCfg.h"
#undef  OS_GEN_NOT

#include "CH32V30xxx.h"
#include "riscv-csr.h"

//=========================================================================================
// Definitions
//=========================================================================================
#define osDispatch()              *(volatile uint32*)(0xE000F000ul) |= 0x80000000; __asm("FENCE.I")

#define ENABLE_INTERRUPTS()       csr_set_bits_mstatus(MSTATUS_MIE_BIT_MASK)
#define DISABLE_INTERRUPTS()      csr_clr_bits_mstatus(MSTATUS_MIE_BIT_MASK)

#define OsSetINTSYSCR(value)      __asm__ volatile ("csrw    0x804, %0" : : "r" (value) :);


//=========================================================================================
// SYSTICK
//=========================================================================================
#include "SysTick.h"

//=========================================================================================
// Functions Prototype
//=========================================================================================
uint32 osGetPMR(void);
void osSetPMR(uint32 level);
void osHwTimerInit(void);
void osHwTimerStart(void);
void osHwTimerReload(void);
void osRestoreSavedIntState(void);
void osSaveAndDisableIntState(void);
void OsRunSysTickIsr(void);
void OsCatchAllCpuExceptions(void);
void OsIsr_SysTickTimerFunc(void);

#endif
