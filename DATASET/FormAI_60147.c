//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm* current_time = localtime(&t);
    char date_string[20], time_string[20];

    // Format the date and time strings
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", current_time);
    strftime(time_string, sizeof(time_string), "%H:%M:%S", current_time);

    // Print the current date and time
    printf("Current date: %s\n", date_string);
    printf("Current time: %s\n", time_string);

    // Wait for one second
    sleep(1);

    // Update the time and format the strings again
    t = time(NULL);
    current_time = localtime(&t);
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", current_time);
    strftime(time_string, sizeof(time_string), "%H:%M:%S", current_time);

    // Print the updated date and time
    printf("Updated date: %s\n", date_string);
    printf("Updated time: %s\n", time_string);

    return 0;
}