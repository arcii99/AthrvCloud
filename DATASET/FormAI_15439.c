//FormAI DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

int main() {
    int choice;
    float value;

    printf("Welcome to the visionary unit converter!\n");
    printf("Please select the type of unit you would like to convert:\n");
    printf("1. Distance\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Please enter the distance in miles: ");
            scanf("%f", &value);
            printf("%.2f miles is equal to %.2f kilometers.\n", value, value * 1.60934);
            break;
        case 2:
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f F is equal to %.2f C.\n", value, (value - 32) * 5 / 9);
            break;
        case 3:
            printf("Please enter the weight in pounds: ");
            scanf("%f", &value);
            printf("%.2f pounds is equal to %.2f kilograms.\n", value, value * 0.453592);
            break;
        default:
            printf("Invalid choice.");
    }

    return 0;
}