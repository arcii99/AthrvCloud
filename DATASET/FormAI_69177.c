//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>

int main()
{
    time_t present_time;
    struct tm *ptr_now;

    // Obtain the current time
    time(&present_time);    
    ptr_now = localtime(&present_time);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("The current date and time is: %02d/%02d/%d %02d:%02d:%02d\n", ptr_now->tm_mday, ptr_now->tm_mon+1, ptr_now->tm_year+1900, ptr_now->tm_hour, ptr_now->tm_min, ptr_now->tm_sec);
    printf("Enter the number of years to travel back in time: ");

    int years_to_travel;
    scanf("%d", &years_to_travel);

    // Calculate the travel back time
    int seconds_in_year = 31536000; // 60 seconds * 60 minutes * 24 hours * 365 days
    time_t travel_time = present_time - (years_to_travel * seconds_in_year);
    ptr_now = localtime(&travel_time);

    printf("\nTraveling back %d years...\n", years_to_travel);
    printf("You have arrived on: %02d/%02d/%d %02d:%02d:%02d\n", ptr_now->tm_mday, ptr_now->tm_mon+1, ptr_now->tm_year+1900, ptr_now->tm_hour, ptr_now->tm_min, ptr_now->tm_sec);

    return 0;
}