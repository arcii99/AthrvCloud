//FormAI DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nWelcome to the Binary Converter!");
    printf("\nThis program will convert a decimal number to binary.");
    
    int decimal, binary[1000], i=0;
    printf("\nEnter the decimal number you want to convert: ");
    scanf("%d", &decimal);
    
    printf("\nThe binary equivalent of %d is: ", decimal);
    
    while(decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    
    for(int j=i-1; j>=0; j--)
    {
        printf("%d", binary[j]);
    }
    
    printf("\n\nThank you for using the Binary Converter!");
    return 0;
}