//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>

int main() {
    int select;
    float from_val, to_val;

    printf("Retro Unit Converter\n");

    while (1) {
        printf("Select conversion:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Miles to Kilometers\n");
        printf("3. Pounds to Kilograms\n");
        scanf("%d", &select);

        switch (select) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &from_val);
                to_val = (from_val - 32) * (5.0 / 9.0);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n\n", from_val, to_val);
                break;
            case 2:
                printf("Enter distance in Miles: ");
                scanf("%f", &from_val);
                to_val = from_val * 1.60934;
                printf("%.2f Miles is equal to %.2f Kilometers\n\n", from_val, to_val);
                break;
            case 3:
                printf("Enter weight in Pounds: ");
                scanf("%f", &from_val);
                to_val = from_val * 0.453592;
                printf("%.2f Pounds is equal to %.2f Kilograms\n\n", from_val, to_val);
                break;
            default:
                printf("Invalid selection. Try again.\n\n");
                break;
        }
    }

    return 0;
}