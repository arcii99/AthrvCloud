//FormAI DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 1.8) + 32;
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) / 1.8;
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius", fahrenheit, celsius);
            break;
        default:
            printf("Invalid option.");
            return 0;
    }

    return 0;
}