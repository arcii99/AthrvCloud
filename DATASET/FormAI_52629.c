//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

int main()
{
    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9/5) + 32;

    // Convert Celsius to Kelvin
    kelvin = celsius + 273.15;

    printf("%.2f Celsius is equivalent to %.2f Fahrenheit and %.2f Kelvin\n", celsius, fahrenheit, kelvin);

    return 0;
}