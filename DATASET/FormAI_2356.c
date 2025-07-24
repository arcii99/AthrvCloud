//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

int main() {
    float input;
    int choice;

    printf("Welcome to the Unit Converter Program!\n");

    printf("Enter the number you want to convert: ");
    scanf("%f", &input);

    printf("Here are the conversion options:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Inches to Centimeters\n");
    printf("5. Gallons to Liters\n");

    printf("Choose the conversion option (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", input, (input - 32) * 5 / 9);
            break;
        case 2:
            printf("%.2f Miles is equal to %.2f Kilometers\n", input, input * 1.609);
            break;
        case 3:
            printf("%.2f Pounds is equal to %.2f Kilograms\n", input, input * 0.4536);
            break;
        case 4:
            printf("%.2f Inches is equal to %.2f Centimeters\n", input, input * 2.54);
            break;
        case 5:
            printf("%.2f Gallons is equal to %.2f Liters\n", input, input * 3.785);
            break;
        default:
            printf("Invalid choice! Please choose from 1-5.\n");
    }

    return 0;
}