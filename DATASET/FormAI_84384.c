//FormAI DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

int main() {
    int choice;
    float value;

    printf("Welcome to the Unit Converter!\n");
    printf("1. Feet to Meters\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Gallons to Liters\n");
    printf("Please choose an option (1-4): ");

    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    switch(choice) {
        case 1:
            printf("%.2f feet is equal to %.2f meters\n", value, value * 0.3048);
            break;
        case 2:
            printf("%.2f pounds is equal to %.2f kilograms\n", value, value * 0.453592);
            break;
        case 3:
            printf("%.2f miles is equal to %.2f kilometers\n", value, value * 1.60934);
            break;
        case 4:
            printf("%.2f gallons is equal to %.2f liters\n", value, value * 3.78541);
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}