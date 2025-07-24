//FormAI DATASET v1.0 Category: Bitwise operations ; Style: brave
#include<stdio.h>

// Declare a Global Variable
int globalVariable = 30;

int main()
{
    printf("Brave C Bitwise Operations Example:\n\n");

    // Create local variables
    int firstNumber = 25;
    int secondNumber = 15;
    int thirdNumber = -10;

    // Bitwise AND operation
    printf("The result of %d AND %d is: %d\n", firstNumber, secondNumber, firstNumber & secondNumber);

    // Bitwise OR operation
    printf("The result of %d OR %d is: %d\n", firstNumber, secondNumber, firstNumber | secondNumber);

    // Bitwise XOR operation
    printf("The result of %d XOR %d is: %d\n", firstNumber, secondNumber, firstNumber ^ secondNumber);

    // Left shift operator
    printf("The result of left shifting %d by 2 bits is: %d\n", firstNumber, firstNumber << 2);

    // Right shift operator
    printf("The result of right shifting %d by 2 bits is: %d\n", firstNumber, firstNumber >> 2);

    // Bitwise NOT operator
    printf("The result of bitwise NOT on %d is: %d\n", thirdNumber, ~thirdNumber);

    // Assigning a value to the Global variable
    printf("\nAssigning a value to the global variable...\n");
    globalVariable = globalVariable + 10;
    printf("The value of the global variable is now: %d\n", globalVariable);

    return 0;
}