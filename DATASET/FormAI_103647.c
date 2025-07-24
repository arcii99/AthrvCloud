//FormAI DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>

int main() {
    int choice;
    float temperature, converted;

    // Display menu
    printf("Select Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // Take input 
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        converted = (temperature * 9 / 5) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temperature, converted);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        converted = (temperature - 32) * 5 / 9;
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temperature, converted);
    } else {
        printf("Invalid Choice!\n");
    }

    return 0;
}