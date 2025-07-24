//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert meters to feet
float metersToFeet(float meters) {
    return meters * 3.28084;
}

// Function to convert feet to meters
float feetToMeters(float feet) {
    return feet / 3.28084;
}

// Function to convert kilograms to pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

// Function to convert pounds to kilograms
float poundsToKilograms(float pounds) {
    return pounds / 2.20462;
}

// Function to display menu and get user choice
int getMenuChoice() {
    int choice;
    printf("\n\nChoose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("7. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to convert units based on user choice
void convertUnits() {
    int choice;
    float input, output;
    do {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                output = celsiusToFahrenheit(input);
                printf("%.2f\xC2\xB0C = %.2f\xC2\xB0F\n", input, output);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                output = fahrenheitToCelsius(input);
                printf("%.2f\xC2\xB0F = %.2f\xC2\xB0C\n", input, output);
                break;
            case 3:
                printf("Enter distance in meters: ");
                scanf("%f", &input);
                output = metersToFeet(input);
                printf("%.2f meters = %.2f feet\n", input, output);
                break;
            case 4:
                printf("Enter distance in feet: ");
                scanf("%f", &input);
                output = feetToMeters(input);
                printf("%.2f feet = %.2f meters\n", input, output);
                break;
            case 5:
                printf("Enter weight in kilograms: ");
                scanf("%f", &input);
                output = kilogramsToPounds(input);
                printf("%.2f kg = %.2f lbs\n", input, output);
                break;
            case 6:
                printf("Enter weight in pounds: ");
                scanf("%f", &input);
                output = poundsToKilograms(input);
                printf("%.2f lbs = %.2f kg\n", input, output);
                break;
            case 7:
                printf("Thank you for using our unit converter!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);
}

int main() {
    convertUnits();
    return 0;
}