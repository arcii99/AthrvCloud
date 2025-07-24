//FormAI DATASET v1.0 Category: Date and time ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    int day = tm->tm_mday;
    int month = tm->tm_mon + 1;
    int year = tm->tm_year + 1900;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;
    int second = tm->tm_sec;

    printf("Today is the %d%c of %s\n", day, (day % 10 == 1 && day != 11) ? 's' : (day % 10 == 2 && day != 12) ? 'n' : (day % 10 == 3 && day != 13) ? 'r' : 't', month == 1 ? "January" : month == 2 ? "February" : month == 3 ? "March" : month == 4 ? "April" : month == 5 ? "May" : month == 6 ? "June" : month == 7 ? "July" : month == 8 ? "August" : month == 9 ? "September" : month == 10 ? "October" : month == 11 ? "November" : "December");

    printf("The year is %d\n", year);

    printf("The current time is %02d:%02d:%02d\n", hour, minute, second);

    return 0;
}