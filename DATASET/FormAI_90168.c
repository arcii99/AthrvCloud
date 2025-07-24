//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main(){

    int num, decimal_num, binary_num, base = 1, rem;
    printf("Enter a decimal number to convert into binary: ");
    scanf("%d",&decimal_num);
    
    num = decimal_num;

    while(num > 0){
        
        rem = num % 2;
        binary_num = binary_num + rem * base;
        num = num / 2;
        base = base * 10;
    }

    printf("\nBinary equivalent of %d is %d.\n",decimal_num, binary_num);

    return 0;
}