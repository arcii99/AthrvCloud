//FormAI DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal_num, quotient, remainder;
    int binary_num[100], i=1, j;
    
    printf("Please enter an integer:\n");
    scanf("%d", &decimal_num);
    
    quotient = decimal_num;
    
    while (quotient != 0) {
        binary_num[i++] = quotient % 2;
        quotient = quotient / 2;
    }
    
    printf("The binary representation of %d is ", decimal_num);
    
    for (j = i - 1; j > 0; j--)
        printf("%d", binary_num[j]);
    
    printf(".\n");
    
    return 0;
}