#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

//Bit-Band Definitions
#define BASE_BitBand_Address 0x42000000
#define RCC_byte_offset 0x23830
#define enable_clock_bit 0
#define GPIOA_byte_offset 0x20000
#define ENABLE_PORT5_bit10 10
#define ENABLE_PORT5_bit11 11
volatile int counter=0;

void main(void)
{
    
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
   // RCC_AHB1ENR |= 0x1;
  
    //use formula: Bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number x 4)
    *((unsigned int*)((BASE_BitBand_Address) + (RCC_byte_offset * 32) + (enable_clock_bit*4))) = 0x1;
    
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    //GPIOA_MODER |= 0x400;

    //set bit 10 to 1
    *((unsigned int*)((BASE_BitBand_Address) + (GPIOA_byte_offset * 32) + (ENABLE_PORT5_bit10*4))) = 0x1;
    
    //set bit 11 to  0
    *((unsigned int*)((BASE_BitBand_Address) + (GPIOA_byte_offset * 32) + (ENABLE_PORT5_bit11*4))) = 0x0;
    
    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    
    while(1)
    {
    counter=0;

    while (counter < 1000000)
    {
      counter++;
    }
  //GPIOA_ODR |= GPIOA;
    
    //Turn on LED by writing 1 to bit 5
    *((unsigned int*)((BASE_BitBand_Address) + (0x20014 * 32) + (5*4))) = 0x1;
       
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
  //GPIOA_ODR &= ~GPIOA;
    
    //Turn off LED by writing 0 to bit 5
    *((unsigned int*)((BASE_BitBand_Address) + (0x20014 * 32) + (5*4))) = 0x0;

    }
}
