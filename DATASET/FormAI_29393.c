//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int currentDate, currentTime, futureDate, futureTime;
    time_t t = time(NULL); // get current calendar time
    struct tm *tm = localtime(&t); // convert it into local time structure
 
    // print current date and time
    printf("Current Date and Time: %02d/%02d/%d %02d:%02d:%02d\n",
           tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900,
           tm->tm_hour, tm->tm_min, tm->tm_sec);
 
    // get input from user for future date and time
    printf("\nEnter Future Date and Time (DD/MM/YYYY HH:MM:SS): ");
    scanf("%d/%d/%d %d:%d:%d", &futureDate, &futureTime);
 
    // calculate difference between current and future date and time
    int dateDiff = futureDate - tm->tm_mday;
    int monthDiff = tm->tm_mon+1 - tm->tm_mon+1;
    int yearDiff = tm->tm_year+1900 - tm->tm_year+1900;
    int hourDiff = futureTime - tm->tm_hour;
    int minDiff = futureTime - tm->tm_min;
    int secDiff = futureTime - tm->tm_sec;
 
    // print time travel information
    printf("\nTime Travel Information:\n\n");
    printf("> Date difference: %d days\n", dateDiff);
    printf("> Month difference: %d months\n", monthDiff);
    printf("> Year difference: %d years\n", yearDiff);
    printf("> Hour difference: %d hours\n", hourDiff);
    printf("> Minute difference: %d minutes\n", minDiff);
    printf("> Second difference: %d seconds\n", secDiff);
 
    return 0;
}