//FormAI DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>

void paranoid_converter() {
    int binary_number, decimal_number = 0, base = 1, remainder;
    printf("Enter a binary number: ");
    scanf("%d", &binary_number);

    // Checking if the binary number has only 0's and 1's
    int temp = binary_number;
    while (temp != 0) {
        remainder = temp % 10;
        if (remainder > 1) {
            printf("Error: Invalid binary number");
            return;
        }
        temp /= 10;
    }

    // Converting binary to decimal
    temp = binary_number;
    while (temp != 0) {
        remainder = temp % 10;
        decimal_number += remainder * base;
        base *= 2;
        temp /= 10;
    }

    // Converting decimal to binary
    int index = 0, binary_array[100];
    temp = decimal_number;
    while (temp != 0) {
        binary_array[index] = temp % 2;
        temp /= 2;
        index++;
    }

    printf("Converted binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary_array[i]);
    }
}

int main() {
    paranoid_converter();
    return 0;
}