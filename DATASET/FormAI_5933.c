//FormAI DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

// Conversion functions
double convertCelsiusToFahrenheit(double celsius){
    return (celsius * 9/5) + 32;
}

double convertFahrenheitToCelsius(double fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

int main(){
    double temperature;
    char fromUnit, toUnit;

    // Ask user for input
    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    printf("Enter unit (C/F): ");
    scanf(" %c", &fromUnit);

    printf("Enter unit to convert to (C/F): ");
    scanf(" %c", &toUnit);

    // Convert to uppercase
    fromUnit = toupper(fromUnit);
    toUnit = toupper(toUnit);

    // Convert temperature
    if(fromUnit == 'C' && toUnit == 'F'){
        double fahrenheit = convertCelsiusToFahrenheit(temperature);
        printf("%.2f%c is equal to %.2f%c\n", temperature, fromUnit, fahrenheit, toUnit);
    } else if(fromUnit == 'F' && toUnit == 'C'){
        double celsius = convertFahrenheitToCelsius(temperature);
        printf("%.2f%c is equal to %.2f%c\n", temperature, fromUnit, celsius, toUnit);
    } else {
        printf("Invalid input!\n");
    }

    return 0;
}