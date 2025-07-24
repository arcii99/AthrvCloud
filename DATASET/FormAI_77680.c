//FormAI DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>

void print_binary(unsigned int n) {
    if (n / 2 != 0) {
        print_binary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {

    unsigned int decimal, binary = 0, base = 1, rem;
    
    printf("Enter a decimal number: ");
    scanf("%u", &decimal);

    while (decimal > 0) {
        rem = decimal % 2;
        binary += rem * base;
        decimal /= 2;
        base *= 10;
    }

    printf("The binary equivalent is: %u\n", binary);

    printf("Now let's convert it back to decimal.\n");

    unsigned int temp = binary, factor = 1, decimal2 = 0;

    while (temp > 0) {
        rem = temp % 10;
        decimal2 += rem * factor;
        factor *= 2;
        temp /= 10;
    }

    printf("The decimal equivalent of %u is: %u\n", binary, decimal2);

    printf("Well, that was easy!\n");

    return 0;
}