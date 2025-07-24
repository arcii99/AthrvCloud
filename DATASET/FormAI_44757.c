//FormAI DATASET v1.0 Category: Date and time ; Style: enthusiastic
#include <stdio.h>
#include <time.h>

int main()
{
    // Get the current time
    time_t now = time(NULL);
 
    // Convert it to a local time struct
    struct tm *local_time = localtime(&now);
 
    // Output the date and time in a friendly format
    printf("Today is %02d/%02d/%04d\n",
           local_time->tm_mon + 1,
           local_time->tm_mday,
           local_time->tm_year + 1900);
 
    printf("The current time is %02d:%02d:%02d\n",
           local_time->tm_hour,
           local_time->tm_min,
           local_time->tm_sec);
 
    // Wait for a few seconds
    sleep(3);
 
    // Get the current time again
    time_t now_again = time(NULL);
 
    // Calculate the time elapsed since the last time we checked
    int elapsed = now_again - now;
 
    printf("It has been %d seconds since we last checked the time.\n", elapsed);
 
    return 0;
}