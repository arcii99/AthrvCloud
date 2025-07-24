//FormAI DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main()
{
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = celsiusToFahrenheit(celsius);
    float kelvin = celsiusToKelvin(celsius);

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin", celsius, kelvin);

    return 0;
}

float celsiusToFahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32;
}

float celsiusToKelvin(float celsius)
{
    return celsius + 273.15;
}