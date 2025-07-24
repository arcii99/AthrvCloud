//FormAI DATASET v1.0 Category: Date and time ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time = time(NULL);
    struct tm *tm_time = localtime(&current_time);
    char date[20];
    char time[20];
    strftime(date, sizeof(date), "%d-%m-%Y", tm_time);
    strftime(time, sizeof(time), "%H:%M:%S", tm_time);
    printf("Today's date is %s\n", date);
    printf("Current time is %s\n", time);
    return 0;
}