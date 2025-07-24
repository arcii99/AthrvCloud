//FormAI DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

int get_binary_length(int num) {
    int length = 0;
    while (num > 0) {
        num /= 2;
        length++;
    }
    return length;
}

void print_binary(int num, int length) {
    bool binary[length];
    for (int i = length - 1; i >= 0; i--) {
        binary[i] = num % 2;
        num /= 2;
    }
    for (int i = 0; i < length; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimal_num, binary_len;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    printf("The binary representation of %d is: ", decimal_num);
    binary_len = get_binary_length(decimal_num);
    print_binary(decimal_num, binary_len);
    return 0;
}