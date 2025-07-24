//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>

int main() {
    int decimal_number, quotient, remainder;
    char hexadecimal_number[100];
    int i = 1, j, temp;

    printf("Hi there! Welcome to my cheerful hexadecimal converter program.\n");
    printf("Please enter a decimal number that you would like to convert into hexadecimal: ");
    scanf("%d", &decimal_number);

    quotient = decimal_number;

    while (quotient != 0) {
        temp = quotient % 16;
        
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        
        hexadecimal_number[i++] = temp;
        quotient = quotient / 16;
    }
    
    printf("\nTa-da! Your decimal number %d in hexadecimal is: ", decimal_number);
    
    for (j = i - 1; j > 0; j--) {
        printf("%c", hexadecimal_number[j]);
    }
    
    printf("\n");
    
    printf("Thanks for using my happy hexadecimal converter program! :)");
    
    return 0;
}