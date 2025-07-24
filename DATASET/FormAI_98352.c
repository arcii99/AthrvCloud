//FormAI DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 16

int main() {
    int decimal;
    char binary[MAX_BITS];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if(decimal < 0) {
        printf("Can only convert non-negative integers.\n");
        return 1;
    }

    int i = 0;
    while(decimal > 0) {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }

    if(i == 0) {
        binary[i] = '0';
        i++;
    }

    binary[i] = '\0';

    // reverse binary string
    for(int j = 0; j < i/2; j++) {
        char temp = binary[j];
        binary[j] = binary[i-1-j];
        binary[i-1-j] = temp;
    }

    printf("Binary: %s\n", binary);

    return 0;
}