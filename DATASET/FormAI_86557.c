//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include<stdio.h>

float convertToFahrenheit(float celcius);
/* Function to convert temperature from Celcius to Fahrenheit */

int main()
{
    float celcius;
    printf("Enter temperature in Celcius: ");
    scanf("%f", &celcius);
    printf("\n%.2fC = %.2fF\n", celcius, convertToFahrenheit(celcius));
    return 0;
}

float convertToFahrenheit(float celcius)
{
    float fahrenheit;
    fahrenheit = (celcius * 9.0 / 5.0) + 32.0; /* Conversion formula */
    return fahrenheit;
}