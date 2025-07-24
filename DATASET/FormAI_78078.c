//FormAI DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>

int main() {
    // Declare variables
    float celsius, fahrenheit;
    int choice;

    // Display menu options
    printf("========MENU========\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("====================\n");

    // Ask for user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // For Celsius to Fahrenheit conversion
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9 / 5) + 32;
            printf("%.1f Celsius = %.1f Fahrenheit\n", celsius, fahrenheit);
            break;

        case 2:
            // For Fahrenheit to Celsius conversion
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.1f Fahrenheit = %.1f Celsius\n", fahrenheit, celsius);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}