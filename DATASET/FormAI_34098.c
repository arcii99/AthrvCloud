//FormAI DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>

void binaryConvert(int);

int main(){
    printf("Welcome to the Binary Converter program!\n");
    printf("Enter a decimal number to convert to binary: ");

    int number;
    scanf("%d", &number);

    printf("The binary equivalent of %d is: ", number);
    binaryConvert(number);

    printf("\nThank you for using the Binary Converter program!\n");

    return 0;
}

void binaryConvert(int number){
    if (number == 0){
        return;
    }

    int binary = number % 2;
    number /= 2;
    binaryConvert(number);
    printf("%d", binary);
}