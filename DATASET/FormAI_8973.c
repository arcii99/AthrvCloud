//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

int main() {
    float Celsius, Fahrenheit;
    int choice;

    printf("Temperature Conversion Menu: \n");
    printf("1. Celsius to Fahrenheit \n");
    printf("2. Fahrenheit to Celsius \n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &Celsius);

            Fahrenheit = (Celsius * 9/5) + 32;

            printf("%.2f degrees Celsius = %.2f degrees Fahrenheit", Celsius, Fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &Fahrenheit);

            Celsius = (Fahrenheit - 32) * 5/9;

            printf("%.2f degrees Fahrenheit = %.2f degrees Celsius", Fahrenheit, Celsius);
            break;

        default:
            printf("Invalid choice. Please enter either 1 or 2.");
            break;
    }

    return 0;
}