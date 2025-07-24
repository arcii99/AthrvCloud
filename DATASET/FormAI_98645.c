//FormAI DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>

int main() {
    float temp_celsius, temp_fahrenheit;
    int choice;

    printf("Temperature Converter\n");
    printf("======================\n\n");
    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Celsius to Fahrenheit\n");
        printf("======================\n\n");
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp_celsius);

        temp_fahrenheit = (temp_celsius * 9/5) + 32;

        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp_celsius, temp_fahrenheit);
    }
    else if (choice == 2) {
        printf("Fahrenheit to Celsius\n");
        printf("======================\n\n");
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temp_fahrenheit);

        temp_celsius = (temp_fahrenheit - 32) * 5/9;

        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp_fahrenheit, temp_celsius);
    }
    else {
        printf("Invalid choice. Please choose again.\n");
    }

    return 0;
}