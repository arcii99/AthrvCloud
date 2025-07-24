//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travel(int year);

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a year to travel to (between 1900 and 2021):\n");

    int year;
    scanf("%d", &year);

    while (year < 1900 || year > 2021) {
        printf("Invalid year. Please enter a year between 1900 and 2021:\n");
        scanf("%d", &year);
    }

    travel(year);

    return 0;
}

void travel(int year) {
    time_t current_time = time(NULL);
    struct tm *now = localtime(&current_time);

    printf("You are in the year %d.\n", now->tm_year + 1900);

    if (year < now->tm_year + 1900) {
        printf("You are traveling back in time...\n");
        while (now->tm_year + 1900 >= year) {
            printf("The year is now %d.\n", now->tm_year + 1900);
            now->tm_year--;
            sleep(1); // wait for one second
        }
    } else if (year > now->tm_year + 1900) {
        printf("You are traveling forward in time...\n");
        while (now->tm_year + 1900 <= year) {
            printf("The year is now %d.\n", now->tm_year + 1900);
            now->tm_year++;
            sleep(1); // wait for one second
        }
    }

    printf("You have arrived in the year %d.\n", now->tm_year + 1900);
    printf("Thank you for using the Time Travel Simulator!\n");
}