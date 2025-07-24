//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

/* function to convert temperature in Celsius to Fahrenheit */
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

/* function to convert temperature in Celsius to Kelvin */
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    double celsius = 0;

    /* prompt user for input */
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    /* convert temperature to Fahrenheit and Kelvin */
    double fahrenheit = celsiusToFahrenheit(celsius);
    double kelvin = celsiusToKelvin(celsius);

    /* print out the results */
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit and %.2f Kelvin.\n", celsius, fahrenheit, kelvin);

    return 0;
}