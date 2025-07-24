//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    time_t current_time, target_time, time_diff;
    struct tm *current_tm, *target_tm;

    //Set the current time to the current system time
    current_time = time(NULL);
    current_tm = localtime(&current_time);

    //Set the target time to 100 years from the current time
    target_tm = localtime(&current_time);
    target_tm->tm_year += 100;
    target_time = mktime(target_tm);

    //Calculate the time difference between the current time and the target time
    time_diff = difftime(target_time, current_time);

    //Output the current time and the target time
    printf("Current time: %s", asctime(current_tm));
    printf("Target time: %s", asctime(target_tm));

    //Output the time difference in years, months, and days
    printf("Time difference: %d years, %d months, %d days\n",
           (int)(time_diff / (60 * 60 * 24 * 365)),
           (int)(((time_diff / (60 * 60 * 24 * 365.25)) - (int)(time_diff / (60 * 60 * 24 * 365))) * 12),
           (int)(time_diff / (60 * 60 * 24)) % 365);

    //Output the time difference in hours, minutes, and seconds
    printf("Time difference: %d hours, %d minutes, %d seconds\n",
           (int)(time_diff / (60 * 60)),
           (int)(time_diff / 60) % 60,
           (int)time_diff % 60);

    return 0;
}