//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>

int main() {
    int decimalNum, index = 0;
    char hexNum[10];
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    while (decimalNum > 0) {
        int remainder = decimalNum % 16;
        if (remainder < 10) {
            hexNum[index++] = 48 + remainder;
        } else {
            hexNum[index++] = 55 + remainder;
        }
        decimalNum /= 16;
    }
    printf("The hexadecimal equivalent is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexNum[i]);
    }
    printf("\n");
    return 0;
}