//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>

int main() {
    printf("Welcome to the Temperature Converter!\n");
    printf("Please input the temperature in Celsius to convert to Fahrenheit: ");
    float celsius;
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 1.8) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    // Bonus feature: convert back to Celsius
    printf("Would you like to convert %.2f Fahrenheit back to Celsius? (Y/N): ", fahrenheit);
    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        float newCelsius = (fahrenheit - 32) / 1.8;
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, newCelsius);
    } else {
        printf("Thank you for using the Temperature Converter.\n");
    }

    return 0;
}