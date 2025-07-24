//FormAI DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celcius to Fahrenheit
double celciusToFahrenheit(double celcius) {
    return (celcius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celcius
double fahrenheitToCelcius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Kilometers to Miles
double kilometersToMiles(double kilometers) {
    return kilometers / 1.609;
}

// Function to convert Miles to Kilometers
double milesToKilometers(double miles) {
    return miles * 1.609;
}

int main() {
    int choice;
    double value;
    
    printf("Welcome to the Unit Converter!\n\n");
    
    do {
        printf("Please choose an option:\n");
        printf("1. Convert Celcius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celcius\n");
        printf("3. Convert Kilometers to Miles\n");
        printf("4. Convert Miles to Kilometers\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Thank you for using the Unit Converter!\n");
                break;
            case 1:
                printf("Enter a value in Celcius: ");
                scanf("%lf", &value);
                printf("%.2lf Celcius is %.2lf Fahrenheit\n\n", value, celciusToFahrenheit(value));
                break;
            case 2:
                printf("Enter a value in Fahrenheit: ");
                scanf("%lf", &value);
                printf("%.2lf Fahrenheit is %.2lf Celcius\n\n", value, fahrenheitToCelcius(value));
                break;
            case 3:
                printf("Enter a value in Kilometers: ");
                scanf("%lf", &value);
                printf("%.2lf Kilometers is %.2lf Miles\n\n", value, kilometersToMiles(value));
                break;
            case 4:
                printf("Enter a value in Miles: ");
                scanf("%lf", &value);
                printf("%.2lf Miles is %.2lf Kilometers\n\n", value, milesToKilometers(value));
                break;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
        
    } while (choice != 0);

    return 0;
}