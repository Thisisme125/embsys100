
1. b) For writing, the compiler produces the MOVS instruction

   c) The instructions used without bit banding is LDR and ORR.W
   
2. a) Normally, with less than 4 arguments, the calling function will passs the values by using the MOVS instruction. With 5 arguments, the STR instruction is used. In my code, a number is stored in register R0, then STR is used to store the value of R0 to the location of the SP register, which is the stack pointer. So the extra number is stored in the stack, which is RAM memory, and will be accessed later when needed.

   b) The extra code that was generated was the STR instruction mentioned in a.
   
   c) The extra code that was generated was the LDR instruction. Which takes the value that was stored in the SP register and store it to R5.
   
   d) The PUSH/POP instruction includes 2 registers now, R4 and R5, instead of just R4. An extra memory location is used in the stack.
   
 3. 
