//FormAI DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

/* This Temperature Converter program is a real-life application that can be used to easily convert Celsius to Fahrenheit and vice versa. */

int main() {

    // declare variables
    char unit;
    float temp, convertedTemp;

    // get input from user
    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Enter the unit of temperature (C or F): ");
    scanf(" %c", &unit);

    // convert temperature based on unit of measurement 
    if (unit == 'C' || unit == 'c') {
        convertedTemp = (temp * 9.0 / 5.0) + 32;
        printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp, convertedTemp);
    } 
    else if (unit == 'F' || unit == 'f') {
        convertedTemp = (temp - 32) * 5.0 / 9.0;
        printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp, convertedTemp);
    } 
    else {
        printf("\nInvalid unit of measurement entered. Please try again.\n");
        return 1;
    }

    return 0;
}