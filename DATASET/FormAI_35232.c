//FormAI DATASET v1.0 Category: Date and time ; Style: happy
#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL); // get the current time

    struct tm time = *localtime(&t); // convert the time to a struct tm object

    printf("Today is %02d/%02d/%d\n", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900); // print the current date
    printf("The time is %02d:%02d:%02d\n", time.tm_hour, time.tm_min, time.tm_sec); // print the current time

    return 0;
}