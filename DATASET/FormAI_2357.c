//FormAI DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int binary_conversion(int number)
{
    int binary = 0, power = 1, remainder;
    while(number > 0)
    {
        remainder = number % 2;
        binary += remainder * power;
        power *= 10;
        number /= 2;
    }
    return binary;
}

int main()
{
    int input, binary;
    printf("Welcome to the Binary Converter!\n");
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &input);
    binary = binary_conversion(input);
    printf("%d in binary is %d\n", input, binary);
    printf("Thank you for using the Binary Converter!\n");
    return 0;
}