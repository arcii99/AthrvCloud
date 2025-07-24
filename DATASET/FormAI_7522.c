//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void time_travel(int choice);

int main(void) {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please select a year to travel to:\n");
    printf("1. 1970\n2. 1990\n3. 2000\n4. 2010\n");
    int choice;
    scanf("%d", &choice);
    time_travel(choice);
    return 0;
}

void time_travel(int choice) {
    time_t current_time;
    struct tm *current_tm;
    char formatted_time[50];

    time(&current_time);
    current_tm = localtime(&current_time);

    switch(choice) {
        case 1:
            current_tm->tm_year = 70;
            break;
        case 2:
            current_tm->tm_year = 90;
            break;
        case 3:
            current_tm->tm_year = 100;
            break;
        case 4:
            current_tm->tm_year = 110;
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    current_time = mktime(current_tm);

    strftime(formatted_time, 50, "%c", localtime(&current_time));

    printf("You have traveled to %s.\n", formatted_time);
}