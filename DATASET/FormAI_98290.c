//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

int main() {
    float input_value;
    int input_unit, output_unit;

    // Welcome message
    printf("==============================\n");
    printf("Welcome to the Unit Converter!\n");
    printf("==============================\n");

    // Ask for input value
    printf("Enter the input value: ");
    scanf("%f", &input_value);

    // Ask for input unit
    printf("Enter the input unit (1 for Celsius, 2 for Fahrenheit, 3 for Kelvin): ");
    scanf("%d", &input_unit);

    // Ask for output unit
    printf("Enter the output unit (1 for Celsius, 2 for Fahrenheit, 3 for Kelvin): ");
    scanf("%d", &output_unit);

    // Convert input unit to base unit (Kelvin)
    if (input_unit == 1) {
        input_value += 273.15; // Celsius to Kelvin
    }
    else if (input_unit == 2) {
        input_value = (input_value - 32) * (5.0/9.0) + 273.15; // Fahrenheit to Kelvin
    }

    // Convert base unit (Kelvin) to output unit
    if (output_unit == 1) {
        input_value -= 273.15; // Kelvin to Celsius
    }
    else if (output_unit == 2) {
        input_value = (input_value - 273.15) * (9.0/5.0) + 32; // Kelvin to Fahrenheit
    }

    // Display the converted value
    printf("The converted value is %.2f\n", input_value);

    return 0;
}