//FormAI DATASET v1.0 Category: Date and time ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    time_t current_time;
    struct tm * time_info;
    char timeString[9]; // space for "HH:MM:SS\0"
 
    time(&current_time);
    time_info = localtime(&current_time);
 
    strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

    printf("Today's date and Current time: %s\t", asctime(time_info));
    printf("The time is %s\n", timeString);
   
    return 0;
}