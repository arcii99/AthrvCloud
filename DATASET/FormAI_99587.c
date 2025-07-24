//FormAI DATASET v1.0 Category: Unit converter ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int option;
    float distance, weight, temp;

    while(1)
    {
        printf("\n******* Unit Converter *******\n");
        printf("1. Convert Distance\n2. Convert Weight\n3. Convert Temperature\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: // Distance
                printf("\nEnter the distance in kilometers: ");
                scanf("%f", &distance);
                printf("Distance in meters: %.2f m\n", distance * 1000);
                printf("Distance in miles: %.2f mi\n", distance * 0.621371);
                break;

            case 2: // Weight
                printf("\nEnter the weight in kilograms: ");
                scanf("%f", &weight);
                printf("Weight in pounds: %.2f lbs\n", weight * 2.20462);
                printf("Weight in ounces: %.2f oz\n", weight * 35.274);
                break;

            case 3: // Temperature
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &temp);
                printf("Temperature in Fahrenheit: %.2f F\n", (temp * 9/5) + 32);
                printf("Temperature in Kelvin: %.2f K\n", temp + 273.15);
                break;

            case 4: // Exit
                printf("\nThank you for using Unit Converter!\n");
                exit(0);

            default: // Invalid option
                printf("\nInvalid option! Please try again.\n");
        }
    }
}