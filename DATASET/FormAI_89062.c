//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <time.h>

int main() {
    time_t present_time = time(NULL); // get current time in seconds
    struct tm *tm_pointer = localtime(&present_time); // convert to struct tm

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("The current time is %02d:%02d:%02d on %02d/%02d/%d.\n\n", tm_pointer->tm_hour, tm_pointer->tm_min, tm_pointer->tm_sec, tm_pointer->tm_mday, tm_pointer->tm_mon+1, tm_pointer->tm_year+1900);

    int year, month, day, hour, minute, second;
    
    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);
    printf("Enter the month (1-12) you want to travel to: ");
    scanf("%d", &month);
    printf("Enter the day (1-31) you want to travel to: ");
    scanf("%d", &day);
    printf("Enter the hour (0-23) you want to travel to: ");
    scanf("%d", &hour);
    printf("Enter the minute (0-59) you want to travel to: ");
    scanf("%d", &minute);
    printf("Enter the second (0-59) you want to travel to: ");
    scanf("%d", &second);

    // calculate time difference
    struct tm travel_time = { second, minute, hour, day, month-1, year-1900 }; // convert to struct tm
    time_t target_time = mktime(&travel_time); // convert to time_t
    
    double diff_seconds = difftime(target_time, present_time);
    int diff_years = (int)(diff_seconds/(365.25*24*60*60));
    diff_seconds -= diff_years*365.25*24*60*60;
    int diff_days = (int)(diff_seconds/(24*60*60));
    diff_seconds -= diff_days*24*60*60;
    int diff_hours = (int)(diff_seconds/(60*60));
    diff_seconds -= diff_hours*60*60;
    int diff_minutes = (int)(diff_seconds/60);
    diff_seconds -= diff_minutes*60;

    printf("\nYou will be traveling ");
    if (diff_years) printf("%d years, ", diff_years);
    if (diff_days) printf("%d days, ", diff_days);
    printf("%02d:%02d:%02d", diff_hours, diff_minutes, (int)diff_seconds);
    if (diff_years <= 0 && diff_days <= 0 && diff_hours <= 0 && diff_minutes <= 0 && diff_seconds <= 0) printf(" into the past.\n");
    else printf(" into the future.\n");

    return 0;
}