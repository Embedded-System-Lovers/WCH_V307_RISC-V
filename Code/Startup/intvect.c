/******************************************************************************************************
  Filename    : intvect.c
  
  Core        : QingKe V4 (RISC-V)
  
  MCU         : CH32V307VCT6 (WCH)
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 20.01.2023
  
  Description : Interrupt vector table implementation
  
******************************************************************************************************/

//=====================================================================================================
// Includes
//=====================================================================================================
#include "Platform_Types.h"

//=====================================================================================================
// Functions prototype
//=====================================================================================================
static void UndefinedHandler(void);

void Isr_InstructionAddressMisaligned (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_InstructionAccessFault       (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_IllegalInstruction           (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_Breakpoint                   (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_LoadAddressMisaligned        (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_LoadAccessFault              (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_StoreAddressMisaligned       (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_StoreAccessFault             (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_EnvironmentCallFromUmode     (void) __attribute__((weak, alias("UndefinedHandler")));
void Isr_EnvironmentCallFromMmode     (void) __attribute__((weak, alias("UndefinedHandler")));
void NMI_IRQ                          (void) __attribute__((weak, alias("UndefinedHandler")));
void SysTick_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void SoftwareInt_IRQn                 (void) __attribute__((weak, alias("UndefinedHandler")));
void WWDG_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void PVD_IRQn                         (void) __attribute__((weak, alias("UndefinedHandler")));
void TAMPER_IRQn                      (void) __attribute__((weak, alias("UndefinedHandler")));
void RTC_IRQn                         (void) __attribute__((weak, alias("UndefinedHandler")));
void FLASH_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void RCC_IRQn                         (void) __attribute__((weak, alias("UndefinedHandler")));
void EXTI0_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void EXTI1_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void EXTI2_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void EXTI3_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void EXTI4_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA1_Channel1_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA1_Channel2_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA1_Channel3_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA1_Channel4_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA1_Channel5_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA1_Channel6_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA1_Channel7_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void ADC_IRQn                         (void) __attribute__((weak, alias("UndefinedHandler")));
void USB_HP_CAN1_TX_IRQn              (void) __attribute__((weak, alias("UndefinedHandler")));
void USB_LP_CAN1_RX0_IRQn             (void) __attribute__((weak, alias("UndefinedHandler")));
void CAN1_RX1_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void CAN1_SCE_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void EXTI9_5_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM1_BRK_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM1_UP__IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM1_TRG_COM_IRQn                (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM1_CC_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM2_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM3_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM4_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void I2C1_EV_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void I2C1_ER_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void I2C2_EV_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void I2C2_ER_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void SPI1_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void SPI2_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void USART1_IRQn                      (void) __attribute__((weak, alias("UndefinedHandler")));
void USART2_IRQn                      (void) __attribute__((weak, alias("UndefinedHandler")));
void USART3_IRQn                      (void) __attribute__((weak, alias("UndefinedHandler")));
void EXTI15_10_IRQn                   (void) __attribute__((weak, alias("UndefinedHandler")));
void RTCAlarm_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void USBWakeUp_IRQn                   (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM8_BRK_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM8_UP__IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM8_TRG_COM_IRQn                (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM8_CC_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void RNG_IRQn                         (void) __attribute__((weak, alias("UndefinedHandler")));
void FSMC_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void SDIO_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM5_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void SPI3_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void UART4_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void UART5_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM6_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM7_IRQn                        (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel1_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel2_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel3_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel4_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel5_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void ETH_IRQn                         (void) __attribute__((weak, alias("UndefinedHandler")));
void ETH_WKUP_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void CAN2_TX_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void CAN2_RX0_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void CAN2_RX1_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void CAN2_SCE_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void OTG_FS_IRQn                      (void) __attribute__((weak, alias("UndefinedHandler")));
void USBHSWakeup_IRQn                 (void) __attribute__((weak, alias("UndefinedHandler")));
void USBHS_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void DVP_IRQn                         (void) __attribute__((weak, alias("UndefinedHandler")));
void UART6_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void UART7_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void UART8_IRQn                       (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM9_BRK_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM9_UP__IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM9_TRG_COM_IRQn                (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM9_CC_IRQn                     (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM10_BRK_IRQn                   (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM10_UP__IRQn                   (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM10_TRG_COM_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void TIM10_CC_IRQn                    (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel6_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel7_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel8_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel9_IRQn               (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel10_IRQn              (void) __attribute__((weak, alias("UndefinedHandler")));
void DMA2_Channel11_IRQn              (void) __attribute__((weak, alias("UndefinedHandler")));

//=====================================================================================================
// Interrupt vector table
//=====================================================================================================
const InterruptHandler __attribute__((aligned(4))) IVT[] =
{
    (InterruptHandler)&UndefinedHandler,       /*!<   0  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<   1  Reserved                                                         */
    (InterruptHandler)&NMI_IRQ,                /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
    (InterruptHandler)&UndefinedHandler,       /*!<   3  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<   4  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<   5  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<   6  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<   7  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<   8  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<   9  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<  10  Reserved                                                         */
    (InterruptHandler)&UndefinedHandler,       /*!<  11  Reserved                                                         */
    (InterruptHandler)&SysTick_IRQn,           /*!<  12  System Tick Timer                                                */
    (InterruptHandler)&UndefinedHandler,       /*!<  15  Reserved                                                         */
    (InterruptHandler)&SoftwareInt_IRQn,       /*!<  14  System Tick Timer                                                */
    (InterruptHandler)&UndefinedHandler,       /*!<  15  Reserved                                                         */
    (InterruptHandler)&WWDG_IRQn,              /*!<  16  Window Watchdog interrupt                                        */
    (InterruptHandler)&PVD_IRQn,               /*!<  17  PVD through EXTI line detection interrupt                        */
    (InterruptHandler)&TAMPER_IRQn,            /*!<  18  Tamper interrupt                                                 */
    (InterruptHandler)&RTC_IRQn,               /*!<  19  RTC global interrupt                                             */
    (InterruptHandler)&FLASH_IRQn,             /*!<  20  Flash global interrupt                                           */
    (InterruptHandler)&RCC_IRQn,               /*!<  21  RCC global interrupt                                             */
    (InterruptHandler)&EXTI0_IRQn,             /*!<  22  EXTI Line0 interrupt                                             */
    (InterruptHandler)&EXTI1_IRQn,             /*!<  23  EXTI Line1 interrupt                                             */
    (InterruptHandler)&EXTI2_IRQn,             /*!<  24  EXTI Line2 interrupt                                             */
    (InterruptHandler)&EXTI3_IRQn,             /*!<  25  EXTI Line3 interrupt                                             */
    (InterruptHandler)&EXTI4_IRQn,             /*!<  26  EXTI Line4 interrupt                                             */
    (InterruptHandler)&DMA1_Channel1_IRQn,     /*!<  27  DMA1 Channel1 global interrupt                                   */
    (InterruptHandler)&DMA1_Channel2_IRQn,     /*!<  28  DMA1 Channel2 global interrupt                                   */
    (InterruptHandler)&DMA1_Channel3_IRQn,     /*!<  29  DMA1 Channel3 global interrupt                                   */
    (InterruptHandler)&DMA1_Channel4_IRQn,     /*!<  30  DMA1 Channel4 global interrupt                                   */
    (InterruptHandler)&DMA1_Channel5_IRQn,     /*!<  31  DMA1 Channel5 global interrupt                                   */
    (InterruptHandler)&DMA1_Channel6_IRQn,     /*!<  32  DMA1 Channel6 global interrupt                                   */
    (InterruptHandler)&DMA1_Channel7_IRQn,     /*!<  33  DMA1 Channel7 global interrupt                                   */
    (InterruptHandler)&ADC_IRQn,               /*!<  34  ADC global interrupt                                             */
    (InterruptHandler)&USB_HP_CAN1_TX_IRQn,    /*!<  35  CAN1 TX interrupts                                               */
    (InterruptHandler)&USB_LP_CAN1_RX0_IRQn,   /*!<  36  CAN1 RX0 interrupts                                              */
    (InterruptHandler)&CAN1_RX1_IRQn,          /*!<  37  CAN1 RX1 interrupt                                               */
    (InterruptHandler)&CAN1_SCE_IRQn,          /*!<  38  CAN1 SCE interrupt                                               */
    (InterruptHandler)&EXTI9_5_IRQn,           /*!<  39  EXTI Line[9:5] interrupts                                        */
    (InterruptHandler)&TIM1_BRK_IRQn,          /*!<  40  TIM1 Break interrupt                                             */
    (InterruptHandler)&TIM1_UP__IRQn,          /*!<  41  TIM1 Update interrupt                                            */
    (InterruptHandler)&TIM1_TRG_COM_IRQn,      /*!<  42  TIM1 Trigger and Commutation interrupts                          */
    (InterruptHandler)&TIM1_CC_IRQn,           /*!<  43  TIM1 Capture Compare interrupt                                   */
    (InterruptHandler)&TIM2_IRQn,              /*!<  44  TIM2 global interrupt                                            */
    (InterruptHandler)&TIM3_IRQn,              /*!<  45  TIM3 global interrupt                                            */
    (InterruptHandler)&TIM4_IRQn,              /*!<  46  TIM4 global interrupt                                            */
    (InterruptHandler)&I2C1_EV_IRQn,           /*!<  47  I2C1 event interrupt                                             */
    (InterruptHandler)&I2C1_ER_IRQn,           /*!<  48  I2C1 error interrupt                                             */
    (InterruptHandler)&I2C2_EV_IRQn,           /*!<  49  I2C2 event interrupt                                             */
    (InterruptHandler)&I2C2_ER_IRQn,           /*!<  50  I2C2 error interrupt                                             */
    (InterruptHandler)&SPI1_IRQn,              /*!<  51  SPI1 global interrupt                                            */
    (InterruptHandler)&SPI2_IRQn,              /*!<  52  SPI2 global interrupt                                            */
    (InterruptHandler)&USART1_IRQn,            /*!<  53  USART1 global interrupt                                          */
    (InterruptHandler)&USART2_IRQn,            /*!<  54  USART2 global interrupt                                          */
    (InterruptHandler)&USART3_IRQn,            /*!<  55  USART3 global interrupt                                          */
    (InterruptHandler)&EXTI15_10_IRQn,         /*!<  56  EXTI Line[15:10] interrupts                                      */
    (InterruptHandler)&RTCAlarm_IRQn,          /*!<  57  RTC Alarms through EXTI line interrupt                           */
    (InterruptHandler)&USBWakeUp_IRQn,         /*!<  58  USB Device WakeUp from suspend through EXTI Line Interrupt       */
    (InterruptHandler)&TIM8_BRK_IRQn,          /*!<  59  TIM8 Break interrupt                                             */
    (InterruptHandler)&TIM8_UP__IRQn,          /*!<  60  TIM8 Update interrupt                                            */
    (InterruptHandler)&TIM8_TRG_COM_IRQn,      /*!<  61  TIM8 Trigger and Commutation interrupts                          */
    (InterruptHandler)&TIM8_CC_IRQn,           /*!<  62  TIM8 Capture Compare interrupt                                   */
    (InterruptHandler)&RNG_IRQn,               /*!<  63  RNG interrupt                                                    */
    (InterruptHandler)&FSMC_IRQn,              /*!<  64  FSMC global interrupt                                            */
    (InterruptHandler)&SDIO_IRQn,              /*!<  65  SDIO global interrupt                                            */
    (InterruptHandler)&TIM5_IRQn,              /*!<  66  TIM5 global interrupt                                            */
    (InterruptHandler)&SPI3_IRQn,              /*!<  67  SPI3 global interrupt                                            */
    (InterruptHandler)&UART4_IRQn,             /*!<  68  UART4 global interrupt                                           */
    (InterruptHandler)&UART5_IRQn,             /*!<  69  UART5 global interrupt                                           */
    (InterruptHandler)&TIM6_IRQn,              /*!<  70  TIM6 Basic interrupt                                             */
    (InterruptHandler)&TIM7_IRQn,              /*!<  71  TIM8 Basic interrupt                                             */
    (InterruptHandler)&DMA2_Channel1_IRQn,     /*!<  72  DMA2 Channel1 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel2_IRQn,     /*!<  73  DMA2 Channel2 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel3_IRQn,     /*!<  74  DMA2 Channel3 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel4_IRQn,     /*!<  75  DMA2 Channel4 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel5_IRQn,     /*!<  76  DMA2 Channel5 global interrupt                                   */
    (InterruptHandler)&ETH_IRQn,               /*!<  77  Ethernet global interrupt                                        */
    (InterruptHandler)&ETH_WKUP_IRQn,          /*!<  78  Ethernet Wakeup through EXTI line interrupt                      */
    (InterruptHandler)&CAN2_TX_IRQn,           /*!<  79  CAN2 TX interrupts                                               */
    (InterruptHandler)&CAN2_RX0_IRQn,          /*!<  80  CAN2 RX0 interrupts                                              */
    (InterruptHandler)&CAN2_RX1_IRQn,          /*!<  81  CAN2 RX1 interrupt                                               */
    (InterruptHandler)&CAN2_SCE_IRQn,          /*!<  82  CAN2 SCE interrupt                                               */
    (InterruptHandler)&OTG_FS_IRQn,            /*!<  83  OTG_FS                                                           */
    (InterruptHandler)&USBHSWakeup_IRQn,       /*!<  84  USBHSWakeup                                                      */
    (InterruptHandler)&USBHS_IRQn,             /*!<  85  USBHS                                                            */
    (InterruptHandler)&DVP_IRQn,               /*!<  86  DVP global Interrupt interrupt                                   */
    (InterruptHandler)&UART6_IRQn,             /*!<  87  UART6 global interrupt                                           */
    (InterruptHandler)&UART7_IRQn,             /*!<  88  UART7 global interrupt                                           */
    (InterruptHandler)&UART8_IRQn,             /*!<  89  UART8 global interrupt                                           */
    (InterruptHandler)&TIM9_BRK_IRQn,          /*!<  90  TIM9 Break interrupt                                             */
    (InterruptHandler)&TIM9_UP__IRQn,          /*!<  91  TIM9 Update interrupt                                            */
    (InterruptHandler)&TIM9_TRG_COM_IRQn,      /*!<  92  TIM9 Trigger and Commutation interrupts                          */
    (InterruptHandler)&TIM9_CC_IRQn,           /*!<  93  TIM9 Capture Compare interrupt                                   */
    (InterruptHandler)&TIM10_BRK_IRQn,         /*!<  94  TIM10 Break interrupt                                            */
    (InterruptHandler)&TIM10_UP__IRQn,         /*!<  95  TIM10 Update interrupt                                           */
    (InterruptHandler)&TIM10_TRG_COM_IRQn,     /*!<  96  TIM10 Trigger and Commutation interrupts                         */
    (InterruptHandler)&TIM10_CC_IRQn,          /*!<  97  TIM10 Capture Compare interrupt                                  */
    (InterruptHandler)&DMA2_Channel6_IRQn,     /*!<  98  DMA2 Channel6 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel7_IRQn,     /*!<  99  DMA2 Channel7 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel8_IRQn,     /*!< 100  DMA2 Channel8 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel9_IRQn,     /*!< 101  DMA2 Channel9 global interrupt                                   */
    (InterruptHandler)&DMA2_Channel10_IRQn,    /*!< 102  DMA2 Channel10 global interrupt                                  */
    (InterruptHandler)&DMA2_Channel11_IRQn     /*!< 103  DMA2 Channel11 global interrupt                                  */
};

//=====================================================================================================
// Exception vector table
//=====================================================================================================
const InterruptHandler __attribute__((aligned(4))) EVT[] =
{
    (InterruptHandler)&Isr_InstructionAddressMisaligned,  /* 0  - Instruction address misaligned */
    (InterruptHandler)&Isr_InstructionAccessFault,        /* 1  - Instruction access fault       */
    (InterruptHandler)&Isr_IllegalInstruction,            /* 2  - Illegal instruction            */
    (InterruptHandler)&Isr_Breakpoint,                    /* 3  - Breakpoint                     */
    (InterruptHandler)&Isr_LoadAddressMisaligned,         /* 4  - Load address misaligned        */
    (InterruptHandler)&Isr_LoadAccessFault,               /* 5  - Load access fault              */
    (InterruptHandler)&Isr_StoreAddressMisaligned,        /* 6  - Store/AMO address misaligned   */
    (InterruptHandler)&Isr_StoreAccessFault,              /* 7  - Store/AMO access fault         */
    (InterruptHandler)&Isr_EnvironmentCallFromUmode,      /* 8  - Environment call from U-mode   */
    (InterruptHandler)&UndefinedHandler,                  /* 9  - Reserved                       */
    (InterruptHandler)&UndefinedHandler,                  /* 10 - Reserved                       */
    (InterruptHandler)&Isr_EnvironmentCallFromMmode,      /* 11 - Environment call from M-mode   */
};

//=====================================================================================================
// Implementation
//=====================================================================================================

//-----------------------------------------------------------------------------------------
/// \brief  
///
/// \param  
///
/// \return 
//-----------------------------------------------------------------------------------------
static void UndefinedHandler(void)
{
  for(;;);
}
