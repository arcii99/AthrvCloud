//FormAI DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>

int main() {
    float input;
    int choice;

    printf("Peaceful Unit Converter\n");

    printf("What would you like to convert?\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Feet to Meters\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the number of miles: ");
            scanf("%f", &input);
            printf("%.2f miles is equal to %.2f kilometers\n", input, input * 1.609);
            break;
        case 2:
            printf("Enter the number of pounds: ");
            scanf("%f", &input);
            printf("%.2f pounds is equal to %.2f kilograms\n", input, input * 0.453592);
            break;
        case 3:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &input);
            printf("%.1f degrees Fahrenheit is equal to %.1f degrees Celsius\n", input, (input - 32) * 5/9);
            break;
        case 4:
            printf("Enter the number of feet: ");
            scanf("%f", &input);
            printf("%.2f feet is equal to %.2f meters\n", input, input * 0.3048);
            break;
        default:
            printf("Invalid choice, please try again\n");
            break;
    }

    return 0;
}