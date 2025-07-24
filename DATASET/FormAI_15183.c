//FormAI DATASET v1.0 Category: Date and time ; Style: synchronous
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[12];
    strftime(date, sizeof(date), "%d/%m/%Y", tm);
    printf("Today's date is: %s\n", date);
    char time[9];
    strftime(time, sizeof(time), "%H:%M:%S", tm);
    printf("Current time is: %s\n", time);
    int hour = tm->tm_hour;
    if (hour >= 6 && hour < 12) {
        printf("Good morning!\n");
    } else if (hour >= 12 && hour < 18) {
        printf("Good afternoon!\n");
    } else if (hour >= 18 && hour < 22) {
        printf("Good evening!\n");
    } else {
        printf("Good night!\n");
    }
    return 0;
}