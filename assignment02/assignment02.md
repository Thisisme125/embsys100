1) a) 536870912 in default view, 0x20000000 in hex view.

   b) 0x20000000
   
   c) No flags are set. 0x20000000 is within the limits of the signed int, 2^32 bits. The addition of 1 did not cause the result to go to zero, or to change the sign bit, or to go to a value larger than 32 bit. 

2) a) Value goes to 0.

   b) Flags Z and C are set to 1. The Z flag is set because the arithmetic resulted in zero. 0xFFFFFFFF in hex is -1. Adding 1 to that will result in 0 and setting the Z flag to 1. The compiler doesn't care if we are using unsigned or signed numbers, since they instruction is the same. So when we added 1 to 0xFFFFFFFF, it resulted to 0x00000000 and setting the carry bit. However, since we are working with a signed integer, we do not care about the carry bit.
   
3) a) 536870912 in default view, 0x20000000 in hex view.

   b) No flags are set. 0x20000000 is within the limits of the signed int, 2^32 bits. The addition of 1 did not cause the result to go to zero, or to change the sign bit, or to go to a value larger than 32 bit. 
   
4) a) The value goes to 0.

   b) Flags Z and C are set to 1. Because adding 1 to 0xFFFFFFFF will cause a carry out of the most significant bit. We would need 33 bits in order for the carry bit not to turn on. The rest of the bits will go to zero, and since we do not have a 33rd bit, the register will not see the 1. Adding 1 to 0xFFFFFFFF will make the result go to 0X00000000, thus turning on the zero bit. Since this is unsigned arithmatic, the carry bit means that there is an error.
   
5) a) Global.

   b) No, it is not visible in the local view.
   
   c) Static View.
   
   d) 0x20000000, this is the first address in the SRAM.
   
6) a) The value of counter at the end of the program is 4.

   b) Counter is stored globally, by default at memory 0x20000000, as seen on problem 5d. The initialized int pointer (*p_int) is pointing to the address of counter. When we increment the pointer using ++(*p_int) we are incrementing the data stored in the address of 0x20000000, which is the location for the variable counter. So using ++(*p_int) produces the same outcome as using counter++. Since we incremented the value 4 times, the value of counter changes from 0 to 4.
   
7) a) Counter is stored in 0x20000000.

   b) The counter variable is stored in the SRAM, which is a type of RAM.
  
   c) The value of counter at the end of the program is 4.
