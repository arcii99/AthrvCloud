//FormAI DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>

int main() {
    int choice;
    double value1, value2, result;
    printf("Welcome to the Unit Converter!\n");
    printf("Please select the conversion you would like to do:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Miles to Kilometers\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &value1);
            result = (value1 * 9 / 5) + 32;
            printf("%.2lf degrees Celsius equals %.2lf degrees Fahrenheit.\n", value1, result);
            break;
        case 2:
            printf("Enter the length in inches: ");
            scanf("%lf", &value1);
            result = value1 * 2.54;
            printf("%.2lf inches equals %.2lf centimeters.\n", value1, result);
            break;
        case 3:
            printf("Enter the distance in miles: ");
            scanf("%lf", &value1);
            result = value1 * 1.60934;
            printf("%.2lf miles equals %.2lf kilometers.\n", value1, result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}