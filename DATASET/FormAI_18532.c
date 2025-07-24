//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    printf("Welcome to the Temperature Converter!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 1.8) + 32;
                printf("%.2f Celsius = %.2f Fahrenheit\n\n", celsius, fahrenheit);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) / 1.8;
                printf("%.2f Fahrenheit = %.2f Celsius\n\n", fahrenheit, celsius);
                break;

            case 3:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}