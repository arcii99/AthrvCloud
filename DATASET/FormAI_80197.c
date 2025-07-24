//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

int main() {

    printf("Welcome to the Unit Converter\n");
    printf("This program can convert between Celsius, Fahrenheit and Kelvin temperature scales\n");

    double temp;
    char unit;

    printf("Enter the temperature you want to convert: ");
    scanf("%lf", &temp);
    printf("Enter the unit of temperature (C/F/K): ");
    scanf(" %c", &unit);

    double convertedTemp;

    switch(unit) {
        case 'C':
            convertedTemp = temp * 1.8 + 32; //Celsius to Fahrenheit
            printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit and %.2lf Kelvin\n", temp, convertedTemp, temp + 273.15);
            break;
        
        case 'F':
            convertedTemp = (temp - 32) / 1.8; //Fahrenheit to Celsius
            printf("%.2lf degrees Fahrenheit is equivalent to %.2lf degrees Celsius and %.2lf Kelvin\n", temp, convertedTemp, (convertedTemp + 273.15));
            break;

        case 'K':
            convertedTemp = temp - 273.15; //Kelvin to Celsius
            printf("%.2lf degrees Kelvin is equivalent to %.2lf degrees Celsius and %.2lf Fahrenheit\n", temp, convertedTemp, (convertedTemp * 1.8) + 32);
            break;

        default:
            printf("Invalid unit of temperature");
    }

    return 0;
}