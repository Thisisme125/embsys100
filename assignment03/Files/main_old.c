//Define Macros
    
    //Define RCC base and offset for AHB1 Bus page
    #define RCC_AHB1 0x40023800  //base
    #define RCC_AHB1ENR  (*((unsigned int*)(RCC_AHB1 + 0x30)))  //offset
    //write 0x1 to enable clock for portA

    //Define GPIOA Base and offset for LED
    #define GPIOA_BASE 0x40020000 //base
    #define GPIOA_MODER (*((unsigned int*)GPIOA_BASE))
    #define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14))) //offset
//  #define GPIOA_ODR (*((unsigned int*)0x40020014)) DOES NOT WORK
    //write 0x400 to MODER set GPIO PA5 as output
    //write 0x20 to ODR to turn on LED
    
//Function Prototypes
void LED_ON();
void LED_OFF();
void Blink_LED (int seconds);
void Space (int seconds);
void BlinkName();

//Define global array to store Name
//char Name[4][5] = {{'O','-','-','-','0'},{'M','-','-','0','0'},{'A','.','-','0','0'},{'R','.','-','.','0'}};


//Main Function
int main()
{
  
  //Enable RCC for AHB1
  RCC_AHB1ENR = 0x1;
    
  //Enable GPIOA_PA5 and set it as OUTPUT
  GPIOA_MODER |= 0x400;

  //Blink Omar in morse code
  BlinkName();
//   Blink_LED(1);
//   Space(1);
//   Blink_LED(3);
//  
  
  return 0;     
}


//Function Definitions
void LED_ON()
{
  GPIOA_ODR |= 0x20;
}

void LED_OFF()
{
  GPIOA_ODR &= 0xDF;
}

void Blink_LED (int seconds) 
{
  int counter = 0;
  
  if (seconds == 1)
  {
     while (counter < 1000000)
     {
       counter++;
     }
     LED_ON();
     
     counter = 0;
     
     while (counter < 1000000)
     {
       counter++;
     }
     LED_OFF();      
     counter = 0;
  }
  
  else if (seconds == 3)
  {
    while (counter < 1000000)
    {
      counter++;
    }
    LED_ON();
    
    counter = 0;
    
    while (counter < 3000000)
    {
      counter++;
    }
    LED_OFF();
    counter = 0;
  }
}

void Space (int seconds)
{
  int counter = 0;
  
    for (int x = 0; x < seconds; x++)
    {
      while (counter < 1000000)
      {
        counter++;
      }
      counter = 0;          
    }
}


void BlinkName()
{
  //Define name array with letter and morse code symbol
  char Name[4][5] = {{'O','-','-','-','0'},{'M','-','-','0','0'},{'A','.','-','0','0'},{'R','.','-','.','0'}};
  
  //Loop through array
  for (int i = 0; i < 4 ;i++)
  {
    for (int j = 1; j < 5; j++)
    {
      switch (Name[i][j])
      {
    case '.':
      Blink_LED(1);
      break;
      
    case '-':
      Blink_LED(3);
      break;
      
    case '0':
      j = 4;
      break; 
      
    default:
      break;
      }
      
      //Pause 1 space 
      Space(1);
    }
  }
    
  
}
