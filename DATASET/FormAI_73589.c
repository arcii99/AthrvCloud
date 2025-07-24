//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>

double convertToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convertToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    double input, output;
    int choice;

    printf("Welcome to Unit Converter:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("Please choose an option: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: ;
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            output = convertToCelsius(input);
            printf("%.2lfF is %.2lfC\n", input, output);
            break;
        case 2: ;
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            output = convertToFahrenheit(input);
            printf("%.2lfC is %.2lfF\n", input, output);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}