//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include<stdio.h>

int main(){
    int decimal, quotient, remainder, i=1, j, temp;
    char hexadecimal[50];

    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    quotient = decimal;

    while(quotient!=0){
        temp = quotient % 16;

        if(temp<10){
            temp = temp + 48;
        }
        else{
            temp = temp + 55;
        }

        hexadecimal[i++]= temp;
        quotient = quotient / 16;
    }

    printf("Equivalent hexadecimal number is: ");

    for(j=i-1; j>0; j--){
        printf("%c", hexadecimal[j]);
    }

    return 0;
}