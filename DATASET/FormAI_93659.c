//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include<stdio.h>
#include <time.h>

// This program simulates the time travel experience of a user by asking for their current date and time, 
// and then taking them to a random date and time in the past or future.

int main() {
    struct tm userTime;          // structure to hold user's current time
    struct tm travelTime;        // structure to hold time to travel to
    time_t userSecs, travelSecs; // variables to hold seconds since epoch

    // get user's current time
    printf("Please enter your current date and time (mm/dd/yyyy hh:mm:ss): ");
    scanf("%d/%d/%d %d:%d:%d", &userTime.tm_mon, &userTime.tm_mday, &userTime.tm_year, 
                                &userTime.tm_hour, &userTime.tm_min, &userTime.tm_sec);
    userTime.tm_year -= 1900;    // adjust year to be compatible with struct tm
    userTime.tm_mon--;           // adjust month to be zero-based

    // convert user's time to seconds since epoch
    userSecs = mktime(&userTime);

    // generate a random number of seconds to add to user's current time to get travel time
    srand((unsigned) time(NULL));
    int randomTime = (rand() % 31536000) - 15768000; // random time between -6 months and +6 months
    travelSecs = userSecs + randomTime;

    // convert travel time to struct tm
    travelTime = *localtime(&travelSecs);

    // print out travel information
    printf("Your current time is: %s", asctime(&userTime));
    printf("You will be traveling to: %s", asctime(&travelTime));

    return 0;
}