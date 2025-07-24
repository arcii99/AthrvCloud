//FormAI DATASET v1.0 Category: Date and time ; Style: happy
#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);    
    char date[50];
    char time[50];
    
    strftime(date, sizeof(date), "%A, %B %d, %Y", tm);
    strftime(time, sizeof(time), "%I:%M:%S %p", tm);
    
    printf("Hello there! Today's date is %s.\n", date);
    printf("The current time is %s.\n", time);
    printf("Isn't it a beautiful day?\n");
    
    return 0;
}