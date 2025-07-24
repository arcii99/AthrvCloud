//FormAI DATASET v1.0 Category: Date and time ; Style: calm
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;
    struct tm *t;
    char datetime[50];
    
    now = time(NULL);
    t = localtime(&now);
    
    strftime(datetime, 50, "%Y-%m-%d %H:%M:%S", t);
    
    printf("The current date and time is: %s\n", datetime);
    
    // Adding 6 hours to the current time
    now += (6 * 3600);
    t = localtime(&now);
    
    strftime(datetime, 50, "%Y-%m-%d %H:%M:%S", t);
    
    printf("The date and time after adding 6 hours is: %s\n", datetime);
    
    return 0;
}