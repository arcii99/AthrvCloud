//FormAI DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void binary(int n);

int main() {
    int num;

    // Prompt user for input
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if(num < 0) { // Check for negative input
        printf("Cannot convert negative numbers to binary.\n");
        return 0;
    } else if(num == 0) { // Check for zero input
        printf("Binary: 0\n");
        return 0;
    }

    // Call binary function to convert to binary
    printf("Binary: ");
    binary(num);
    printf("\n");

    return 0;
}

void binary(int n) {
    if(n == 0) // Base case
        return;
    binary(n / 2); // Recursive call
    printf("%d", n % 2);
}