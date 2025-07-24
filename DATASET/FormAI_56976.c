//FormAI DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>

/* function to convert celsius to fahrenheit */
double celsius_to_fahrenheit(double celsius){
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

/* function to convert fahrenheit to celsius */
double fahrenheit_to_celsius(double fahrenheit){
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    double temperature;
    int choice;

    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &temperature);

    printf("\n");

    printf("Enter your choice:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    if (choice == 1){
        printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
    } else if (choice == 2){
        printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", temperature, fahrenheit_to_celsius(temperature));
    } else {
        printf("Invalid choice entered\n");
    }

    return 0;
}