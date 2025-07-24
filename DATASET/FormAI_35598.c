//FormAI DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>

int main() {
    float input, output;
    int option;

    printf("Welcome to the Scientific Unit Converter\n");

    // Menu options for conversion
    printf("Select your conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = (input * 1.8) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, output);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) / 1.8;
            printf("%.2f Fahrenheit = %.2f Celsius\n", input, output);
            break;
        case 3:
            printf("Enter length in meters: ");
            scanf("%f", &input);
            output = input * 3.28084;
            printf("%.2f Meters = %.2f Feet\n", input, output);
            break;
        case 4:
            printf("Enter length in feet: ");
            scanf("%f", &input);
            output = input / 3.28084;
            printf("%.2f Feet = %.2f Meters\n", input, output);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}