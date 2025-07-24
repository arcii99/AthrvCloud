//FormAI DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char binary[40];
    int decimal = 0, i, power = 1;

    printf("Enter binary number: ");
    fgets(binary, 40, stdin);
    binary[strcspn(binary, "\n")] = '\0'; // removes trailing newline character

    for (i = strlen(binary) - 1; i >= 0; i--) // loop through the binary string from right to left
    {
        if (binary[i] == '1') // if the current bit is 1
        {
            decimal += power; // add the value of the current power of 2 to the decimal value
        }
        power *= 2; // multiply the power by 2 for the next iteration
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}