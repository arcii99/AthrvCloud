//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>

int main() {
    int option;
    float value;
    printf("Welcome to the C Unit Converter!\n");
    printf("Choose an option to convert:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Celsius to Fahrenheit\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Enter the value in kilometers: ");
            scanf("%f", &value);
            printf("%.2f kilometers is equal to %.2f miles\n", value, value / 1.609);
            break;
        case 2:
            printf("Enter the value in pounds: ");
            scanf("%f", &value);
            printf("%.2f pounds is equal to %.2f kilograms\n", value, value / 2.2046);
            break;
        case 3:
            printf("Enter the value in Celsius: ");
            scanf("%f", &value);
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", value, (value * 1.8) + 32);
            break;
        default:
            printf("Invalid option selected.\n");
    }
    printf("Thanks for using the C Unit Converter!\n");
    return 0;
}