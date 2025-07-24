//FormAI DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main(){
    int binary, decimal = 0, base = 1, temp;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    // Convert to decimal
    temp = binary;
    while(temp > 0){
        if(temp % 10 == 1){
            decimal += base;
        }
        base *= 2;
        temp /= 10;
    }
    printf("Decimal equivalent: %d\n", decimal);

    // Convert decimal back to binary
    int quotient = decimal;
    int remainder;
    char binary_string[50];
    int i = 0;

    while(quotient != 0){
        remainder = quotient % 2;
        binary_string[i++] = remainder + '0';
        quotient /= 2;
    }
    binary_string[i] = '\0';

    printf("Binary equivalent: ");
    for(int j = i-1; j >= 0; j--){
        printf("%c", binary_string[j]);
    }
    printf("\n");

    return 0;
}