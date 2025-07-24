//FormAI DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initialize variables
    float input;
    int choice_one, choice_two;
    const float inches_to_cm = 2.54;
    const float feet_to_cm = 30.48;
    const float yards_to_cm = 91.44;
    const float miles_to_km = 1.60934;

    // Display menu of measurements to convert
    printf("===================\n");
    printf("Unit Converter Menu:\n");
    printf("===================\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Feet to Centimeters\n");
    printf("3. Yards to Centimeters\n");
    printf("4. Miles to Kilometers\n\n");

    // Prompt user for first conversion choice
    printf("Enter conversion choice 1: ");
    scanf("%d", &choice_one);

    // Prompt user for second conversion choice
    printf("Enter conversion choice 2: ");
    scanf("%d", &choice_two);

    // Verify that both choices are valid
    if ((choice_one < 1 || choice_one > 4) || (choice_two < 1 || choice_two > 4)) {
        printf("Invalid conversion choices.\n");
        return 0;
    }

    // Prompt user for input value
    printf("Enter value to convert: ");
    scanf("%f", &input);

    // Convert input value based on user's choices
    switch (choice_one) {
        case 1:
            input *= inches_to_cm;
            break;
        case 2:
            input *= feet_to_cm;
            break;
        case 3:
            input *= yards_to_cm;
            break;
        case 4:
            input *= miles_to_km;
            break;
    }

    switch (choice_two) {
        case 1:
            input /= inches_to_cm;
            break;
        case 2:
            input /= feet_to_cm;
            break;
        case 3:
            input /= yards_to_cm;
            break;
        case 4:
            input /= miles_to_km;
            break;
    }

    // Print out results
    printf("===================\n");
    printf("Conversion Results:\n");
    printf("===================\n");

    switch (choice_one) {
        case 1:
            printf("%.2f inches is equal to ", input);
            break;
        case 2:
            printf("%.2f feet is equal to ", input);
            break;
        case 3:
            printf("%.2f yards is equal to ", input);
            break;
        case 4:
            printf("%.2f miles is equal to ", input);
            break;
    }

    switch (choice_two) {
        case 1:
            printf("%.2f centimeters\n", input);
            break;
        case 2:
            printf("%.2f centimeters\n", input);
            break;
        case 3:
            printf("%.2f centimeters\n", input);
            break;
        case 4:
            printf("%.2f kilometers\n", input);
            break;
    }

    return 0;
}