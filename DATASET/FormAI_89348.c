//FormAI DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    int num, binaryArr[32], index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert decimal to binary
    while (num > 0) {
        binaryArr[index] = num % 2;
        index++;
        num /= 2;
    }

    // Print binary equivalent
    printf("Binary equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryArr[i]);
    }

    printf("\n");

    return 0;
}