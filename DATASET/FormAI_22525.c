//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>

int main() {
    int choice;
    double value;

    printf("Welcome to the Puzzling Unit Converter! Please choose an option: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Feet to Meters\n");
    printf("4. Inches to Centimeters\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("Please enter a value in degrees Celsius: ");
            scanf("%lf", &value);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit!", value, (value * 1.8) + 32);
            break;

        case 2: 
            printf("Please enter a value in miles: ");
            scanf("%lf", &value);
            printf("%.2f miles is equal to %.2f kilometers!", value, value * 1.60934);
            break;

        case 3: 
            printf("Please enter a value in feet: ");
            scanf("%lf", &value);
            printf("%.2f feet is equal to %.2f meters!", value, value * 0.3048);
            break;

        case 4: 
            printf("Please enter a value in inches: ");
            scanf("%lf", &value);
            printf("%.2f inches is equal to %.2f centimeters!", value, value * 2.54);
            break;

        default: 
            printf("Invalid choice, please choose a valid option!");
            break;
    }

    return 0;
}