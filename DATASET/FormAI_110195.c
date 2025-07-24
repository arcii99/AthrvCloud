//FormAI DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0, j;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Printing binary array in reverse order
    printf("Binary Number: ");
    for (j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main() {
    int decimalNum;
    printf("Enter decimal number: ");
    scanf("%d", &decimalNum);
    if (decimalNum < 0) {
        printf("Negative numbers are not allowed!\n");
    } else {
        decimalToBinary(decimalNum);
    }
    return 0;
}