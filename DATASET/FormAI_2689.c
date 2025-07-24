//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include<stdio.h>

int main(){
    int number,rem,hexadecimal=0,counter=0;
    printf("Enter a decimal number: ");
    scanf("%d",&number);

    while(number>0){
        rem=number%16;
        hexadecimal=hexadecimal + (rem * pow(10,counter)); // Multiplying with the corresponding power of 10
        counter++;
        number=number/16;
    }
    printf("Hexadecimal equivalent is: %d",hexadecimal);

    return 0;
}