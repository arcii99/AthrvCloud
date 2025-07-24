//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include<stdio.h>

int main() {
    float fahrenheit, celsius;
    int choice;

    printf("Temperature Converter - C to F and F to C\n");
    printf("Enter 1 to convert from Celsius to Fahrenheit\n");
    printf("Enter 2 to convert from Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 9/5) + 32;
        printf("Temperature in Fahrenheit: %.2f F\n", fahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) * 5/9;
        printf("Temperature in Celsius: %.2f C\n", celsius);
    } else {
        printf("Invalid input. Please enter 1 or 2\n");
    }

    return 0;
}