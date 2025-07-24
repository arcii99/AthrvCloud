//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

/* This program takes two integer values from the user and performs the following bitwise operations:
   - Bitwise AND
   - Bitwise OR
   - Bitwise XOR
   - Bitwise NOT
   - Bitwise left shift
   - Bitwise right shift */

int main()
{
    int num1, num2;

    //reading the two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // performing bitwise AND
    printf("Bitwise AND: %d & %d = %d\n", num1, num2, num1 & num2);
    
    // performing bitwise OR
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, num1 | num2);
    
    // performing bitwise XOR
    printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, num1 ^ num2);

    // performing bitwise NOT
    printf("Bitwise NOT of %d: ~%d = %d\n", num1, num1, ~num1);
    printf("Bitwise NOT of %d: ~%d = %d\n", num2, num2, ~num2);
    
    // performing bitwise left shift
    printf("Bitwise left shift of %d by 2: %d << 2 = %d\n", num1, num1, num1<<2);
    printf("Bitwise left shift of %d by 3: %d << 3 = %d\n", num2, num2, num2<<3);
    
    // performing bitwise right shift
    printf("Bitwise right shift of %d by 2: %d >> 2 = %d\n", num1, num1, num1>>2);
    printf("Bitwise right shift of %d by 3: %d >> 3 = %d\n", num2, num2, num2>>3);

    return 0;
}