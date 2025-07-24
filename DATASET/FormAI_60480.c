//FormAI DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>

int main() {
    int choice;
    float var, convertedVar;

    printf("Welcome to the Unique C Unit Converter!\n\n");

    while (1) {
        printf("Please select an option below:\n");
        printf("1. Inches to Centimeters\n");
        printf("2. Pounds to Kilograms\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Quit\n\n");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Thank you for using the Unique C Unit Converter!\n");
            break;
        }

        printf("Please enter the value you want to convert:\n");
        scanf("%f", &var);

        switch (choice) {
            case 1:
                convertedVar = var * 2.54;
                printf("%.2f inches is equal to %.2f centimeters.\n\n", var, convertedVar);
                break;
            case 2:
                convertedVar = var * 0.453592;
                printf("%.2f pounds is equal to %.2f kilograms.\n\n", var, convertedVar);
                break;
            case 3:
                convertedVar = (var - 32) * 5 / 9;
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", var, convertedVar);
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}