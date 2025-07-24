//FormAI DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>

int main() {
    int num;
    char binary[32]; // Maximum size of binary representation for 32-bit integer
    int i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Convert decimal to binary
    while (num != 0) {
        binary[i] = num % 2 + '0'; // Convert remainder to char and add to binary array
        num /= 2;
        i++;
    }
    binary[i] = '\0'; // Add null terminator at the end of the binary string

    // Reverse binary string
    int j;
    for (j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    printf("Binary representation: %s", binary);

    return 0;
}