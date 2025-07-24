//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEX_DIGITS 10

char uppercase(char c){
    if(c >= 'a' && c <= 'z'){
        return (c-'a') + 'A';
    }
    return c;
}

void print_hex(int num, int digits)
{
    char hex[MAX_HEX_DIGITS];
    int i;
    for (i = digits-1; i >= 0; --i) {
        hex[i] = (num % 16 < 10) ? ('0' + num % 16) : ('A' + num % 16 - 10);
        num /= 16;
    }
    printf("Hexadecimal: ");
    for (i = 0; i < digits; ++i) {
        putchar(uppercase(hex[i]));
    }
    printf("\n");
}

int read_integer()
{
    int num;
    printf("Enter a decimal integer:\n");
    scanf("%d", &num);
    return num;
}

int main()
{
    int num, digits;
    printf("*** Decimal to Hexadecimal Converter ***\n");
    num = read_integer();
    digits = 1;
    while (num >= (1 << (4*digits))) {
        digits += 1;
    }
    print_hex(num, digits);
    return 0;
}