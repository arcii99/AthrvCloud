//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

int main() {
    int choice;
    float input_value, output_value;

    printf("Welcome to the Unit Converter!\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("Please choose an option: ");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &input_value);
            output_value = (input_value - 32) * 5 / 9;
            printf("%.2f°F = %.2f°C\n", input_value, output_value);
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &input_value);
            output_value = (input_value * 9 / 5) + 32;
            printf("%.2f°C = %.2f°F\n", input_value, output_value);
            break;
        case 3:
            printf("Enter the distance in Miles: ");
            scanf("%f", &input_value);
            output_value = input_value * 1.609;
            printf("%.2f miles = %.2f kilometers\n", input_value, output_value);
            break;
        case 4:
            printf("Enter the distance in Kilometers: ");
            scanf("%f", &input_value);
            output_value = input_value / 1.609;
            printf("%.2f kilometers = %.2f miles\n", input_value, output_value);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}