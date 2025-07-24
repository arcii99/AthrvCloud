//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include<stdio.h>

void binary(int decimal){
    int binary[32], n = 0;
    while(decimal > 0){
        binary[n] = decimal%2;
        decimal /= 2;
        n++;
    }
    for(int i=n-1; i>=0; i--){
        printf("%d", binary[i]);
    }
}

int main(){
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("The binary equivalent of %d is: ", decimal);
    binary(decimal);
    return 0;
}