//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t rawtime;
    struct tm * timeinfo; 
    char timeString[100];
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timeString, sizeof(timeString), "%d %B %Y %I:%M:%S %p", timeinfo);
    printf("The current date and time is: %s\n", timeString);
    
    return 0;
}