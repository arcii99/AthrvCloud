//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void timeTravel(int year)
{
    if(year == 2021) // base case when the time travel has reached present year (2021)
    {
        printf("\nCongratulations! You have successfully traveled through time and arrived at the present year: 2021.\n");
    }
    else if(year < 2021) // case when user travels back in time
    {
        printf("\nYou have traveled back in time to the year %d.\n", year);
        timeTravel(year + 1); // recursive call to time travel to the next year
    }
    else // case when user travels into the future
    {
        printf("\nYou have traveled into the future to the year %d.\n", year);
        timeTravel(year - 1); // recursive call to time travel to the previous year
    }
}

int main()
{
    int year_choice;

    printf("Welcome to the Time Travel Simulator program!\n");
    printf("You can travel back and forth through time using this program.\n\n");

    printf("Please enter the year you would like to travel to: ");
    scanf("%d", &year_choice);

    printf("\nYou have selected to time travel to the year %d.\n", year_choice);

    timeTravel(year_choice); // calling the recursive time travel function

    return 0;
}