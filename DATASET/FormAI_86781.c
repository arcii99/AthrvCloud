//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, rem, i = 1, binary = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num != 0){
        rem = num % 2;
        num /= 2;
        binary += rem * i;
        i *= 10;
    }

    printf("The binary equivalent is: %d", binary);

    return 0;
}