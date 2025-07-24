//FormAI DATASET v1.0 Category: Date and time ; Style: expert-level
#include <stdio.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm *current_time_info;
    char time_string[50];

    time(&current_time);
    current_time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "Today is %A, %B %d, %Y. The time is %I:%M %p.", current_time_info);
    printf("%s\n", time_string);

    return 0;
}