//FormAI DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>

void dec_to_bin(unsigned int num) {
    if(num > 1)
        dec_to_bin(num / 2);

    printf("%d", num % 2);
}

int main() {
    unsigned int decimal;

    printf("Enter a decimal number: ");
    scanf("%u", &decimal);

    printf("Binary equivalent: ");
    dec_to_bin(decimal);
    printf("\n");

    return 0;
}