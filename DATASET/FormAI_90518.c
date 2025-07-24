//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int decimal, remainder,quotient, i=1,j,temp;
    char hexadecimal[1000];

    printf("Enter Decimal number: ");
    scanf("%d",&decimal);

    quotient = decimal;

    while(quotient!=0){
        temp = quotient % 16;

        //To convert integer into character
        if(temp < 10){
            temp = temp + 48;
        }
        else{
            temp = temp + 55;
        }

        hexadecimal[i++]= temp;
        quotient = quotient / 16;
    }

    printf("\nHexadecimal number is: ");
    for(j=i-1;j>0;j--){
        printf("%c",hexadecimal[j]);
    }
    printf("\n");

    return 0;
}