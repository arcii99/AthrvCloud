//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include<stdio.h>
#include<time.h>

int main(){
    time_t current_time;
    struct tm * time_info;
    char time_string[9];
    int year, month, day, hour, minute, second;
    long int seconds;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("Enter the hour: ");
    scanf("%d", &hour);
    printf("Enter the minute: ");
    scanf("%d", &minute);
    printf("Enter the second: ");
    scanf("%d", &second);
    //Converting date to seconds from 1970
    struct tm current = {0,0,0,day,month-1,year-1900};
    seconds = mktime(&current);
    //Adding time difference to seconds
    seconds += ((hour*60)+minute)*60+second;
    printf("Time entered is: %02d-%02d-%d %02d:%02d:%02d \n",day,month,year,hour,minute,second);
    printf("The time in seconds from Jan, 1970 is : %ld \n", seconds);
    //Converting seconds to date
    time_info = localtime(&seconds);
    strftime(time_string, sizeof(time_string), "%d-%m-%Y %H:%M:%S", time_info);
    printf("The date and time after time travel is: %s\n", time_string);
    return 0;
}