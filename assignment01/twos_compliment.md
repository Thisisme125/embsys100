Why use two's complement to represent negative numbers?

The reason we use two's complement to represent negative numbers is because we can use the same circuit to perform the addition or subtraction. This translates to only needing one set of instructions in order to perform signed and unsigned arithmetic.

When using different representations and performing addition or subtraction, we would need to apply different logic circuits to perform the arithmetic. By representing positive numbers as they are, and negative numbers in their 2's complement, we can use the same circuit/instruction to perform the arithmetic.

For example, if we add 1001 to 0011, we would get 1100, whether it was -7 + 3, or 9 + 3. The same addition instruction can get the answer for both addition or subtraction.

If we used sign-bit representation, it would be -7 + 3, but we would need another instruction/circuit to add them together to get the right answer.

If we used 1's complement, only one instruction is needed, but we have an issue with representing zero. All 0's is positive zero, and all 1's is negative 0.
