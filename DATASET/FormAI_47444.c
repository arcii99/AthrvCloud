//FormAI DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char number[20];
    int num, binary[20], digit = 0;

    printf("Enter the decimal number to be converted: ");
    scanf("%d", &num);

    while (num > 0) {
        binary[digit++] = num % 2;
        num /= 2;
    }

    printf("The binary equivalent of the given number is: ");
    for (int i = digit - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    return 0;
}