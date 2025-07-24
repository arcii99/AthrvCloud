//FormAI DATASET v1.0 Category: Date and time ; Style: introspective
/* This is a C program that demonstrates how to obtain the current date and time using the time() function.
   It also shows different ways to format the date and time data using strftime(). */

#include <stdio.h>
#include <time.h>

int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    // get current date/time using time() function
    time(&rawtime);
    // convert to struct tm format
    timeinfo = localtime(&rawtime);

    // display the date and time in different formats using strftime()
    strftime(buffer, 80, "Today is %a, %d %b %Y.\n", timeinfo);
    printf("%s", buffer);

    strftime(buffer, 80, "The time is %I:%M%p.\n", timeinfo);
    printf("%s", buffer);

    strftime(buffer, 80, "The year is %Y.\n", timeinfo);
    printf("%s", buffer);

    strftime(buffer, 80, "The month is %B.\n", timeinfo);
    printf("%s", buffer);

    strftime(buffer, 80, "The day is %d.\n", timeinfo);
    printf("%s", buffer);

    strftime(buffer, 80, "The hour is %I %p.\n", timeinfo);
    printf("%s", buffer);

    //format for HTTP date/time string
    strftime(buffer, 80, "Date: %a, %d %b %Y %H:%M:%S GMT\n", timeinfo);
    printf("%s", buffer);

    return 0;
}