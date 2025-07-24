//FormAI DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int decimal_num, binary_num[32], i = 0;

    // Take input from user
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    // Convert decimal to binary
    while(decimal_num > 0) {
        binary_num[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }

    // Print the binary number in reverse order
    printf("Equivalent binary number is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binary_num[j]);
    }

    return 0;
}