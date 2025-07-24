//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>

void binary(unsigned int num) {
    int binary_num = 0, base = 1, temp = num;

    while (temp > 0) {
        int last_digit = temp % 2;
        binary_num += last_digit * base;
        base *=10;
        temp /= 2;
    }

    printf("Binary of %d: %d\n", num, binary_num);
}

int main() {
    unsigned int num;
    printf("Enter a number to convert to binary: ");
    scanf("%u", &num);
    binary(num);
    return 0;
}