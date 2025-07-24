//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void hex_convert(int num) {
    if (num / 16 != 0) {
        hex_convert(num / 16);
    }
    int mod = num % 16;
    if (mod < 10) {
        printf("%d", mod);
    } else {
        printf("%c", mod + 'A' - 10);
    }
}

int main() {
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    printf("Hexadecimal equivalent is: ");
    hex_convert(decimal_num);
    printf("\n");
    return 0;
}