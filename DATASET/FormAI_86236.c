//FormAI DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include<stdio.h>

int main(){
    printf("Enter a decimal number: ");
    int decimal;
    scanf("%d",&decimal);

    int binary[32]; //array to store binary digits
    int i = 0; //index variable for binary array

    //convert decimal number to binary
    while(decimal > 0){
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Binary equivalent: ");
    for(int j=i-1; j>=0; j--){
        printf("%d",binary[j]);
    }
    printf("\n");

    return 0;
}