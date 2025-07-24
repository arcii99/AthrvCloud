//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    float celsius, fahrenheit, kelvin;

    // get input from user
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // convert to Fahrenheit and Kelvin
    fahrenheit = celsiusToFahrenheit(celsius);
    kelvin = celsiusToKelvin(celsius);

    // display results
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius is equivalent to %.2f Kelvin", celsius, kelvin);

    return 0;
}