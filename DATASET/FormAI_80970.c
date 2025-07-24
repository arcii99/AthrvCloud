//FormAI DATASET v1.0 Category: Date and time ; Style: satisfied
#include <stdio.h>
#include <time.h>

int main() {
    // declare necessary variables
    struct tm tm;
    char buffer[80];

    // get current time
    time_t t = time(NULL);
    localtime_r(&t, &tm);
    
    // format and store time in buffer
    strftime(buffer, sizeof(buffer), "%c", &tm);

    // print formatted time
    printf("Current date and time: %s\n", buffer);

    // add 90 minutes
    tm.tm_min += 90;
    mktime(&tm);

    // format and store new time in buffer
    strftime(buffer, sizeof(buffer), "%c", &tm);

    // print new time
    printf("Date and time in 90 minutes: %s\n", buffer);

    return 0;
}