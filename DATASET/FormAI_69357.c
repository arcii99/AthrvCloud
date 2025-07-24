//FormAI DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>

int main() {
    float temperature, fahrenheit, celsius;
    char choice;

    printf("Enter temperature in °F or °C: ");
    scanf("%f%c", &temperature, &choice);

    if (choice == 'f' || choice == 'F') {
        fahrenheit = temperature;
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("\n%.1f°F is equivalent to %.1f°C\n", fahrenheit, celsius);
    } else if (choice == 'c' || choice == 'C') {
        celsius = temperature;
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("\n%.1f°C is equivalent to %.1f°F\n", celsius, fahrenheit);
    } else {
        printf("\nInvalid choice, please enter either 'F' or 'C'\n");
    }

    return 0;
}