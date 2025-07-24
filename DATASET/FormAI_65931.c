//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: standalone
#include <stdio.h>

void hexConversion(int num) {
    if (num / 16 != 0) {
        hexConversion(num / 16);
    }
    int remainder = num % 16;
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + remainder - 10);
    }
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Hexadecimal equivalent is : ");
    hexConversion(num);
    printf("\n");
    return 0;
}