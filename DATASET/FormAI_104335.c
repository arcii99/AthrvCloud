//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    time_t currentTime;  // variable to hold the current time
    struct tm* dateTime; // structure to hold the broken down date and time values

    // get the current time and store it in the time_t variable
    time(&currentTime);

    // print out the current time in string format
    printf("Current time: %s", ctime(&currentTime));

    // get the broken down date and time values from the time_t variable
    dateTime = localtime(&currentTime);
 
    // adjust the year to travel back to 1912
    dateTime->tm_year = 12;  // 1912 is 1900 + 12
    dateTime->tm_mon = 3;    // April
    dateTime->tm_mday = 14;  // 14th day

    // set the time to the exact moment the RMS Titanic hit the iceberg
    dateTime->tm_hour = 23;
    dateTime->tm_min = 40;
    dateTime->tm_sec = 0;

    // convert the broken down date and time values back into a time_t variable
    time_t titanicsCollision = mktime(dateTime);

    // print out the time of the Titanic's collision with the iceberg
    printf("The RMS Titanic hit an iceberg on %s", ctime(&titanicsCollision));

    // calculate the number of seconds from 1912 to the current time
    long secondsSince1912 = difftime(currentTime, titanicsCollision);

    // print out the number of seconds
    printf("It has been %ld seconds since the sinking of the Titanic.", secondsSince1912);

    return 0;
}