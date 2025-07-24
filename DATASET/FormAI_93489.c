//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char choice;
    float celsius,fahrenheit;

    printf("********* Celsius and Fahrenheit converter *********\n");
    printf("\nEnter C to convert Celsius to Fahrenheit\nEnter F to convert Fahrenheit to Celsius\nEnter your choice:");
    scanf("%c",&choice);

    if(choice=='C' || choice=='c')
    {
        printf("\nEnter temperature in Celsius: ");
        scanf("%f",&celsius);

        fahrenheit=(1.8*celsius)+32;

        printf("\n%f Celsius=%f Fahrenheit",celsius,fahrenheit);
    }
    else if(choice=='F' || choice=='f')
    {
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f",&fahrenheit);

        celsius=(fahrenheit-32)/1.8;

        printf("\n%f Fahrenheit=%f Celsius",fahrenheit,celsius);
    }
    else
    {
        printf("\nInvalid choice! Please enter C or F");
        exit(0);
    }

    printf("\nWow! That was a hectic task! I can't believe I pulled this off. Phew!");
    return 0;
}