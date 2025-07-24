//FormAI DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>

void binaryConversion(int num) {
    if (num > 1) {
        binaryConversion(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    int decimal, binary = 0, base = 1, rem;
    printf("Enter decimal number: ");
    scanf("%d", &decimal);
    while (decimal > 0) {
        rem = decimal % 2;
        binary = binary + rem * base;
        decimal = decimal / 2;
        base = base * 10;
    }
    printf("Binary equivalent: %d\n", binary);
    printf("Binary conversion recursive: ");
    binaryConversion(binary);
    printf("\n");
    return 0;
}