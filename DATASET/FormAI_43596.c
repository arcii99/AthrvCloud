//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    char time_string[20];
    int year;

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%Y", time_info);
    year = atoi(time_string);

    printf("Welcome to the Time Travel Simulator!\n");

    printf("Enter a year to travel to (1000 - %d): ", year);
    int target_year;
    scanf("%d", &target_year);

    if(target_year < 1000 || target_year > year) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("You have successfully traveled to the year %d!\n", target_year);

    return 0;
}