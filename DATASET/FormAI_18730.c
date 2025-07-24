//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

int main() {
    int choice;
    float value, convertedValue;

    printf("**********Unit Converter**********\n");
    printf("1. Meter to Centimeter\n");
    printf("2. Centimeter to Meter\n");
    printf("3. Kilometer to Meter\n");
    printf("4. Meter to Kilometer\n");
    printf("5. Fahrenheit to Celsius\n");
    printf("6. Celsius to Fahrenheit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter Value in Meter: ");
            scanf("%f", &value);
            convertedValue = value * 100;
            printf("%.2f Meter = %.2f Centimeter", value, convertedValue);
            break;
        case 2:
            printf("Enter Value in Centimeter: ");
            scanf("%f", &value);
            convertedValue = value / 100;
            printf("%.2f Centimeter = %.2f Meter", value, convertedValue);
            break;
        case 3:
            printf("Enter Value in Kilometer: ");
            scanf("%f", &value);
            convertedValue = value * 1000;
            printf("%.2f Kilometer = %.2f Meter", value, convertedValue);
            break;
        case 4:
            printf("Enter Value in Meter: ");
            scanf("%f", &value);
            convertedValue = value / 1000;
            printf("%.2f Meter = %.2f Kilometer", value, convertedValue);
            break;
        case 5:
            printf("Enter Temperature in Fahrenheit: ");
            scanf("%f", &value);
            convertedValue = (value - 32) * 5 / 9;
            printf("%.2f Fahrenheit = %.2f Celsius", value, convertedValue);
            break;
        case 6:
            printf("Enter Temperature in Celsius: ");
            scanf("%f", &value);
            convertedValue = (value * 9 / 5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit", value, convertedValue);
            break;
        default:
            printf("Invalid Choice. Please Choose a Valid Option.");
            break;
    }

    return 0;
}