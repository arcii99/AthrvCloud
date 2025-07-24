//FormAI DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>

int main() {
    int option;
    float value;
    float converted_value;

    printf("Please select the type of conversion you would like to perform.\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Miles per hour to Kilometers per hour\n");
    printf("3. Inches to Centimeters\n");

    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter the value in Celsius: ");
            scanf("%f", &value);
            converted_value = value * (9.0 / 5.0) + 32;
            printf("%.2fC is equal to %.2fF\n", value, converted_value);
            break;
        case 2:
            printf("Enter the value in Miles per hour: ");
            scanf("%f", &value);
            converted_value = value * 1.60934;
            printf("%.2f mph is equal to %.2f kph\n", value, converted_value);
            break;
        case 3:
            printf("Enter the value in Inches: ");
            scanf("%f", &value);
            converted_value = value * 2.54;
            printf("%.2f inches is equal to %.2f cm\n", value, converted_value);
            break;
        default:
            printf("Invalid option selected!\n");
            break;
    }

    return 0;
}