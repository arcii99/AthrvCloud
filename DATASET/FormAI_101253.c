//FormAI DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>

int main() {
    int choice;
    float value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose an option from the menu below:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Kilometers to Miles\n");
    printf("3. Convert Pounds to Kilograms\n");
    printf("4. Quit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter a temperature in Celsius: ");
        scanf("%f", &value);
        result = (value * 9 / 5) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", value, result);
    }
    else if (choice == 2) {
        printf("\nEnter a distance in Kilometers: ");
        scanf("%f", &value);
        result = value * 0.621371;
        printf("%.2f Kilometers is equal to %.2f miles.", value, result);
    }
    else if (choice == 3) {
        printf("\nEnter a weight in Pounds: ");
        scanf("%f", &value);
        result = value * 0.453592;
        printf("%.2f Pounds is equal to %.2f Kilograms.", value, result);
    }
    else if (choice == 4) {
        printf("\nThank you for using the Unit Converter.\n");
        return 0;
    }
    else {
        printf("\nInvalid choice. Please try again.\n");
    }

    return 0;
}