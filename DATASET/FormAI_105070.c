//FormAI DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, value;
    printf("Welcome to the Unit Converter!\n");
    printf("Please select your conversion type:\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Kilograms to Pounds\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("Enter the value in meters: ");
            scanf("%d", &value);
            printf("%d meters is equal to %.2f feet.\n", value, value * 3.28084);
            break;
        case 2:
            printf("Enter the value in kilometers: ");
            scanf("%d", &value);
            printf("%d kilometers is equal to %.2f miles.\n", value, value * 0.621371);
            break;
        case 3:
            printf("Enter the value in Celsius: ");
            scanf("%d", &value);
            printf("%d Celsius is equal to %.2f Fahrenheit.\n", value, (value * 1.8) + 32);
            break;
        case 4:
            printf("Enter the value in kilograms: ");
            scanf("%d", &value);
            printf("%d kilograms is equal to %.2f pounds.\n", value, value * 2.20462);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}