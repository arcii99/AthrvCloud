//FormAI DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>

int main() 
{
    int choice;
    float distance;

    printf("Welcome to the Distance Converter!\n");
    printf("Enter 1 to convert miles to kilometers.\n");
    printf("Enter 2 to convert kilometers to miles.\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter distance in miles: ");
            scanf("%f", &distance);
            printf("%.2f miles = %.2f kilometers", distance, distance * 1.609);
            break;

        case 2:
            printf("Enter distance in kilometers: ");
            scanf("%f", &distance);
            printf("%.2f kilometers = %.2f miles", distance, distance / 1.609);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}