//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Kilometers to Miles
float kilometers_to_miles(float kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Miles to Kilometers
float miles_to_kilometers(float miles) {
    return miles * 1.60934;
}

int main() {
    int choice;
    float value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kilometers to Miles\n");
    printf("4. Convert Miles to Kilometers\n");
    printf("5. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &value);
                result = celsius_to_fahrenheit(value);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n\n", value, result);
                break;

            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &value);
                result = fahrenheit_to_celsius(value);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n\n", value, result);
                break;

            case 3:
                printf("Enter the distance in Kilometers: ");
                scanf("%f", &value);
                result = kilometers_to_miles(value);
                printf("%.2f Kilometers is equal to %.2f Miles.\n\n", value, result);
                break;

            case 4:
                printf("Enter the distance in Miles: ");
                scanf("%f", &value);
                result = miles_to_kilometers(value);
                printf("%.2f Miles is equal to %.2f Kilometers.\n\n", value, result);
                break;

            case 5:
                printf("Thank you for using the Unit Converter!\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n\n");
        }
    } while (choice != 5);

    return 0;
}