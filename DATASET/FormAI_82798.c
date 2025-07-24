//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

int main() {
    float tempCelsius, tempFahrenheit;
    int choice;

    printf("Temperature Converter\n");
    printf("=====================\n");

    printf("Select an option:\n");
    printf("1. Convert from Celsius to Fahrenheit\n");
    printf("2. Convert from Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &tempCelsius);

        tempFahrenheit = (tempCelsius * 9 / 5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit", tempCelsius, tempFahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &tempFahrenheit);

        tempCelsius = (tempFahrenheit - 32) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Celsius", tempFahrenheit, tempCelsius);
    } else {
        printf("Invalid choice");
    }

    return 0;
}