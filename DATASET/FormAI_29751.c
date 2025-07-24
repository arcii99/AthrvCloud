//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToHex(unsigned int num);

int main() {
    int decimalNumber;

    printf("Enter decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Hexadecimal conversion of decimal number %d is: ", decimalNumber);
    convertToHex(decimalNumber);

    return 0;
}

void convertToHex(unsigned int num) {
    char hex[100];
    int i = 1, j, temp;

    while (num != 0) {
        temp = num % 16;

        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }

        hex[i++] = temp;
        num /= 16;
    }

    printf("0x");

    for (j = i - 1; j > 0; j--) {
        printf("%c", hex[j]);
    }

    printf("\n");
}