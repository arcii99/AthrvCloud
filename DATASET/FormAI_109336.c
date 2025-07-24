//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

int main() {

    printf("Welcome to the ephemeral unit converter!\n");
    printf("This program converts between distance, temperature and weight units.\n\n");

    int choice;
    float value;

    printf("Please choose the type of unit to convert:\n");
    printf("1. Distance\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");

    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {
        // Distance conversion
        printf("Please enter the distance value to convert: ");
        scanf("%f", &value);

        printf("Please choose the input unit:\n");
        printf("1. Meters\n");
        printf("2. Kilometers\n");
        printf("3. Feet\n");
        printf("4. Miles\n");

        int input_unit;
        scanf("%d", &input_unit);

        printf("Please choose the output unit:\n");
        printf("1. Meters\n");
        printf("2. Kilometers\n");
        printf("3. Feet\n");
        printf("4. Miles\n");

        int output_unit;
        scanf("%d", &output_unit);

        float result;
        switch (input_unit) {
            case 1: // Meters
                switch (output_unit) {
                    case 1: // Meters
                        result = value;
                        break;
                    case 2: // Kilometers
                        result = value / 1000.0;
                        break;
                    case 3: // Feet
                        result = value * 3.28084;
                        break;
                    case 4: // Miles
                        result = value * 0.000621371;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 2: // Kilometers
                switch (output_unit) {
                    case 1: // Meters
                        result = value * 1000.0;
                        break;
                    case 2: // Kilometers
                        result = value;
                        break;
                    case 3: // Feet
                        result = value * 3280.84;
                        break;
                    case 4: // Miles
                        result = value * 0.621371;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 3: // Feet
                switch (output_unit) {
                    case 1: // Meters
                        result = value * 0.3048;
                        break;
                    case 2: // Kilometers
                        result = value * 0.0003048;
                        break;
                    case 3: // Feet
                        result = value;
                        break;
                    case 4: // Miles
                        result = value * 0.000189394;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 4: // Miles
                switch (output_unit) {
                    case 1: // Meters
                        result = value / 0.000621371;
                        break;
                    case 2: // Kilometers
                        result = value / 0.621371;
                        break;
                    case 3: // Feet
                        result = value * 5280.0;
                        break;
                    case 4: // Miles
                        result = value;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            default:
                printf("Invalid input unit. Please try again.\n");
                return -1;
        }

        printf("\n%.2f in the input unit equals %.2f in the output unit.\n", value, result);

    } else if (choice == 2) {
        // Temperature conversion
        printf("Please enter the temperature value to convert: ");
        scanf("%f", &value);

        printf("Please choose the input unit:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");

        int input_unit;
        scanf("%d", &input_unit);

        printf("Please choose the output unit:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");

        int output_unit;
        scanf("%d", &output_unit);

        float result;
        switch (input_unit) {
            case 1: // Celsius
                switch (output_unit) {
                    case 1: // Celsius
                        result = value;
                        break;
                    case 2: // Fahrenheit
                        result = (value * 9/5) + 32;
                        break;
                    case 3: // Kelvin
                        result = value + 273.15;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 2: // Fahrenheit
                switch (output_unit) {
                    case 1: // Celsius
                        result = (value - 32) * 5/9;
                        break;
                    case 2: // Fahrenheit
                        result = value;
                        break;
                    case 3: // Kelvin
                        result = (value + 459.67) * 5/9;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 3: // Kelvin
                switch (output_unit) {
                    case 1: // Celsius
                        result = value - 273.15;
                        break;
                    case 2: // Fahrenheit
                        result = (value * 9/5) - 459.67;
                        break;
                    case 3: // Kelvin
                        result = value;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            default:
                printf("Invalid input unit. Please try again.\n");
                return -1;
        }

        printf("\n%.2f in the input unit equals %.2f in the output unit.\n", value, result);

    } else if (choice == 3) {
        // Weight conversion
        printf("Please enter the weight value to convert: ");
        scanf("%f", &value);

        printf("Please choose the input unit:\n");
        printf("1. Grams\n");
        printf("2. Kilograms\n");
        printf("3. Pounds\n");
        printf("4. Ounces\n");

        int input_unit;
        scanf("%d", &input_unit);

        printf("Please choose the output unit:\n");
        printf("1. Grams\n");
        printf("2. Kilograms\n");
        printf("3. Pounds\n");
        printf("4. Ounces\n");

        int output_unit;
        scanf("%d", &output_unit);

        float result;
        switch (input_unit) {
            case 1: // Grams
                switch (output_unit) {
                    case 1: // Grams
                        result = value;
                        break;
                    case 2: // Kilograms
                        result = value / 1000.0;
                        break;
                    case 3: // Pounds
                        result = value * 0.00220462;
                        break;
                    case 4: // Ounces
                        result = value * 0.035274;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 2: // Kilograms
                switch (output_unit) {
                    case 1: // Grams
                        result = value * 1000.0;
                        break;
                    case 2: // Kilograms
                        result = value;
                        break;
                    case 3: // Pounds
                        result = value * 2.20462;
                        break;
                    case 4: // Ounces
                        result = value * 35.274;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 3: // Pounds
                switch (output_unit) {
                    case 1: // Grams
                        result = value / 0.00220462;
                        break;
                    case 2: // Kilograms
                        result = value * 0.453592;
                        break;
                    case 3: // Pounds
                        result = value;
                        break;
                    case 4: // Ounces
                        result = value * 16.0;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            case 4: // Ounces
                switch (output_unit) {
                    case 1: // Grams
                        result = value / 0.035274;
                        break;
                    case 2: // Kilograms
                        result = value * 0.0283495;
                        break;
                    case 3: // Pounds
                        result = value * 0.0625;
                        break;
                    case 4: // Ounces
                        result = value;
                        break;
                    default:
                        printf("Invalid output unit. Please try again.\n");
                        return -1;
                }
                break;
            default:
                printf("Invalid input unit. Please try again.\n");
                return -1;
        }

        printf("\n%.2f in the input unit equals %.2f in the output unit.\n", value, result);

    } else {
        printf("Invalid choice. Please try again.\n");
        return -1;
    }

    return 0;
}