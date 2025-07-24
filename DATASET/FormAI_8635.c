//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>

int main() {
    int choice;
    float temp, convertedTemp;
    printf("Welcome to the Temperature Converter\n");
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: // Celsius to Fahrenheit conversion
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            convertedTemp = (temp * 9 / 5) + 32;
            printf("%.2f°C is %.2f°F\n", temp, convertedTemp);
            break;
        case 2: // Fahrenheit to Celsius conversion
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            convertedTemp = (temp - 32) * 5 / 9;
            printf("%.2f°F is %.2f°C\n", temp, convertedTemp);
            break;
        default:
            printf("Invalid choice, please try again.\n");
    }
    return 0;
}