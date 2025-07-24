//FormAI DATASET v1.0 Category: Binary Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int to_binary(int decimal_num)
{
    if (decimal_num == 0) {
        return 0;
    } else {
        return (decimal_num % 2) + 10 * to_binary(decimal_num / 2);
    }
}

void print_binary(int decimal_num)
{
    int binary_num = to_binary(decimal_num);
    printf("%d in binary is: %d\n", decimal_num, binary_num);
}

int main()
{
    char input[MAX_LENGTH];
    int decimal_num;

    printf("Enter a decimal number to convert to binary: ");
    fgets(input, MAX_LENGTH, stdin);
    decimal_num = atoi(input);

    if (decimal_num < 0) {
        printf("Error: Invalid Input. Please enter a positive integer.\n");
        return 1;
    }

    print_binary(decimal_num);

    return 0;
}