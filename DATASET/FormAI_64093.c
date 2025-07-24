//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void timeTravel(int years) {
    struct tm time_info;
    time_t current_time = time(NULL);
    localtime_r(&current_time, &time_info);
    time_info.tm_year += years;
    time_info.tm_isdst = -1;
    time_t new_time = mktime(&time_info);
    printf("You have time traveled %d year(s) into the future!\n\n", years);
    printf("The current date and time is: %s\n", asctime(localtime(&current_time)));
    printf("The date and time %d year(s) from now is: %s\n", years, asctime(localtime(&new_time)));
}

int main() {
    int years;
    char direction[10];
    printf("Welcome to the Time Travel Simulator!\n\n");
    while(1) {
        printf("Enter 'forward' to travel into the future or 'backward' to travel into the past: ");
        scanf("%s", direction);
        if(strcmp(direction, "forward") == 0) {
            printf("How many years would you like to travel into the future? ");
            scanf("%d", &years);
            timeTravel(years);
        }
        else if(strcmp(direction, "backward") == 0) {
            printf("How many years would you like to travel into the past? ");
            scanf("%d", &years);
            timeTravel(-years);
        }
        else {
            printf("Invalid direction, please try again.\n\n");
        }
    }
    return 0;
}