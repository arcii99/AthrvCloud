//FormAI DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include<stdio.h>

void decToBin(int num){
    int binary[100], i=0;
    while(num>0){
        binary[i] = num%2;
        num = num/2;
        i++;
    }
    for(int j=i-1; j>=0; j--){
        printf("%d", binary[j]);
    }
}

int main(){
    int decimalNum;
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimalNum);
    if(decimalNum<0){
        printf("Invalid input, please enter a positive integer.\n");
        return 0;
    }
    printf("The binary equivalent of %d is ", decimalNum);
    decToBin(decimalNum);
    printf("\n");
    return 0;
}