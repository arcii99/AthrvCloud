//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>

int main() {
    int choice;
    float celsius, fahrenheit;

    printf("\nTemperature Converter");
    printf("\n1. Celsius to Fahrenheit conversion");
    printf("\n2. Fahrenheit to Celsius conversion");
    printf("\nEnter your choice (1/2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Celsius to Fahrenheit conversion formula: F = 9/5 * C + 32 
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = 9 * celsius / 5 + 32;
            printf("\n%.2f \370C = %.2f \370F", celsius, fahrenheit);
            break;
        case 2:
            // Fahrenheit to Celsius conversion formula: C = (F - 32) * 5/9
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("\n%.2f \370F = %.2f \370C", fahrenheit, celsius);
            break;
        default:
            printf("\nInvalid choice");
    }

    return 0;
}