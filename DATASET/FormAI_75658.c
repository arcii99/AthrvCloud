//FormAI DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char binary[64];    // binary number string
    int num;            // decimal number
    int rem, i = 0;     // remainder, index i

    printf("Welcome to the Binary Converter!\n\n");
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // decimal to binary conversion
    while (num != 0) {
        rem = num % 2;
        binary[i++] = rem + '0';    // convert int to char
        num /= 2;
    }

    binary[i] = '\0';    // add null terminator to binary string

    // reverse binary string
    char temp;
    int len = strlen(binary);
    for (int j = 0; j < len / 2; j++) {
        temp = binary[j];
        binary[j] = binary[len - j - 1];
        binary[len - j - 1] = temp;
    }

    // print binary result
    printf("\nBinary: %s\n", binary);

    return 0;
}