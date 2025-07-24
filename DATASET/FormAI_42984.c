//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime = time(NULL); // Gets the current time as a time_t variable
    struct tm *currentDate = localtime(&currentTime); // Gets the current date as a struct tm pointer

    printf("Welcome to the Time Travel Simulator\n\n");
    printf("Today's date is %02d/%02d/%d\n\n", currentDate->tm_mday, currentDate->tm_mon + 1, currentDate->tm_year + 1900);

    printf("Enter the number of years you want to travel (positive for future, negative for past): ");
    int travelYears;
    scanf("%d", &travelYears);

    printf("Enter the number of months you want to travel (positive for future, negative for past): ");
    int travelMonths;
    scanf("%d", &travelMonths);

    printf("Enter the number of days you want to travel (positive for future, negative for past): ");
    int travelDays;
    scanf("%d", &travelDays);

    time_t newTime = currentTime + (travelYears * 31536000) + (travelMonths * 2592000) + (travelDays * 86400); // Calculates the new time based on the input

    struct tm *newDate = localtime(&newTime); // Converts the new time back into a struct tm pointer

    printf("\nYou have travelled to the date: %02d/%02d/%d\n", newDate->tm_mday, newDate->tm_mon + 1, newDate->tm_year + 1900);

    if(difftime(newTime, currentTime) > 0)
    {
        printf("You have travelled %ld seconds into the future\n", (long)difftime(newTime, currentTime));
    }
    else
    {
        printf("You have travelled %ld seconds into the past\n", (long)difftime(currentTime, newTime));
    }

    return 0;
}