//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

int main()
{
    float temperature, celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperature);

    // Convert Celsius to Fahrenheit
    fahrenheit = (temperature * 9/5) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, fahrenheit);

    // Convert Fahrenheit to Celsius
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &temperature);

    celsius = (temperature - 32) * 5/9;
    printf("%.2f Fahrenheit is equal to %.2f Celsius.", temperature, celsius);

    return 0;
}