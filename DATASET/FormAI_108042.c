//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // initiliaze varibles
    int year, month, day, hour, minute, second, choice, travelYear, travelMonth, travelDay, travelHour, travelMinute, travelSecond;
    time_t t = time(NULL);
    struct tm time = *localtime(&t);

    // display current time
    printf("Current time is: %02d/%02d/%d %02d:%02d:%02d\n", time.tm_mday, time.tm_mon + 1, time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);

    // get user input for travel date
    printf("\nEnter travel date and time in the format: DD/MM/YYYY HH:MM:SS\n");
    scanf("%d/%d/%d %d:%d:%d", &travelDay, &travelMonth, &travelYear, &travelHour, &travelMinute, &travelSecond);

    // calculate time difference in seconds
    long timeDiff = ((travelYear - 1900) * 31536000) + ((travelMonth - 1) * 2592000) + ((travelDay - 1) * 86400) + (travelHour * 3600) + (travelMinute * 60) + travelSecond - ((time.tm_year - 70) * 31536000) - (time.tm_yday * 86400) - (time.tm_hour * 3600) - (time.tm_min * 60) - time.tm_sec;

    // check if time difference is positive
    if (timeDiff < 0) {
        printf("\nYou cannot travel back in time!\n");
        return 0;
    }

    // display time difference in seconds
    printf("\nThe time difference between current time and travel date is %ld seconds.\n", timeDiff);

    // ask user if they want to proceed with time travel
    printf("\nDo you want to proceed with time travel? (1 = yes, 0 = no)\n");
    scanf("%d", &choice);

    // check user input
    if (choice != 1) {
        printf("\nTime travel cancelled!\n");
        return 0;
    }

    // set system time
    time.tm_sec += timeDiff;
    mktime(&time);
    printf("\nTime travel successful! The new time is: %02d/%02d/%d %02d:%02d:%02d\n", time.tm_mday, time.tm_mon + 1, time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    return 0;
}