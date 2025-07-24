//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include<stdio.h>

int main(){
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    
    int quotient = decimal_num;
    int remainder;
    int hex_num[100];
    int i = 1;

    while(quotient != 0){
        remainder = quotient % 16;
        if(remainder < 10){
            hex_num[i++] = remainder + 48;
        } else{
            hex_num[i++] = remainder + 55;
        }
        quotient /= 16;
    }

    printf("The hexadecimal equivalent of %d is: ", decimal_num);
    for(int j = i - 1; j > 0; j--){
        printf("%c", hex_num[j]);
    }

    return 0;
}