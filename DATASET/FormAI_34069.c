//FormAI DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float fahrenheit, celsius;

    printf("Please enter a temperature in Fahrenheit:");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5/9;

    printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);

    return 0;
}