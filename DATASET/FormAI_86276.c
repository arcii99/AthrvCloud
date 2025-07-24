//FormAI DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    printf("Would you like to convert this temperature into Kelvin? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        float kelvin = celsius + 273.15;
        printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
    }

    printf("Thank you for using this temperature converter!\n");

    return 0;
}