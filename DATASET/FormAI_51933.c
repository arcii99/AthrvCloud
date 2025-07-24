//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>

int main() {
    float input, output;
    int option;
    printf("Enter the value to be converted:\n");
    scanf("%f", &input);
    printf("Choose the option for conversion:\n");
    printf("1 - Celsius to Fahrenheit.\n2 - Fahrenheit to Celsius.\n3 - Miles to Kilometers.\n4 - Kilometers to Miles.\n5 - Inches to Centimeters.\n6 - Centimeters to Inches.\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            output = (input * 9 / 5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, output);
            break;
        case 2:
            output = (input - 32) * 5 / 9;
            printf("%.2f Fahrenheit = %.2f Celsius\n", input, output);
            break;
        case 3:
            output = input * 1.60934;
            printf("%.2f Miles = %.2f Kilometers\n", input, output);
            break;
        case 4:
            output = input / 1.60934;
            printf("%.2f Kilometers = %.2f Miles\n", input, output);
            break;
        case 5:
            output = input * 2.54;
            printf("%.2f Inches = %.2f Centimeters\n", input, output);
            break;
        case 6:
            output = input / 2.54;
            printf("%.2f Centimeters = %.2f Inches\n", input, output);
            break;
        default:
            printf("Invalid option selected, try again.\n");
    }
    return 0;
}