//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ada Lovelace
/*
 * Program: Temperature Converter
 * Author: Ada Lovelace
 * Date: 10/01/2021
 * Description: This program converts temperature from Celsius to Fahrenheit and vice versa.
 */

#include <stdio.h>

int main() {
    int choice;
    float temperature, convertedTemp;

    printf("Welcome to Temperature Converter\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemp = (temperature * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit", temperature, convertedTemp);
    }
    else if (choice == 2) {
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemp = (temperature - 32) * 5/9;
        printf("%.2f Fahrenheit = %.2f Celsius", temperature, convertedTemp);
    }
    else {
        printf("\nInvalid choice!");
    }

    return 0;
}