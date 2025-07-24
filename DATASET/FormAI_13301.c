//FormAI DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>

int main() {
    int choice;
    float val;

    printf("Welcome to the unit converter!\n");

    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Please enter the temperature in Celsius: ");
            scanf("%f", &val);
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", val, ((val * 9/5) + 32));
            break;
        case 2:
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%f", &val);
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", val, ((val - 32) * 5/9));
            break;
        case 3:
            printf("Please enter the distance in kilometers: ");
            scanf("%f", &val);
            printf("%.2f kilometers is %.2f miles.\n", val, (val / 1.609));
            break;
        case 4:
            printf("Please enter the distance in miles: ");
            scanf("%f", &val);
            printf("%.2f miles is %.2f kilometers.\n", val, (val * 1.609));
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}