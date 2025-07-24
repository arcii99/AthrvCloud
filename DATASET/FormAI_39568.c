//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp;
    int choice;

    do {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);

        printf("1. Convert to Fahrenheit\n");
        printf("2. Convert to Kelvin\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Temperature in Fahrenheit is: %.2f\n", (temp * 1.8) + 32);
                break;
            case 2:
                printf("Temperature in Kelvin is: %.2f\n", temp + 273.15);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}