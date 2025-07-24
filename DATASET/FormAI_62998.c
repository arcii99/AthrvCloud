//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

void binary_print(unsigned int num) {
    // Helper function to print binary representation of a number
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) {
            // Insert space every 4 bits for readability
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Bit Party!\n");

    // Let's start with some fun bitwise operations
    unsigned int num1 = 0b11001100;
    unsigned int num2 = 0b00110011;

    printf("\nFirst, let's initialize two unsigned integers:\n");
    printf("num1 = ");
    binary_print(num1);
    printf("num2 = ");
    binary_print(num2);

    printf("\nNow let's do some bitwise operations!\n");
    printf("1. Bitwise AND operator &: ");
    binary_print(num1 & num2);

    printf("2. Bitwise OR operator |: ");
    binary_print(num1 | num2);

    printf("3. Bitwise XOR operator ^: ");
    binary_print(num1 ^ num2);

    printf("4. Bitwise NOT operator ~ on num1: ");
    binary_print(~num1);

    printf("\nLet's have some fun with shifting bits!\n");
    unsigned int num3 = 0b00111100;

    printf("\nInitialized a new unsigned integer:\n");
    printf("num3 = ");
    binary_print(num3);

    printf("5. Left shift operator << by 2: ");
    binary_print(num3 << 2);

    printf("6. Right shift operator >> by 3: ");
    binary_print(num3 >> 3);

    printf("\nThanks for joining the Bit Party! Happy coding!\n");

    return 0;
}