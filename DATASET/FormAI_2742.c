//FormAI DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>

int main() {
    // initialize variables
    int decimal, binary[32], i = 0, j;

    // get decimal input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // convert decimal to binary
    while(decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    // print binary equivalent
    printf("Binary equivalent: ");
    for(j = i-1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    return 0;
}