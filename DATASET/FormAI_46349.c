//FormAI DATASET v1.0 Category: Temperature Converter ; Style: light-weight
// C Temperature Converter Example Program
#include <stdio.h>

int main() {
    // Declare variables
    float fahrenheit, celsius;

    // Input temperature in Fahrenheit
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5 / 9;

    // Display the temperature in Celsius
    printf("Temperature in Celsius: %.2f\n", celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    // Display the temperature in Fahrenheit
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}