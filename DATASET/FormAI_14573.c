//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
// Welcome to the Temperature Converter Bot!
// This program converts temperatures between Celsius and Fahrenheit.
// Choose the temperature scale to convert from and the scale to convert to.

#include<stdio.h>
#include<stdlib.h>

int main() {
    char input;
    float temperature, converted_temperature;
    printf("Welcome to Temperature Converter Bot!\n");
    printf("Please select the temperature scale to convert from:\n");
    printf("Type C for Celsius or F for Fahrenheit: ");
    scanf("%c", &input);
    printf("Please enter the temperature value to convert: ");
    scanf("%f", &temperature);
    if(input == 'C') { // Celsius to Fahrenheit conversion
        converted_temperature = (temperature * 9/5) + 32;
        printf("%.2fC equals %.2fF\n", temperature, converted_temperature);
    } else if(input == 'F') { // Fahrenheit to Celsius conversion
        converted_temperature = (temperature - 32) * 5/9;
        printf("%.2fF equals %.2fC\n", temperature, converted_temperature);
    } else { // Invalid input
        printf("Invalid input. Please try again.\n");
    }
    return 0;
}