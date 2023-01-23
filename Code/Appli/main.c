
#include "SysTick.h"


int main(void)
{
  SysTick_Init();
  SysTick_Start(SYSTICK_TIMEOUT_SEC(1));

  for(;;);
}