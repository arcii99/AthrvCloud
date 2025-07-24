//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    float temperature;
    char unit;

    // Prompt the user to enter the temperature and its unit
    printf("Please enter the temperature: ");
    scanf("%f%c", &temperature, &unit);

    // Convert the temperature to Celsius or Fahrenheit depending on its unit
    if (unit == 'C' || unit == 'c') {
        float fahrenheit = celsiusToFahrenheit(temperature);
        printf("%f degrees Celsius is equal to %f degrees Fahrenheit\n", temperature, fahrenheit);
    } else if (unit == 'F' || unit == 'f') {
        float celsius = fahrenheitToCelsius(temperature);
        printf("%f degrees Fahrenheit is equal to %f degrees Celsius\n", temperature, celsius);
    } else {
        // Invalid unit, terminate the program
        printf("Invalid unit. Please enter a temperature followed by either 'C' or 'F'.\n");
        return 1;
    }

    return 0;
}