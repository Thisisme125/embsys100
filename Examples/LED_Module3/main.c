//#define RCC_AHB1ENR (*((unsigned int*)0x40023830))
#define GPIOA_MODER (*((unsigned int*)0x40020000))
#define GPIOA_ODR (*((unsigned int*)0x40020014))

//also you can do macros to change macros
#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))


volatile long long counter = 0;

int main()
{
 
//  int* p = &counter;
//  (*p)++;
//  (*p)++;
//  (*p)++;
//  (*p)++;
//  (*p)++;
//  (*p)++;
//  (*p)++;
//  (*p)++;
//  (*p)++;
//  (*p)++;
  
//  p = (int*)0x20000002;
//  (*p) = 0xDEADBEEF;
  
  // 1. Enable clock to peripheral
//  *((unsigned int*)0x40023830) = 0x1;
    RCC_AHB1ENR = 0x1;
//  // 2. Set GPIOA5 to Output
//  *((unsigned int*)0x40020000) = 0xA8000400;
    GPIOA_MODER = 0xA8000400;
//  // 3. Write 1 or 0 to turn ON/OFF LED
//  *((unsigned int*)0x40020014) = 0xA8000020;
//  *((unsigned int*)0x40020014) = 0xA8000000;
    while(1)
    {
      counter = 0;
      while (counter < 800000)
      {
        counter++;
      }
        
    
    GPIOA_ODR = 0xA8000020;
     counter = 0;
     while (counter < 800000)
     {
       counter ++;
     }
    GPIOA_ODR = 0xA8000000;
    counter  = 0;
    }
  return 0;
}

//RCC base address: 0x40023800
//RCC AHB1 clock enable offset: 0x30
//Write 0x1 

//GPIO MODER
//Address offset: 0x00
//Write : 0x400

// GPIO port output data register (GPIOx_ODR)
// address offset = 0x14
// offset from base address, GPIOA 0x4002 0000
//Write : 0x20

