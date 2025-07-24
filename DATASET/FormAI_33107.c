//FormAI DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>

float convertToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float convertToFahrenheit(float celsius) {
    return celsius * 9 / 5 + 32;
}

void printMenu(void) {
    printf("Select the unit to convert from: \n");
    printf("1. Fahrenheit\n");
    printf("2. Celsius\n");
}

void convert(float input, int choice) {
    float output;
    switch (choice) {
        case 1:
            output = convertToCelsius(input);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input, output);
            break;
        case 2:
            output = convertToFahrenheit(input);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", input, output);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    int choice;
    float input;
    printf("Welcome to the C Unit Converter!\n");
    printMenu();
    scanf("%d", &choice);
    printf("Enter the temperature to convert: ");
    scanf("%f", &input);
    convert(input, choice);
    return 0;
}