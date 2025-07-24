//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

int main() {

    float fahrenheit, celsius;
    int option;
    printf("Welcome to C Temperature Converter:\n");
    printf("Select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", fahrenheit, celsius);
            break;

        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9 / 5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", celsius, fahrenheit);
            break;

        default:
            printf("Invalid option.");
    }

    return 0;
}