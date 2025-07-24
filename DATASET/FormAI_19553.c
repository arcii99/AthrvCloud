//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

int main() {
    struct tm * timeinfo;
    time_t current_time;
    char* time_string;
    
    printf("Welcome to the Time Travel Simulator!\n");

    current_time = time(NULL);
    timeinfo = localtime(&current_time);

    printf("The current date and time is: %s", asctime(timeinfo));

    int yearsToGo;

    printf("How many years into the future or past do you want to travel?\n");
    scanf("%d", &yearsToGo);

    timeinfo->tm_year += yearsToGo;
    current_time = mktime(timeinfo);
    timeinfo = localtime(&current_time);

    printf("You have arrived on: %s", asctime(timeinfo));

    return 0;
}