//FormAI DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>

int main() {
    // declare variables for temperature values
    float celsius, fahrenheit;

    // take user input for temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // convert Celsius to Fahrenheit and display result
    fahrenheit = (celsius * 1.8) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    // take user input for temperature in Fahrenheit
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // convert Fahrenheit to Celsius and display result
    celsius = (fahrenheit - 32) / 1.8;
    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);

    return 0;
}