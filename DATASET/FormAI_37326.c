//FormAI DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>

void binary_converter(int decimal_num) {
    int binary_arr[32]; // Assume the max size of 32 bit binary number
    int index = 0;
    while (decimal_num > 0) {
        binary_arr[index] = decimal_num % 2;
        decimal_num /= 2;
        index++;
    }
    printf("Binary equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary_arr[i]);
    }
}

int main() {
    int decimal_num;
    printf("Enter decimal number to convert to binary: ");
    scanf("%d", &decimal_num);
    binary_converter(decimal_num);
    return 0;
}