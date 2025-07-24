//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include <time.h>
#include <stdio.h>

int main()
{
    time_t now = time(NULL); 
    
    struct tm *local_time = localtime(&now);
    
    char date[50], time[50];
    
    strftime(date, 50, "%Y-%m-%d", local_time);
    strftime(time, 50, "%H:%M:%S", local_time);
   
    printf("The current date is: %s\n", date);
    printf("The current time is: %s\n", time);

    return 0;
}