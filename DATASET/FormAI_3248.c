//FormAI DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>

#define MAX_BITS 32

int main() {

    int decimal_number;
    int binary_number[MAX_BITS];
    int index = 0;

    // get decimal number from user
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    // check if decimal number is negative
    if(decimal_number < 0) {
        printf("ERROR: Binary conversion of negative numbers is not allowed.\n");
        return 1;
    }

    // convert decimal number to binary
    while(decimal_number > 0) {
        binary_number[index] = decimal_number % 2;
        decimal_number /= 2;
        index++;
    }

    // print binary number
    if(index == 0) {
        printf("0");
    } else {
        for(int i = index-1; i >= 0; i--) {
            printf("%d", binary_number[i]);
        }
    }

    printf("\n");

    return 0;
}