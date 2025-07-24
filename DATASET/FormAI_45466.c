//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>

int main(void) {
    float celsius, fahrenheit;
    int choice;

    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("Enter your choice:\n1. Convert to Fahrenheit\n2. Convert to Kelvin\n");
    scanf("%d", &choice);

    if (choice == 1) {
        fahrenheit = celsius * 9/5 + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
    } else if (choice == 2) {
        float kelvin = celsius + 273.15;
        printf("%.2f degrees Celsius is equal to %.2f Kelvin\n", celsius, kelvin);
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}