//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include<stdio.h>

/* This program converts a decimal number to hexa-decimal number */
/* A medieval style converter. */

int main() 
{

    int i, j, n, rem;
    int quotient[1000];
    char hexaDeciNum[100];

    printf("Greetings traveller! Welcome to the Hexadecimal Converter Program!\n");
    printf("Please enter a decimal number that you wish to convert: ");
    scanf("%d", &n);
    printf("Alright, let me convert the number %d into a hexa-decimal quantity...\n", n);
    
    /* convert decimal to hexadecimal */
    /* by dividing decimal number by 16 and printing remainder in reverse order */
    /* add a scroll sound as it prints each remainder in reverse order to recreate the medieval effect */

    i = 0;
    while(n != 0) 
    {
        quotient[i] = n % 16;
        n = n / 16;
        i++;
    }
    printf("The hexa-decimal number is: ");
    for(j = i - 1; j >= 0; j--) 
    {
        rem = quotient[j];
        if (rem < 10)
            hexaDeciNum[j] = 48 + rem; /* print character 0-9 */
        else
            hexaDeciNum[j] = 55 + rem; /* print character A-F */
	printf("%c",hexaDeciNum[j]);
/* print hexa-decimal number with medieval scroll sound */
printf("shhhhh");
printf("%c\n",hexaDeciNum[j]);
    }
    return 0;
}