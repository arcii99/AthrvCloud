//FormAI DATASET v1.0 Category: Binary Converter ; Style: shocked
#include<stdio.h>

int main() {

    int number;
    printf("Enter the decimal number to convert to binary: ");
    scanf("%d", &number);

    int binary[64];
    int index = 0;

    while (number > 0) {
        binary[index++] = number % 2;
        number = number / 2;
    }

    printf("The binary equivalent is: ");

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    return 0;
}