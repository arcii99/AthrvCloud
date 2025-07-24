//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("Welcome to the Ultimate Unit Converter! Let's get started!\n");

    int choice;
    double data;

    printf("Please select an option: \n");
    printf("1. Feet to Meters\n2. Pounds to Kilograms\n3. Gallons to Liters\n");
    printf("Enter your choice (1, 2, or 3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the length in feet: ");
            scanf("%lf", &data);
            double meters = data * 0.3048;
            printf("%.2lf feet is equal to %.2lf meters\n", data, meters);
            break;
        case 2:
            printf("Enter the weight in pounds: ");
            scanf("%lf", &data);
            double kilograms = data * 0.453592;
            printf("%.2lf pounds is equal to %.2lf kilograms\n", data, kilograms);
            break;
        case 3:
            printf("Enter the volume in gallons: ");
            scanf("%lf", &data);
            double liters = data * 3.78541;
            printf("%.2lf gallons is equal to %.2lf liters\n", data, liters);
            break;
        default:
            printf("Invalid choice. Please select either 1, 2, or 3.\n");
            break;
    }

    printf("Thanks for using the Ultimate Unit Converter!\n");

    return 0;
}