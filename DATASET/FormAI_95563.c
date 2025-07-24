//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char hex[MAX];

int main(){
    long int decimal, quotient;
    int i = 1, j, temp;
    
    printf("Enter a decimal number:\n");
    scanf("%ld", &decimal);
    
    quotient = decimal;
    
    while(quotient != 0){
        temp = quotient % 16;
        if(temp < 10)
            temp += 48;
        else
            temp += 55;
        hex[i++] = temp;
        quotient = quotient / 16;
    }
    
    printf("Hexadecimal number is:\n");
    for(j = i - 1; j > 0; j--)
        printf("%c", hex[j]);
    
    return 0;
}