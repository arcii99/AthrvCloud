//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

int main() {
    int choice;
    float input;
    float output;

    printf("Welcome to Grateful Unit Converter!\n");
    printf("Please select the unit conversion you would like to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = (input * 9/5) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input, output);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) * 5/9;
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input, output);
            break;
        case 3:
            printf("Enter length in meters: ");
            scanf("%f", &input);
            output = input * 3.28;
            printf("%.2f meters is equal to %.2f feet.\n", input, output);
            break;
        case 4:
            printf("Enter length in feet: ");
            scanf("%f", &input);
            output = input / 3.28;
            printf("%.2f feet is equal to %.2f meters.\n", input, output);
            break;
        case 5:
            printf("Enter weight in kilograms: ");
            scanf("%f", &input);
            output = input * 2.205;
            printf("%.2f kilograms is equal to %.2f pounds.\n", input, output);
            break;
        case 6:
            printf("Enter weight in pounds: ");
            scanf("%f", &input);
            output = input / 2.205;
            printf("%.2f pounds is equal to %.2f kilograms.\n", input, output);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}