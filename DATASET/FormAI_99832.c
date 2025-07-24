//FormAI DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>

int main()
{
    float temp_celsius, temp_fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temp_celsius);

    // Conversion Formula from Celsius to Fahrenheit
    temp_fahrenheit = (temp_celsius * 9/5) + 32;

    printf("%.2f Celsius is %.2f Fahrenheit\n", temp_celsius, temp_fahrenheit);

    return 0;
}