//FormAI DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

int main() {
    int option;
    float value, convertedValue;

    printf("Welcome to Minimalist Unit Converter\n");
    printf("------------------------------------\n");

    printf("Select an option:\n");
    printf("1. Meter to Feet\n");
    printf("2. Celsius to Fahrenheit\n");

    scanf("%d", &option);

    printf("Enter a value to convert: ");
    scanf("%f", &value);

    switch(option) {
        case 1: {
            convertedValue = value * 3.281; // 1 meter = 3.281 feet
            printf("%.2f meters is equal to %.2f feet\n", value, convertedValue);
            break;
        }

        case 2: {
            convertedValue = (value * 9/5) + 32; // Celsius to Fahrenheit formula
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", value, convertedValue);
            break;
        }

        default: {
            printf("Invalid option selected!\n");
            break;
        }
    }

    return 0;
}