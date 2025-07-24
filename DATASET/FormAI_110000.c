//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

int main() {
    printf("\n\n\t\t C UNIT CONVERTER \n");
    printf("\t\t ----------------- \n\n");

    int option;
    float value;

    printf("1. Convert Celsius to Fahrenheit \n");
    printf("2. Convert Fahrenheit to Celsius \n");
    printf("3. Convert Kilometers to Miles \n");
    printf("4. Convert Miles to Kilometers \n");

    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            printf("%.2f Celsius is equal to %.2f Fahrenheit. \n", value, (value * 9 / 5) + 32);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f Fahrenheit is equal to %.2f Celsius. \n", value, (value - 32) * 5 / 9);
            break;
        case 3:
            printf("Enter distance in Kilometers: ");
            scanf("%f", &value);
            printf("%.2f Kilometers is equal to %.2f Miles. \n", value, value / 1.609);
            break;
        case 4:
            printf("Enter distance in Miles: ");
            scanf("%f", &value);
            printf("%.2f Miles is equal to %.2f Kilometers. \n", value, value * 1.609);
            break;
        default:
            printf("Invalid option. Please select a valid option. \n");
            break;
    }

    return 0;
}