1) a) -2147483648 in default view, 0x80000000 in hex view.

   b) 0x80000000
   
   c) Flags N and V are set to 1. The N flag is set because the arithmetic resulted in a negative number. For signed 32 bit, positive numbers range from 0x00000000 to 0x7FFFFFFF, and negative numbers range from 0x80000000 to 0xFFFFFFFF. Since we incremented 0x7FFFFFFF by 1, it resulted to 0x80000000 which is now in the negative range of the signed integer. Therefore, the N flag got set as it is a negative number. The overflow flag V is set if the sum of two positive integers results in a negative, or the sum of two negative integers results in a positive. In this case, two positive numbers were added and it resulted to a negative number, so the overflow flag is set to catch this error.

2) a) Value goes to 0.

   b) Flags N and V are not set. The result is no longer negative, so the N flag is not set. The overflow flag V is not applicable to this arithmetic, as it will only set if there is an error adding two positive or two negative numbers. Since we are adding a negative and a positive number, the overflow flag will not be triggered. 

Flags Z and C are set to 1. The Z flag is set because the arithmetic resulted in zero. 0xFFFFFFFF in signed hex is -1. Adding 1 to that will result in 0 and setting the Z flag to 1. The ALU doesn't care if we are using unsigned or signed numbers, since they instruction is the same. So when we added 1 to 0xFFFFFFFF, it resulted to 0x00000000 and it generated an arithmatic carry therefore setting the carry bit. However, since we are working with a signed integer, we do not care about the carry bit.
   
3) a) 2147483648 in default view, 0x80000000 in hex view.

   b) The flags N and V are set again. The reasons are the same as the answer in (1c). The ALU does not know signed and unsigned, and it is using the same instruction for both. The ALU will set the approriate flags when the binary addition is done. Despite both flags being set, since we know this is an unsigned integer, we should ignore these flags. In unsigned arithmetic, we do not care about the negative flag or the overflow flag.
   
4) a) The value goes to 0.

   b) Flags N and V are not set. The result is 0 and not negative so the N flag is not set. For the N flag to be set, the value has to be in the range of 0x80000000 to 0xFFFFFFFF. The overflow flag V is not applicable to this arithmitec, as it will only set if there is an error adding two positive or two negative numbers. THe ALU will see this as adding a negative and a positive number, so the overflow flag will not be triggered. 
   
   Flags Z and C are set to 1. Because adding 1 to 0xFFFFFFFF will cause a carry out of the most significant bit. We would need 33 bits in order for the carry bit not to turn on. The rest of the bits will go to zero, and since we do not have a 33rd bit, the register will not see the 1. Adding 1 to 0xFFFFFFFF will make the result go to 0X00000000, thus turning on the Z flag. Since this is unsigned arithmatic, the carry bit means that there is an error indicating that am arithmetic carry has been generated.
   
5) a) Global.

   b) No, it is not visible in the local view.
   
   c) Static View.
   
   d) 0x20000000, this is the first address in the SRAM.
   
6) a) The value of counter at the end of the program is 4.

   b) Counter is stored globally, by default at memory 0x20000000, as seen on problem (5d). The initialized int pointer (*p_int) is pointing to the address of variable counter. When we increment the pointer using ++(*p_int) we are incrementing the data stored in the address of 0x20000000, which is the location for the variable counter. So using ++(*p_int) produces the same result as using counter++. Since we incremented the value the pointer 3 times, and counter 1 time, the value of counter changes from 0 to 4.
   
7) a) Counter is stored in 0x20000000.

   b) The counter variable is stored in the SRAM, which is a type of RAM.
  
   c) The value of counter at the end of the program is 4.
