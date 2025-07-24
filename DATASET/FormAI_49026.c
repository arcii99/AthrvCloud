//FormAI DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include<stdio.h>

int main()
{
    float km, mile;
    int choice;
    printf("1. Convert kilometers to miles\n");
    printf("2. Convert miles to kilometers\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter distance in kilometers: ");
            scanf("%f", &km);
            mile = km * 0.621371;
            printf("%.2f km is equal to %.2f miles", km, mile);
            break;

        case 2:
            printf("Enter distance in miles: ");
            scanf("%f", &mile);
            km = mile / 0.621371;
            printf("%.2f miles is equal to %.2f km", mile, km);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}