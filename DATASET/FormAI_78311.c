//FormAI DATASET v1.0 Category: Date and time ; Style: peaceful
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time and date
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);

    // Display peaceful message
    printf("Today is a peaceful day.\n");
    printf("The current time is %02d:%02d:%02d\n", current_time->tm_hour,
                                                   current_time->tm_min, 
                                                   current_time->tm_sec);
    printf("The date is %02d/%02d/%04d\n", current_time->tm_mday, 
                                            current_time->tm_mon + 1,
                                            current_time->tm_year + 1900);

    return 0;
}