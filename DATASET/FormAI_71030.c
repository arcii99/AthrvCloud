//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>

void print_hex(int num);

int main() {
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    
    printf("The hexadecimal equivalent of %d is: ", decimal_num);
    print_hex(decimal_num);
    
    return 0;
}

void print_hex(int num) {
    char hex_digits[] = "0123456789ABCDEF";
    int remainder;
    int hex_num[100];
    int i = 0;
    
    while (num > 0) {
        remainder = num % 16;
        hex_num[i] = remainder;
        num /= 16;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex_digits[hex_num[j]]);
    }
    
    printf("\n");
}