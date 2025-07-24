//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

/* A fun and cheerful C Temperature Converter! */

int main(void)
{
    float fahrenheit, celsius;

    printf("Hey there! Welcome to the Temperature Converter! \n\n");

    printf("First, let's convert Fahrenheit to Celsius! \n");
    printf("Enter your temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = ((fahrenheit - 32) * 5) / 9;
    printf("%.2f degrees Fahrenheit is equivalent to %.2f degrees Celsius! \n", fahrenheit, celsius);

    printf("\nNow let's convert Celsius to Fahrenheit! \n");
    printf("Enter your temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit! \n", celsius, fahrenheit);

    printf("\nThanks for using the Temperature Converter! \n");

    return 0;
}