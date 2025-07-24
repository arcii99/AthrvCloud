//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
// ALAN TURING STYLE C TEMPERATURE CONVERTER EXAMPLE PROGRAM

#include <stdio.h>

int main() {
    float temperature;
    char scale;

    printf("Welcome to the temperature converter program!\n\n");

    // Ask user for input
    printf("Please enter the temperature you would like to convert: ");
    scanf("%f", &temperature);

    printf("\n");
    printf("Please enter the scale of the temperature you entered (C or F): ");
    scanf(" %c", &scale);

    // Check if user input is valid
    if (scale != 'C' && scale != 'F') {
        printf("\n");
        printf("Invalid input! Please enter either C or F.\n");
        return 0;
    }

    // Convert Celsius to Fahrenheit
    if (scale == 'C') {
        float convertedTemperature = temperature * 1.8 + 32;
        printf("\n");
        printf("The temperature %.1f Celsius is %.1f Fahrenheit.\n", temperature, convertedTemperature);
    }

    // Convert Fahrenheit to Celsius
    if (scale == 'F') {
        float convertedTemperature = (temperature - 32) * 5 / 9;
        printf("\n");
        printf("The temperature %.1f Fahrenheit is %.1f Celsius.\n", temperature, convertedTemperature);
    }

    printf("\n");
    printf("Thank you for using our temperature converter program!\n");

    return 0;
}