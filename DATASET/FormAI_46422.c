//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>

/* Shape Shifting C Unit Converter */

int main() {
    char option;

    printf("Welcome to the Shape Shifting C Unit Converter!\n");
    printf("Which type of unit conversion would you like to perform?\n");
    printf("a) Length\nb) Temperature\nc) Weight\nd) Quit\n");

    scanf(" %c", &option);

    while (option != 'd') {

        switch(option) {
            case 'a':
                length();
                break;
            case 'b':
                temperature();
                break;
            case 'c':
                weight();
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }

        printf("\nWhich type of unit conversion would you like to perform?\n");
        printf("a) Length\nb) Temperature\nc) Weight\nd) Quit\n");

        scanf(" %c", &option);
    }

    printf("Thank you for using the Shape Shifting C Unit Converter!\n");

    return 0;
}

void length() {
    float input, output;
    char option;

    printf("You have selected Length conversion.\n");
    printf("Which conversion do you wish to perform?\n");
    printf("a) Kilometers to Miles\nb) Miles to Kilometers\n");

    scanf(" %c", &option);

    switch(option) {
        case 'a':
            printf("Enter length in kilometers: ");
            scanf("%f", &input);

            output = input * 0.621371;
            printf("%.2f kilometers is equal to %.2f miles.\n", input, output);
            break;
        case 'b':
            printf("Enter length in miles: ");
            scanf("%f", &input);

            output = input * 1.60934;
            printf("%.2f miles is equal to %.2f kilometers.\n", input, output);
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }
}

void temperature() {
    float input, output;
    char option;

    printf("You have selected Temperature conversion.\n");
    printf("Which conversion do you wish to perform?\n");
    printf("a) Celsius to Fahrenheit\nb) Fahrenheit to Celsius\n");

    scanf(" %c", &option);

    switch(option) {
        case 'a':
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);

            output = (input * 1.8) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", input, output);
            break;
        case 'b':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);

            output = (input - 32) / 1.8;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input, output);
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }
}

void weight() {
    float input, output;
    char option;

    printf("You have selected Weight conversion.\n");
    printf("Which conversion do you wish to perform?\n");
    printf("a) Kilograms to Pounds\nb) Pounds to Kilograms\n");

    scanf(" %c", &option);

    switch(option) {
        case 'a':
            printf("Enter weight in kilograms: ");
            scanf("%f", &input);

            output = input * 2.20462;
            printf("%.2f kilograms is equal to %.2f pounds.\n", input, output);
            break;
        case 'b':
            printf("Enter weight in pounds: ");
            scanf("%f", &input);

            output = input * 0.453592;
            printf("%.2f pounds is equal to %.2f kilograms.\n", input, output);
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }
}