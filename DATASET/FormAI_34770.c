//FormAI DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int decimal, binary = 0, base = 1;

    //Take decimal number input
    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    //Convert decimal to binary
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    //Print the binary equivalent
    printf("Binary equivalent is: %d", binary);

    return 0;
}