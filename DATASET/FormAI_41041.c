//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINARY 64

void binary_converter(unsigned long decimal_number, char *binary_number);
void print_binary(char *binary_number);

int main() {
    unsigned long decimal_number;
    char binary_number[MAX_BINARY];

    printf("Enter a positive decimal number to convert to binary: ");
    scanf("%lu", &decimal_number);
    binary_converter(decimal_number, binary_number);
    print_binary(binary_number);

    return 0;
}

void binary_converter(unsigned long decimal_number, char *binary_number) {
    int i = 0;

    while(decimal_number > 0) {
        binary_number[i] = decimal_number % 2 + '0';
        decimal_number /= 2;
        i++;
    }

    binary_number[i] = '\0';

    int j;
    char temp;

    for(j = 0; j < i / 2; j++) {
        temp = binary_number[j];
        binary_number[j] = binary_number[i - j - 1];
        binary_number[i - j - 1] = temp;
    }
}

void print_binary(char *binary_number) {
    printf("Binary equivalent: %s\n", binary_number);
}