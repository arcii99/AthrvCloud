//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include<stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    printf("Welcome to Celsius-Fahrenheit Temperature Converter!");

    do {
        printf("\n\nChoose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 1.8) + 32;
                printf("Temperature in Fahrenheit: %.2f°F", fahrenheit);
                break;
            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) / 1.8;
                printf("Temperature in Celsius: %.2f°C", celsius);
                break;
            case 3:
                printf("\nExiting program. Goodbye!");
                break;
            default:
                printf("\nInvalid choice. Try again.");
        }
    } while (choice != 3);

    return 0;
}