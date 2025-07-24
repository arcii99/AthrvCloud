//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>

float celsiusToFahrenheit(float C) {
    return (C * (9.0/5.0)) + 32;
}

float fahrenheitToCelsius(float F) {
    return (F - 32) * (5.0/9.0);
}

int main() {
    int choice;
    float temperature, converted;

    printf("Temperature Converter\n");
    printf("====================\n");

    do {
        printf("\n1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temperature);
                converted = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, converted);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, converted);
                break;

            case 3:
                printf("\nThank you for using the Temperature Converter\n");
                break;

            default:
                printf("\nInvalid choice, please try again\n");
                break;
        }
    } while (choice != 3);

    return 0;
}