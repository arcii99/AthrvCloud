//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    printf("Welcome to the Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Please enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
            break;
        default:
            printf("Invalid choice, please enter 1 or 2\n");
            break;
    }

    return 0;
}