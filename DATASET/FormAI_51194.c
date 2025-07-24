//FormAI DATASET v1.0 Category: Date and time ; Style: content
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[32];
    strftime(date, sizeof(date), "%B %d, %Y", t);

    char time[32];
    strftime(time, sizeof(time), "%I:%M:%S %p", t);

    printf("Current date and time: %s %s\n", date, time);

    return 0;
}