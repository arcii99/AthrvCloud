//FormAI DATASET v1.0 Category: Date and time ; Style: minimalist
#include<stdio.h>
#include<time.h>

int main()
{
    time_t current_time;
    char* c_time_string;
    
    current_time = time(NULL);
    
    if(current_time == ((time_t)-1))
    {
        printf("Failed to get current time.\n");
        return 1;
    }
    
    c_time_string = ctime(&current_time);
    
    if(c_time_string == NULL)
    {
        printf("Failed to convert time.\n");
        return 1;
    }
    
    printf("Current time is %s", c_time_string);
    return 0;
}