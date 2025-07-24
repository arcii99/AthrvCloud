//FormAI DATASET v1.0 Category: Date and time ; Style: content
#include <stdio.h>
#include <time.h>

int main(){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    char date[50], time[50];
    strftime(date, sizeof(date), "%A, %B %d, %Y", tm);
    strftime(time, sizeof(time), "%I:%M:%S %p", tm);
    
    printf("Today's date is: %s\n", date);
    printf("The current time is: %s\n", time);
    
    return 0;
}

/*
Output:
Today's date is: Tuesday, August 31, 2021
The current time is: 06:18:23 PM
*/