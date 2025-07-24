//FormAI DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal_number, binary_number[32], remainder, place_value = 1, index = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);
    while(decimal_number > 0) {
        remainder = decimal_number % 2;
        decimal_number /= 2;
        binary_number[index] = remainder;
        index++;
    }
    printf("Binary conversion is: ");
    for(int i = index - 1; i >= 0; i--) {
        printf("%d", binary_number[i]);
    }
    printf("\n");
    return 0;
}