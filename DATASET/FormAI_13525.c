//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <time.h>

int main() {
    //get current time
    time_t currentTime = time(NULL);

    //create a time structure for current time
    struct tm *currentTimeStruct = localtime(&currentTime);

    printf("Current Date and Time: %s", asctime(currentTimeStruct));

    //initialize the time machine date and time values
    struct tm timeMachineTime = {0};
    timeMachineTime.tm_year = 2000 - 1900; //year 2000
    timeMachineTime.tm_mon = 0;           //January
    timeMachineTime.tm_mday = 1;          //first day
    timeMachineTime.tm_hour = 0;          //midnight
    timeMachineTime.tm_min = 0;
    timeMachineTime.tm_sec = 0;

    //convert time machine time to seconds since epoch
    time_t timeMachineTimeSeconds = mktime(&timeMachineTime);

    //calculate time difference between current time and time machine time
    double timeDiff = difftime(currentTime, timeMachineTimeSeconds);

    //add time difference to time machine time to get calculated time
    time_t calculatedTimeSeconds = timeMachineTimeSeconds + timeDiff;

    //create a time structure for calculated time
    struct tm *calculatedTimeStruct = localtime(&calculatedTimeSeconds);

    printf("Calculated Time: %s", asctime(calculatedTimeStruct));

    return 0;
}