//FormAI DATASET v1.0 Category: Date and time ; Style: excited
#include <stdio.h>
#include <time.h>

int main()
{
    // Declare variables to hold date/time information
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [20];

    // Get the current time and date
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    // Format the date/time output and store it in buffer
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

    // Display the date/time output to the user
    printf("The current date and time is: %s\n", buffer);

    return 0;
}