//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>

float celcius_to_fahrenheit(float celcius);
float fahrenheit_to_celcius(float fahrenheit);

int main() {
    int option;
    float temperature;

    printf("Welcome to the temperature converter\n");
    printf("Choose conversion option: \n");
    printf("1. Celcius to Fahrenheit\n");
    printf("2. Fahrenheit to Celcius\n");
    printf("Enter your option: ");

    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter temperature in Celcius: ");
            scanf("%f", &temperature);
            printf("%.2f Celcius is %.2f Fahrenheit\n", temperature, celcius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit is %.2f Celcius\n", temperature, fahrenheit_to_celcius(temperature));
            break;
        default:
            printf("Invalid option selected\n");
            break;
    }

    return 0;
}

float celcius_to_fahrenheit(float celcius) {
    return (celcius * 9/5) + 32;
}

float fahrenheit_to_celcius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}