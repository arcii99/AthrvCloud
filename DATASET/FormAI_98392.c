//FormAI DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>

int main() {
    int option;
    double value;
    printf("Welcome to Unit Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Feet to meters\n");
    printf("2. Miles to kilometers\n");
    printf("3. US gallons to liters\n");
    printf("4. Pounds to kilograms\n");
    printf("5. Fahrenheit to Celsius\n");

    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter value in feet: ");
            scanf("%lf", &value);
            printf("%.2lf feet equals %.2lf meters.\n", value, value/3.2808);
            break;
        case 2:
            printf("Enter value in miles: ");
            scanf("%lf", &value);
            printf("%.2lf miles equals %.2lf kilometers.\n", value, value*1.609);
            break;
        case 3:
            printf("Enter value in US gallons: ");
            scanf("%lf", &value);
            printf("%.2lf US gallons equals %.2lf liters.\n", value, value*3.785);
            break;
        case 4:
            printf("Enter value in pounds: ");
            scanf("%lf", &value);
            printf("%.2lf pounds equals %.2lf kilograms.\n", value, value/2.2046);
            break;
        case 5:
            printf("Enter value in Fahrenheit: ");
            scanf("%lf", &value);
            printf("%.2lf Fahrenheit equals %.2lf Celsius.\n", value, (value-32)/1.8);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}