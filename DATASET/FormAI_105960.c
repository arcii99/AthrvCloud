//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    char hex_num[MAX_SIZE];
    int decimal_num = 0, base = 1, i = 0, j = 0;

    printf("Enter a hexadecimal number: ");
    fgets(hex_num, MAX_SIZE, stdin);

    // Remove newline character from input
    while (hex_num[j] != '\n') {
        j++;
    }
    hex_num[j] = '\0';

    // Convert hexadecimal to decimal
    for (i = 0; hex_num[i] != '\0'; i++) {
        if (hex_num[i] >= '0' && hex_num[i] <= '9') {
            decimal_num += (hex_num[i] - '0') * base;
            base *= 16;
        }
        else if (hex_num[i] >= 'a' && hex_num[i] <= 'f') {
            decimal_num += (hex_num[i] - 'a' + 10) * base;
            base *= 16;
        }
        else if (hex_num[i] >= 'A' && hex_num[i] <= 'F') {
            decimal_num += (hex_num[i] - 'A' + 10) * base;
            base *= 16;
        }
        else {
            printf("Invalid input!\n");
            exit(0);
        }
    }

    // Print decimal equivalent
    printf("The decimal equivalent of %s is %d\n", hex_num, decimal_num);

    return 0;
}