//FormAI DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>

int main() {
    int choice;
    float value, result;

    printf("Welcome to the Curious Unit Converter!\n\n");

    while (1) {
        printf("Please select a conversion option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Feet to Meters\n");
        printf("3. Pounds to Kilograms\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &value);
                result = (value - 32) * 5/9;
                printf("%.2f degrees Celsius\n", result);
                break;
            case 2:
                printf("Enter the length in feet: ");
                scanf("%f", &value);
                result = value / 3.2808;
                printf("%.2f meters\n", result);
                break;
            case 3:
                printf("Enter the weight in pounds: ");
                scanf("%f", &value);
                result = value / 2.2046;
                printf("%.2f kilograms\n", result);
                break;
            case 4:
                printf("Thank you for using the Curious Unit Converter!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n");
    }

    return 0;
}