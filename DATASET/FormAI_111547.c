//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
/* A decentralized C program to convert decimal to hexadecimal */
#include <stdio.h>

//Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber) {
    char hexadecimal[100];
    int index = 0;

    while(decimalNumber != 0) {
        int remainder = decimalNumber%16;

        if(remainder < 10){
            hexadecimal[index++] = remainder + 48;
        }else{
            hexadecimal[index++] = remainder + 55;
        }
        
        decimalNumber /= 16;
    }

    //Printing the result
    printf("Hexadecimal: ");
    for(int i=index-1; i>=0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

int main() {
    int decimal;

    //Taking decimal input from user
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    //Calling function to convert decimal to hexadecimal
    decimalToHexadecimal(decimal);

    return 0;
}