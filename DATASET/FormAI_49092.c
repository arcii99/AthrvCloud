//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {

    // Let's use some bitwise magic to manipulate some bits!

    unsigned int firstNumber = 10;
    unsigned int secondNumber = 5;
    unsigned int result;

    printf("First number: %d\n", firstNumber);
    printf("Second number: %d\n", secondNumber);

    // Bitwise AND operator
    result = firstNumber & secondNumber;
    printf("Bitwise AND: %d & %d = %d\n", firstNumber, secondNumber, result);

    // Bitwise OR operator
    result = firstNumber | secondNumber;
    printf("Bitwise OR: %d | %d = %d\n", firstNumber, secondNumber, result);

    // Bitwise XOR operator
    result = firstNumber ^ secondNumber;
    printf("Bitwise XOR: %d ^ %d = %d\n", firstNumber, secondNumber, result);

    // Bitwise Complement operator
    result = ~firstNumber;
    printf("Bitwise Complement of %d = %d\n", firstNumber, result);

    // Left Shift operator
    result = firstNumber << 1;
    printf("Left Shift of %d by 1 = %d\n", firstNumber, result);

    // Right Shift operator
    result = firstNumber >> 1;
    printf("Right Shift of %d by 1 = %d\n", firstNumber, result);

    return 0;
}