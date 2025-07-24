//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float c2f(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float f2c(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main() {
    int choice;
    float temperature;
    printf("Welcome to the Temperature Converter!\n");
    do {
        printf("What would you like to do?\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, c2f(temperature));
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, f2c(temperature));
                break;
            case 3:
                printf("Thank you for using the Temperature Converter!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while(choice != 3);
    return 0;
}