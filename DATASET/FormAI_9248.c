//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    printf("Welcome to the Temperature Converter\n");
    printf("-----------------------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 1.8) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) / 1.8;
            printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
            break;
        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
    }

    return 0;
}