
#include "Platform_Types.h"
#include "CH32V30xxx.h" 


int dummy_cpptest(void);

float val=33.14;
volatile int t = 1;


int main(void)
{
  t = dummy_cpptest();
  val = ((float)t/2 + 11.12) * 2;

  for(;;);
}