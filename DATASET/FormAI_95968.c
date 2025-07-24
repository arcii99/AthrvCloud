//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    float fahrenheit, celsius;
    char choice;
    printf("Which temperature you want to convert to? \n");
    printf("Enter F to convert temperature to Fahrenheit. \n");
    printf("Enter C to convert temperature to Celsius. \n");
    scanf("%c", &choice);

    switch(choice) 
    {
        case 'F':
        case 'f':
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = ((9 * celsius) / 5.0) + 32;
            printf("%.2f Celsius equals to %.2f Fahrenheit. \n", celsius, fahrenheit);
            break;

        case 'C':
        case 'c':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (5 * (fahrenheit - 32)) / 9.0;
            printf("%.2f Fahrenheit equals to %.2f Celsius. \n", fahrenheit, celsius);
            break;

        default:
            printf("You have entered an invalid choice! \n");
            break;
    }

    return 0;
}