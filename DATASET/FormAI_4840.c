//FormAI DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>

int main() {
    float input;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Choose an option:\n");
    printf("1. Feet to Meters\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter length in feet: ");
            scanf("%f", &input);
            printf("%.2f feet is equal to %.2f meters.\n", input, input * 0.3048);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input, (input - 32) * 5/9);
            break;
        case 3:
            printf("Enter distance in miles: ");
            scanf("%f", &input);
            printf("%.2f miles is equal to %.2f kilometers.\n", input, input * 1.60934);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}