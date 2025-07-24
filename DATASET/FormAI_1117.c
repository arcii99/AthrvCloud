//FormAI DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>

int main() {
    int option;
    float value;

    printf("Welcome to the unit converter!\n");
    printf("Enter the corresponding number to select an option:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter value in kilometers: ");
            scanf("%f", &value);
            printf("%.2f kilometers = %.2f miles\n", value, value * 0.621371);
            break;
        case 2:
            printf("Enter value in miles: ");
            scanf("%f", &value);
            printf("%.2f miles = %.2f kilometers\n", value, value * 1.60934);
            break;
        case 3:
            printf("Enter value in Celsius: ");
            scanf("%f", &value);
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 1.8) + 32);
            break;
        case 4:
            printf("Enter value in Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) / 1.8);
            break;
        default:
            printf("Invalid option selected!\n");
            break;
    }

    return 0;
}