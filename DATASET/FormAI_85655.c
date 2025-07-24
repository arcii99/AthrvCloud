//FormAI DATASET v1.0 Category: Date and time ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int hour = tm.tm_hour;
    int minute = tm.tm_min;
    int second = tm.tm_sec;
    int day = tm.tm_mday;
    int month = tm.tm_mon + 1;
    int year = tm.tm_year + 1900;

    printf("Current date and time is: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    int n = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int future_hour = (hour + n) % 24;
    int future_day = day + n / 24;
    int future_month = month;
    int future_year = year;

    if (future_day > 31) {
        future_day -= 31;
        future_month++;
    }
    if (future_month > 12) {
        future_month -= 12;
        future_year++;
    }

    printf("After %d hours, the date and time will be: %d-%02d-%02d %02d:%02d:%02d\n", n, future_year, future_month, future_day, future_hour, minute, second);

    return 0;
}