//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Initializing variables
    int year, month, day;
    time_t current_time = time(NULL);
    struct tm *tm_ptr = localtime(&current_time);

    //Getting current date
    year = tm_ptr->tm_year + 1900;
    month = tm_ptr->tm_mon + 1;
    day = tm_ptr->tm_mday;

    //Printing current date
    printf("Current date: %d/%d/%d\n", day, month, year);

    //Simulating time travel
    printf("Enter number of years to travel: ");
    int years_to_travel;
    scanf("%d", &years_to_travel);

    //Calculating new date after time travel
    year += years_to_travel;
    if (year < 0) {
        printf("Sorry, you cannot travel back in time before year 0.");
        return 0;
    }

    //Printing new date after time travel
    printf("New date after time travel: %d/%d/%d\n", day, month, year);

    return 0;
}