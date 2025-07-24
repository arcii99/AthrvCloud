//FormAI DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float);
float fahrenheit_to_celsius(float);

// Main function
int main() {
    int choice;
    float temp;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            printf("%.2f°C = %.2f°F", temp, celsius_to_fahrenheit(temp));
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            printf("%.2f°F = %.2f°C", temp, fahrenheit_to_celsius(temp));
            break;

        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = ((9 * celsius) / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (5 * (fahrenheit - 32)) / 9;
    return celsius;
}