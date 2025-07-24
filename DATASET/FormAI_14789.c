//FormAI DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>

int main() {
    int choice;
    float value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Feet to Meters\n");
    printf("2. Gallons to Liters\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Inches to Centimeters\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter value in feet: ");
            scanf("%f", &value);
            printf("%.2f feet is equal to %.2f meters\n", value, value / 3.2808);
            break;
        case 2:
            printf("Enter value in gallons: ");
            scanf("%f", &value);
            printf("%.2f gallons is equal to %.2f liters\n", value, value * 3.7854);
            break;
        case 3:
            printf("Enter value in pounds: ");
            scanf("%f", &value);
            printf("%.2f pounds is equal to %.2f kilograms\n", value, value / 2.2046);
            break;
        case 4:
            printf("Enter value in inches: ");
            scanf("%f", &value);
            printf("%.2f inches is equal to %.2f centimeters\n", value, value * 2.54);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}