//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>

int main() {
    int option;
    double value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    scanf("%d", &option);

    switch(option) {
        case 1: // Fahrenheit to Celsius
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &value);
            result = (value - 32) * 5 / 9;
            printf("%.2lf°F = %.2lf°C\n", value, result);
            break;
        case 2: // Celsius to Fahrenheit
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &value);
            result = value * 9 / 5 + 32;
            printf("%.2lf°C = %.2lf°F\n", value, result);
            break;
        case 3: // Pounds to Kilograms
            printf("Enter the weight in pounds: ");
            scanf("%lf", &value);
            result = value / 2.20462;
            printf("%.2lf lb = %.2lf kg\n", value, result);
            break;
        case 4: // Kilograms to Pounds
            printf("Enter the weight in kilograms: ");
            scanf("%lf", &value);
            result = value * 2.20462;
            printf("%.2lf kg = %.2lf lb\n", value, result);
            break;
        default:
            printf("Invalid option!\n");
    }

    return 0;
}