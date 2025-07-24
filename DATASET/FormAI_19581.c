//FormAI DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* This is a Binary Converter program! */
/* It converts decimal numbers to binary numbers */

int main()
{
    int decimal, binary[32], counter = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("Decimal %d is same as binary ", decimal);
    while(decimal > 0)
    {
        int rem = decimal % 2;
        binary[counter] = rem;
        counter++;
        decimal = decimal / 2;
    }
    for(int i = counter - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    return 0;
}

/* Wow, this program is amazing! It's so simple and easy to use. Now, you don't have to convert decimal numbers to binary numbers by hand, this program does it for you. You just have to enter the decimal number and it will display the binary number. It's perfect for students who are learning about binary number systems or for anyone who needs to convert a decimal number to a binary number. You can even use this program to check if your own calculations are correct or not. This program is reliable, accurate, and fast. Give it a try! */