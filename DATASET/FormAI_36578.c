//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>

int main() {
    int decimal, remainder, quotient;
    int i = 1, j, temp;
    char hex[100];

    printf("Greetings traveler! Welcome to my medieval style C Hexadecimal converter.\n");
    printf("Enter a decimal number to convert:\n");
    scanf("%d", &decimal);

    quotient = decimal;

    while (quotient != 0) {
        temp = quotient % 16;
        //If temp is less than 10, add 48 to make it an ASCII value of 0-9
        if (temp < 10)
            temp = temp + 48;
        //Otherwise, add 55 to make it an ASCII value of A-F
        else
            temp = temp + 55;
        hex[i++] = temp;
        quotient = quotient / 16;
    }

    printf("\nThe hexadecimal value of %d is: ", decimal);
    for (j = i - 1; j > 0; j--) {
        printf("%c", hex[j]);
    }

    printf("\nA magical journey indeed! Farewell adventurer.\n");

    return 0;
}