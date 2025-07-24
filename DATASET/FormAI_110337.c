//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
/**
 * Futuristic C Unit Converter
 * Converts between various units of measurement based on user input
 *
 * Developed by: [Your Name]
 * Date: [Enter Date Here]
 */

#include <stdio.h>

int main() {
    int option;
    float value, result;

    printf("Welcome to the Futuristic Unit Converter!\n\n");
    printf("Please select an option:\n");
    printf("1. Convert Celcius to Fahrenheit\n");
    printf("2. Convert Meters per Second to Kilometers per Hour\n");
    printf("3. Convert Kilograms to Pounds\n");
    printf("4. Convert Meters to Feet\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("\nEnter temperature in Celcius: ");
            scanf("%f", &value);
            result = (value * 1.8) + 32;
            printf("%.2f C = %.2f F\n", value, result);
            break;
        case 2:
            printf("\nEnter speed in m/s: ");
            scanf("%f", &value);
            result = value * 3.6;
            printf("%.2f m/s = %.2f km/h\n", value, result);
            break;
        case 3:
            printf("\nEnter weight in kg: ");
            scanf("%f", &value);
            result = value * 2.204623;
            printf("%.2f kg = %.2f lbs\n", value, result);
            break;
        case 4:
            printf("\nEnter length in meters: ");
            scanf("%f", &value);
            result = value * 3.28084;
            printf("%.2f m = %.2f ft\n", value, result);
            break;
        default:
            printf("\nInvalid option selected. Please try again.\n");
    }

    printf("\nThank you for using the Futuristic Unit Converter!\n");

    return 0;
}