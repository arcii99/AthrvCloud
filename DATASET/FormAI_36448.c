//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>

int main()
{
    float fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Calculate temperature in Celsius
    celsius = (fahrenheit - 32) * 5 / 9;

    // Display the converted temperature
    printf("\n%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);

    return 0;
}