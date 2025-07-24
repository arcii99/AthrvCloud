//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
#include <stdio.h>

void main() {
    float temperature, celsius, fahrenheit;
    int choice;

    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        fahrenheit = (temperature * 9 / 5) + 32;
        printf("%.2fC is equal to %.2fF", temperature, fahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        celsius = (temperature - 32) * 5 / 9;
        printf("%.2fF is equal to %.2fC", temperature, celsius);
    } else {
        printf("Invalid choice!");
    }
}