//FormAI DATASET v1.0 Category: Date and time ; Style: energetic
#include <stdio.h>
#include <time.h>

int main()
{
    time_t rawtime, newtime;
    struct tm * timeinfo;
    char buffer[80];

    time ( &rawtime );

    /* Get the time in the UTC/GMT timezone */
    timeinfo = gmtime ( &rawtime );

    /* Format the time */
    strftime (buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
    printf("UTC/GMT time: %s\n", buffer);

    /* Convert to local timezone */
    newtime = rawtime + (5 * 3600); // Change 5 to your local timezone offset
    timeinfo = localtime(&newtime);

    /* Format the time */
    strftime (buffer,80,"%Y-%m-%d %I:%M:%S %p",timeinfo);
    printf("Local time: %s\n", buffer);

    return 0;
}