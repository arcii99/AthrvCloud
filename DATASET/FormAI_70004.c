//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int year, current_year, age;
    time_t current_time;
    struct tm *current_tm;

    time(&current_time);
    current_tm = localtime(&current_time);

    current_year = current_tm->tm_year + 1900;
    age = rand() % 50 + 20;

    printf("Welcome to the Time Travel Simulator Program!\n\n");

    printf("Enter year to time travel to (1900 - %d): ", current_year);
    scanf("%d", &year);

    if (year < 1900 || year > current_year)
    {
        printf("Invalid year entered!\n");
        return 0;
    }

    printf("\n\nWoohoo! Time travel successful!\n");

    printf("You are now in the year %d\n", year);

    if (year < current_year)
    {
        printf("You are %d years old in this year\n", age + (current_year - year));
    }
    else if (year > current_year)
    {
        printf("You are only %d years old in this year\n", age - (year - current_year));
    }
    else
    {
        printf("You are currently %d years old\n", age);
    }

    printf("\n\nThank you for using the Time Travel Simulator Program!\n");

    return 0;
}