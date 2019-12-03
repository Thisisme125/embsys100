1) a. The C stack will set aside memeory locations for the variables that are used in the function. The main function will then fill in   the values of the variables, starting from the top of the stack. It will decrement by 4 for each variable. In this case, I have 2 int variables and 2 int pointers, so the C stack will have 4 memory locations starting from the top of the stack, and decrement it by 4, 4 times. The main function will then put in the values I set for those variables into the memory addresses.

   b. R0 is the value of the first argurment in my function, which is the address of my XPtr, and R1 is the value of the second argument, the address of my yPtr.
   
   c.
   ![Locals View](https://github.com/Thisisme125/embsys100/blob/feature/assignment05/images/a3.PNG)
   
2) 


3)
