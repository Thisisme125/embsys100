/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping Chars
*******************************************************************************/   
    
    PUBLIC swapCharsAsm      // Exports symbols to other modules
                             // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Takes in two Char addresses, and swaps their values
C Prototype     : void swapCharsAsm(Char* xPtr, Char* yPtr);
                : Where x and y are char addresses
Parameters      : R0, R1: Char Address
Return value    : None
*******************************************************************************/  
  
swap2Asm
    MOVB R2, [R0]        // Dereference the address in R0, and copy contents to R2
    MOVB R0, [R1]        // Deference the address of R1, and copy value into R0
    MOVB R1, R2          // Copy Contents of R2 into R1
END

/* OR

swap2Asm
    MOVB R0, [R0]        // Dereference address stored in R0 and copy value to R0
    MOVB R2, R0          // Copy value of R0 into R2
    MOVB R1, [R1]        // Dereference address stored in R1 and copy value to R1
    MOVB R0, R1          // Copy of R1 value to R0
    MOVB R1, R2          // Copy contents of R2 into R1
END

*/
