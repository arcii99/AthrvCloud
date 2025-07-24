//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multivariable
#include <stdio.h>
#include <time.h>

int main() {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    printf("Current date is: %d/%d/%d\n", month, day, year);

    int desiredYear, desiredMonth, desiredDay;

    printf("\nEnter the year you want to travel to: ");
    scanf("%d", &desiredYear);
    printf("Enter the month you want to travel to: ");
    scanf("%d", &desiredMonth);
    printf("Enter the day you want to travel to: ");
    scanf("%d", &desiredDay);

    time_t desiredTime = mktime(&localTime);

    if (desiredTime == -1) {
        printf("Invalid date entered. Please try again.\n");
        return 1;
    }

    printf("\nTime machine activated. Travelling to %d/%d/%d...\n", desiredMonth, desiredDay, desiredYear);
    printf("Please wait...\n\n");

    for (int i=10; i>0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }

    printf("\nWelcome to %d/%d/%d!\n", desiredMonth, desiredDay, desiredYear);

    return 0;
}