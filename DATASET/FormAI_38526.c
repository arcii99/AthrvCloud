//FormAI DATASET v1.0 Category: Date and time ; Style: complex
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    time_t current_time, start_time;
    struct tm *start_time_info, *current_time_info;
    char current_time_string[30], start_time_string[30];

    // get the current time
    time(&current_time);
    current_time_info = localtime(&current_time);
    strftime(current_time_string, sizeof(current_time_string), "%Y-%m-%d %H:%M:%S", current_time_info);
    
    // get the start time, set the seconds to 0
    start_time_info = localtime(&current_time);
    start_time_info->tm_sec = 0;
    start_time = mktime(start_time_info);
    strftime(start_time_string, sizeof(start_time_string), "%Y-%m-%d %H:%M:%S", start_time_info);

    printf("Program started at %s\n", start_time_string);

    // loop for 1 hour
    while (difftime(current_time, start_time) < 3600)
    {
        // generate a random number and print the time and number
        int rand_num = rand() % 100;
        printf("[%s]: %d\n", current_time_string, rand_num);

        // wait for 5 seconds
        sleep(5);

        // update the current time
        time(&current_time);
        current_time_info = localtime(&current_time);
        strftime(current_time_string, sizeof(current_time_string), "%Y-%m-%d %H:%M:%S", current_time_info);
    }

    printf("Program ended at %s\n", current_time_string);

    return 0;
}