//FormAI DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>

int main() {
    int choice;
    double value, result;
    printf("Welcome to the Statistical Unit Converter!\n\n");
    printf("Please select an option from the menu:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Inches to Centimeters\n");
    printf("3. Convert Pounds to Kilograms\n");
    printf("4. Exit Program\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nCelsius to Fahrenheit Conversion\n");
            printf("Enter a temperature in Celsius: ");
            scanf("%lf", &value);
            result = (value * 9 / 5) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", value, result);
            break;
        case 2:
            printf("\nInches to Centimeters Conversion\n");
            printf("Enter a length in inches: ");
            scanf("%lf", &value);
            result = value * 2.54;
            printf("%.2f inches is equal to %.2f centimeters.\n", value, result);
            break;
        case 3:
            printf("\nPounds to Kilograms Conversion\n");
            printf("Enter a weight in pounds: ");
            scanf("%lf", &value);
            result = value * 0.45;
            printf("%.2f pounds is equal to %.2f kilograms.\n", value, result);
            break;
        case 4:
            printf("\nExiting program...");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
    return 0;
}