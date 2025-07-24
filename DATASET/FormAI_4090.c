//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>

int main() {
    //define variables
    int decimalNumber, quotient, i=1, j, temp;
    char hexadecimalNumber[100];

    printf("Enter decimal number: ");
    scanf("%d", &decimalNumber);

    quotient = decimalNumber;
    
    //convert decimal to hexadecimal
    while(quotient != 0) {
        temp = quotient % 16;

        //to convert integer into character
        if(temp < 10) {
            temp += 48;
        }
        else {
            temp += 55;
        }

        hexadecimalNumber[i] = temp;
        i++;
        quotient /= 16;
    }

    printf("Hexadecimal number of %d is: ", decimalNumber);
    
    //display hexadecimal number
    for(j=i-1; j>0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }

    return 0;
}