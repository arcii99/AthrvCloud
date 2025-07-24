//FormAI DATASET v1.0 Category: Date and time ; Style: energetic
#include <stdio.h>
#include <time.h>

int main()
{
    // get current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // print date and time in a lively way
    printf("Hey there! The date today is %d/%d/%d and the time now is %d:%d:%d.\n", 
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
    printf("Isn't it amazing how time flies? Let's use it to our advantage and make the most of it!\n");
    
    // prompt user to enter a future date and time
    int year, month, day, hour, minute;
    printf("Enter a future date and time (in YYYY/MM/DD HH:MM format): ");
    scanf("%d/%d/%d %d:%d", &year, &month, &day, &hour, &minute);

    // calculate the difference between current time and future time
    struct tm future_time = {0};
    future_time.tm_year = year - 1900;
    future_time.tm_mon = month - 1;
    future_time.tm_mday = day;
    future_time.tm_hour = hour;
    future_time.tm_min = minute;
    time_t future_t = mktime(&future_time);
    double diff_seconds = difftime(future_t, t);

    // print the time remaining in an exciting way
    printf("Woohoo! Only %.0f seconds left until the specified time. Let's make them count!\n", diff_seconds);
    printf("Don't forget to live in the moment and enjoy every second of your day.\n");

    return 0;
}