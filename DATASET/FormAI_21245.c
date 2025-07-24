//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    int choice = 0;
    float input;
    float output;

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("What would you like to convert?\n");
        printf("1. Miles to Kilometers\n");
        printf("2. Kilometers to Miles\n");
        printf("3. Pounds to Kilograms\n");
        printf("4. Kilograms to Pounds\n");
        printf("5. Inches to Centimeters\n");
        printf("6. Centimeters to Inches\n");
        printf("7. Quit\n");
        printf("> ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Miles to Kilometers
                printf("Enter the number of miles: ");
                scanf("%f", &input);
                output = input * 1.609344;
                printf("%.2f miles is %.2f kilometers.\n", input, output);
                break;

            case 2: // Kilometers to Miles
                printf("Enter the number of kilometers: ");
                scanf("%f", &input);
                output = input * 0.621371;
                printf("%.2f kilometers is %.2f miles.\n", input, output);
                break;

            case 3: // Pounds to Kilograms
                printf("Enter the number of pounds: ");
                scanf("%f", &input);
                output = input * 0.453592;
                printf("%.2f pounds is %.2f kilograms.\n", input, output);
                break;

            case 4: // Kilograms to Pounds
                printf("Enter the number of kilograms: ");
                scanf("%f", &input);
                output = input * 2.20462;
                printf("%.2f kilograms is %.2f pounds.\n", input, output);
                break;

            case 5: // Inches to Centimeters
                printf("Enter the number of inches: ");
                scanf("%f", &input);
                output = input * 2.54;
                printf("%.2f inches is %.2f centimeters.\n", input, output);
                break;

            case 6: // Centimeters to Inches
                printf("Enter the number of centimeters: ");
                scanf("%f", &input);
                output = input * 0.393701;
                printf("%.2f centimeters is %.2f inches.\n", input, output);
                break;

            case 7: // Quit
                printf("Thanks for using the Unit Converter!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}