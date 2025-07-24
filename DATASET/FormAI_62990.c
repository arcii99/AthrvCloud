//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void convert_hex(int num);

int main() {
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    printf("The equivalent hexadecimal number is: ");
    convert_hex(decimal_num);
    printf("\n");
    return 0;
}

void convert_hex(int num) {
    int remainder;
    
    if (num == 0) {
        return;
    }
    
    remainder = num % 16;
    convert_hex(num / 16);
    
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder + 55);
    }
}