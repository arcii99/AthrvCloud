//FormAI DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the ultimate unit converter program!\n");
    printf("This program can convert from Celsius to Fahrenheit, Kilometers per hour to Miles per hour and many other units.\n");
    printf("Enter the number corresponding to the unit conversion you want to perform: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Kilometers per hour to Miles per hour\n");
    int choice;
    scanf("%d", &choice);
    float result;
    
    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Celsius: \n");
            float celsius;
            scanf("%f", &celsius);
            result = (celsius * 9 / 5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, result);
            break;
        case 2:
            printf("Enter the speed in Kilometers per hour: \n");
            float kmph;
            scanf("%f", &kmph);
            result = kmph / 1.609;
            printf("%.2f kilometers per hour is equal to %.2f miles per hour.\n", kmph, result);
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
    
    printf("Thank you for using the ultimate unit converter program! Come back again soon!");
    return 0;
}