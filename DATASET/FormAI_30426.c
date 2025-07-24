//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main()
{
    float celsius, fahrenheit, kelvin;
    
    printf("Enter a temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f C = %.2f F\n", celsius, fahrenheit);
    
    kelvin = celsiusToKelvin(celsius);
    printf("%.2f C = %.2f K\n", celsius, kelvin);
    
    return 0;
}

float celsiusToFahrenheit(float celsius)
{
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

float celsiusToKelvin(float celsius)
{
    float kelvin = celsius + 273.15;
    return kelvin;
}