//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
/* A C Temperature Converter program in Dennis Ritchie style */
#include <stdio.h>

/* function declarations */
float convertToFahrenheit(float celsius);
float convertToKelvin(float celsius);

int main() {
    float celsius, fahrenheit, kelvin;
    char choice;

    do {
        /* input */
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &celsius);

        /* conversion */
        fahrenheit = convertToFahrenheit(celsius);
        kelvin = convertToKelvin(celsius);

        /* output */
        printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n", celsius, fahrenheit);
        printf("%.2f degrees Celsius = %.2f Kelvin\n", celsius, kelvin);

        /* ask for another conversion */
        printf("\nWould you like to convert another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

/* function definitions */
float convertToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float convertToKelvin(float celsius) {
    return celsius + 273.15;
}