//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int currentYear, travelYear;
    char repeat;

    do
    {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Enter the current year: ");
        scanf("%d", &currentYear);

        printf("Enter the year you want to travel to: ");
        scanf("%d", &travelYear);

        if (travelYear < currentYear)
        {
            printf("Sorry, you cannot travel back in time.\n");
        }
        else if (travelYear == currentYear)
        {
            printf("You are already in %d. No need to time travel.\n", currentYear);
        }
        else
        {
            printf("Hold on tight! You are about to travel through time...\n");
            sleep(2); // Time delay for effect
            printf("You have arrived in the year %d!\n", travelYear);
            printf("Congratulations! You have successfully time traveled.\n");
        }

        printf("Would you like to time travel again? (Y/N) ");
        scanf(" %c", &repeat);

        printf("\n");

    } while (repeat == 'Y' || repeat == 'y');

    printf("Thank you for using the Time Travel Simulator. Have a great day!\n");

    return 0;
}