//FormAI DATASET v1.0 Category: Date and time ; Style: shocked
#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    if (current_time == NULL) {
        printf("Oops! Failed to get the current time and date :(\n");
        return 1;
    }
    char date_str[20];
    char time_str[20];
    if (strftime(date_str, sizeof(date_str), "%d-%m-%Y", current_time) == 0) {
        printf("Oops! Failed to format the date :(\n");
        return 1;
    }
    if (strftime(time_str, sizeof(time_str), "%I:%M %p", current_time) == 0) {
        printf("Oops! Failed to format the time :(\n");
        return 1;
    }
    printf("The current date is %s\n", date_str);
    printf("The current time is %s\n", time_str);
    return 0;
}