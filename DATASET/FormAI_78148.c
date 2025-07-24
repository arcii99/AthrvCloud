//FormAI DATASET v1.0 Category: Unit converter ; Style: genious
#include <stdio.h>

int main() {
    int choice;
    float value, result;

    printf("***Welcome to Genius Unit Converter***\n");

    do {
        printf("\nPlease select the conversion type:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Meter to Feet\n");
        printf("4. Feet to Meter\n");
        printf("5. Kilogram to Pound\n");
        printf("6. Pound to Kilogram\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &value);
                result = (value * 9/5) + 32;
                printf("%.2f C = %.2f F\n", value, result);
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &value);
                result = (value - 32) * 5/9;
                printf("%.2f F = %.2f C\n", value, result);
                break;
            case 3:
                printf("Enter the length in meters: ");
                scanf("%f", &value);
                result = value * 3.281;
                printf("%.2f meters = %.2f feet\n", value, result);
                break;
            case 4:
                printf("Enter the length in feet: ");
                scanf("%f", &value);
                result = value * 0.305;
                printf("%.2f feet = %.2f meters\n", value, result);
                break;
            case 5:
                printf("Enter the weight in kilograms: ");
                scanf("%f", &value);
                result = value * 2.205;
                printf("%.2f kilograms = %.2f pounds\n", value, result);
                break;
            case 6:
                printf("Enter the weight in pounds: ");
                scanf("%f", &value);
                result = value * 0.454;
                printf("%.2f pounds = %.2f kilograms\n", value, result);
                break;
            case 7:
                printf("Thank you for using Genius Unit Converter!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 7);

    return 0;
}