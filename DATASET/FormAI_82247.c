//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    time_t currentTime = time(NULL);
    struct tm pastTime = {0};

    //setting the year 2050
    pastTime.tm_year = 150;

    //setting the month to February
    pastTime.tm_mon = 1;

    //setting the day to 10th
    pastTime.tm_mday = 10;

    //setting the hour to 12 pm
    pastTime.tm_hour = 12;

    //setting the minute to 0
    pastTime.tm_min = 0;

    //setting the second to 0
    pastTime.tm_sec = 0;

    //converting the time to a time_t value
    time_t pastTime_t = mktime(&pastTime);

    //calculating the difference between current time and past time
    double secondsDiff = difftime(currentTime, pastTime_t);

    printf("Welcome to CyberTime Travel Simulator.\n");

    if (currentTime < pastTime_t){
        printf("You are traveling back in time!\n");
    }else{
        printf("You are traveling into the future!\n");
    }

    printf("Accelerating the Quantum Drive Engine...\n");
    printf("Calculating time warp stability factor...\n");
    printf("Preparing for temporal shift...\n");
    printf("Initiating the Time Warp sequence:\n");

    for (int i = 0; i < 10; i++){

        //simulate the time warp
        printf("%d%%\n", (i+1)*10);
        sleep(1);
    }

    printf("Time Warp sequence complete.\n");

    if (currentTime < pastTime_t){
        printf("You have arrived in the year 2050, February 10th at 12 pm.\n");
    }else{
        printf("You have arrived in the year 2020, June 27th at 1 pm.\n");
    }

    printf("The difference between your departure time and arrival time was %.0f seconds.\n", secondsDiff);

    return 0;
}