//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

int main() {
    int menu_choice;
    float value, converted_value;

    printf("Welcome to the Unit Converter!\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Feet to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &menu_choice);

    switch(menu_choice) {
        case 1:
            printf("Enter value in inches: ");
            scanf("%f", &value);
            converted_value = value * 2.54;
            printf("%.2f inches is equal to %.2f centimeters.\n", value, converted_value);
            break;
        case 2:
            printf("Enter value in feet: ");
            scanf("%f", &value);
            converted_value = value * 0.3048;
            printf("%.2f feet is equal to %.2f meters.\n", value, converted_value);
            break;
        case 3:
            printf("Enter value in miles: ");
            scanf("%f", &value);
            converted_value = value * 1.60934;
            printf("%.2f miles is equal to %.2f kilometers.\n", value, converted_value);
            break;
        case 4:
            printf("Enter value in pounds: ");
            scanf("%f", &value);
            converted_value = value * 0.453592;
            printf("%.2f pounds is equal to %.2f kilograms.\n", value, converted_value);
            break;
        case 5:
            printf("Enter value in Fahrenheit: ");
            scanf("%f", &value);
            converted_value = (value - 32) / 1.8;
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", value, converted_value);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}