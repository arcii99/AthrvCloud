//FormAI DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include<stdio.h>

int main(){
    int num, binary_digits[100], i=0;

    printf("Welcome to the Binary Converter!!\n");
    printf("Enter the number you want to convert: ");

    scanf("%d", &num);

    //Converting decimal to binary
    while(num>0){
        binary_digits[i] = num%2;
        num /= 2;
        i++;
    }

    //Printing binary digits in reverse order
    printf("The binary conversion of the number is: ");
    for(int j=i-1; j>=0; j--){
        printf("%d", binary_digits[j]);
    }

    printf("\nCongratulations! You have converted a decimal number to binary.");
    return 0;
}