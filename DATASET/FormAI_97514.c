//FormAI DATASET v1.0 Category: Binary Converter ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void binaryConvert(int decimalNumber);

int main(){

    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d",&decimalNumber);

    printf("Binary of %d is ", decimalNumber);
    binaryConvert(decimalNumber);
    printf("\n");

    return 0;
}

void binaryConvert(int decimalNumber){

    if(decimalNumber == 0){
        return;
    }
    else{
        binaryConvert(decimalNumber/2);
        printf("%d", decimalNumber%2);
    }
}