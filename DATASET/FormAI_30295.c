//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>

int main() {
    int choice;
    float value, converted;

    printf("Welcome to the unit converter!\n");
    printf("1. Distance\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("What type of conversion would you like to do? ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter distance in meters: ");
            scanf("%f", &value);
            converted = value * 3.28084;
            printf("%.2f meters is %.2f feet.\n", value, converted);
            break;
        case 2:
            printf("Enter weight in kilograms: ");
            scanf("%f", &value);
            converted = value * 2.20462;
            printf("%.2f kilograms is %.2f pounds.\n", value, converted);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            converted = value * 1.8 + 32;
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", value, converted);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}