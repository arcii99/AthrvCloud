//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the temperature converter!\n");
    float celsius, fahrenheit;
    int choice;

    do {
        printf("\nEnter 1 to convert Celsius to Fahrenheit\n");
        printf("Enter 2 to convert Fahrenheit to Celsius\n");
        printf("Enter 0 to exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &celsius);

                fahrenheit = (celsius * 9/5) + 32;

                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
                break;

            case 2:
                printf("\nEnter the temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);

                celsius = (fahrenheit - 32) * 5/9;

                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius);
                break;

            case 0:
                printf("\nThank you for using the temperature converter!\n");
                break;

            default:
                printf("\nInvalid input, please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}