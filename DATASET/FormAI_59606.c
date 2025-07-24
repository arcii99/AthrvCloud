//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>

char hexChar[] = "0123456789ABCDEF";

void convertToHex(int num) {
    int remainder;
    char hexValue[50];
    int i = 0;

    while(num != 0) {
        remainder = num % 16;
        hexValue[i++] = hexChar[remainder];
        num /= 16;
    }

    printf("\nHexadecimal Value: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexValue[j]);
    }
    printf("\n");
}

int main() {
    int num;
    printf("\nEnter a decimal number: ");
    scanf("%d", &num);

    convertToHex(num);

    return 0;
}