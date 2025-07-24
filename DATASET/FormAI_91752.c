//FormAI DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>

int main() {
    int option;
    float celsius, fahrenheit;

    printf("Welcome to the Temperature Converter!\n");
    printf("------------------------------------\n");

    do {
        printf("Choose an option:\n");
        printf("1. Convert from Celsius to Fahrenheit\n");
        printf("2. Convert from Fahrenheit to Celsius\n");
        printf("3. Exit the program\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9 / 5) + 32;
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
                break;

            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius);
                break;

            case 3:
                printf("Thank you for using the Temperature Converter!\n");
                break;

            default:
                printf("Invalid option. Please choose an option between 1-3.\n");
                break;
        }
    } while (option != 3);

    return 0;
}