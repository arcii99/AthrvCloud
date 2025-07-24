//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentTime = time(NULL);
    struct tm *timeStruct = localtime(&currentTime);

    printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d\n",
            timeStruct->tm_year + 1900, timeStruct->tm_mon + 1, timeStruct->tm_mday,
            timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec);

    int choice;
    printf("Enter a year to travel back in time: ");
    scanf("%d", &choice);

    if (choice > timeStruct->tm_year + 1900)
    {
        printf("Sorry, time travel to the future is not possible at the moment.\n");
    }
    else
    {
        time_t timeTravel = mktime(timeStruct);
        timeTravel -= ((timeStruct->tm_year + 1900) - choice) * 31536000L;
        timeStruct = localtime(&timeTravel);

        printf("You have successfully traveled back to: %d-%02d-%02d %02d:%02d:%02d\n",
                timeStruct->tm_year + 1900, timeStruct->tm_mon + 1, timeStruct->tm_mday,
                timeStruct->tm_hour, timeStruct->tm_min, timeStruct->tm_sec);
    }

    return 0;
}