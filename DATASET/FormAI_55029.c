//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm* current_time = localtime(&t);
    
    printf("Welcome to the time travel simulator! Let's go back in time...\n\n");

    int years_back, months_back, days_back, hours_back, minutes_back;
    printf("How many years do you want to go back? ");
    scanf("%d", &years_back);
    printf("How many months do you want to go back? ");
    scanf("%d", &months_back);
    printf("How many days do you want to go back? ");
    scanf("%d", &days_back);
    printf("How many hours do you want to go back? ");
    scanf("%d", &hours_back);
    printf("How many minutes do you want to go back? ");
    scanf("%d", &minutes_back);

    struct tm travel_time = *current_time;
    travel_time.tm_year -= years_back;
    travel_time.tm_mon -= months_back;
    travel_time.tm_mday -= days_back;
    travel_time.tm_hour -= hours_back;
    travel_time.tm_min -= minutes_back;
    travel_time.tm_sec = 0;

    time_t travel_time_t = mktime(&travel_time);
    
    printf("\nTraveling to %s", asctime(&travel_time));
    printf("3... 2... 1...\n\n");
    sleep(1);

    while (t > travel_time_t) {
        t -= 60;
        printf("Time remaining: %ld seconds\n", t - travel_time_t);
        sleep(1);
    }
    
    printf("\nWelcome to %s", asctime(&travel_time));
    printf("You have successfully traveled back in time!\n");

    return 0;
}