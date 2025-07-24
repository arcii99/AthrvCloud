//FormAI DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    int choice;

    printf("Temperature Converter:\n\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) / 1.8;
            printf("\n%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", fahrenheit, celsius);
            break;
        case 2:
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 1.8) + 32;
            printf("\n%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
            break;
        default:
            printf("\nInvalid choice. Please enter either 1 or 2.\n");
    }

    return 0;
}