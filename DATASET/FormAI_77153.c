//FormAI DATASET v1.0 Category: Date and time ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    // Get the current time
    time_t now = time(NULL);
    
    // Convert it to a struct tm for displaying the date and time
    struct tm *t = localtime(&now);
    
    // Display the date and time in a human-readable form
    printf("Current date and time: %s", asctime(t));
    
    // Extract individual components of the date and time
    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int minute = t->tm_min;
    int second = t->tm_sec;
    
    // Display the individual components
    printf("Year: %d\n", year);
    printf("Month: %d\n", month);
    printf("Day: %d\n", day);
    printf("Hour: %d\n", hour);
    printf("Minute: %d\n", minute);
    printf("Second: %d\n", second);
    
    return 0;
}