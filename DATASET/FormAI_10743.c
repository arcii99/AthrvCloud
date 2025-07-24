//FormAI DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

int main()
{
    int choice;
    float value;
    printf("Welcome to Unit Converter!\n");
    printf("What would you like to convert today?\n");
    printf("1. Kilometer to Meter\n");
    printf("2. Meter to Kilometer\n");
    printf("3. Kilogram to Gram\n");
    printf("4. Gram to Kilogram\n");

    printf("\nEnter your choice (1/2/3/4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the value in kilometers: ");
            scanf("%f", &value);
            printf("%.2f km = %.2f m", value, value*1000);
            break;
        case 2:
            printf("Enter the value in meters: ");
            scanf("%f", &value);
            printf("%.2f m = %.2f km", value, value/1000);
            break;
        case 3:
            printf("Enter the value in kilograms: ");
            scanf("%f", &value);
            printf("%.2f kg = %.2f g", value, value*1000);
            break;
        case 4:
            printf("Enter the value in grams: ");
            scanf("%f", &value);
            printf("%.2f g = %.2f kg", value, value/1000);
            break;
        default:
            printf("Invalid input. Please try again.");
    }

    return 0;
}