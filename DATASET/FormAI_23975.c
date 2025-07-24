//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>

int main()
{
    int choice;
    double value;

    printf("\nWelcome to medieval unit converter\n");
    printf("1. Feet to Meters\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            printf("Thank you for using medieval unit converter\n");
            break;
        }

        printf("Enter the value to be converted: ");
        scanf("%lf", &value);

        switch (choice)
        {
        case 1:
            printf("%.2lf feet is equal to %.2lf meters.\n", value, (value * 0.3048));
            break;

        case 2:
            printf("%.2lf pounds is equal to %.2lf kilograms.\n", value, (value * 0.453592));
            break;

        case 3:
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", value, ((value - 32) * 5 / 9));
            break;

        default:
            printf("Invalid choice. Please enter a valid choice.\n");
            break;
        }
    }

    return 0;
}