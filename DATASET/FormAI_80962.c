//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A function to handle time-travel */
void time_travel(int years, int months, int days) {
    struct tm travel_time = {0};  // Initialize travel_time struct

    travel_time.tm_year = years - 1900;  // Year starts from 1900
    travel_time.tm_mon = months - 1;  // Month starts from 0
    travel_time.tm_mday = days;

    time_t t = mktime(&travel_time);  // Convert the travel_time struct into time_t format
    struct tm* tm_info = localtime(&t);  // Convert the time_t back to a struct

    printf("You have time-traveled to %s", asctime(tm_info));
}

/* Main program */
int main() {
    time_t now = time(NULL);  // Get the current time
    struct tm* tm_now = localtime(&now);

    printf("Current Date: %d/%d/%d\n", tm_now->tm_mday, tm_now->tm_mon + 1, tm_now->tm_year + 1900);  // Display current date

    /* Prompt user for years, months, and days to time-travel */
    int years, months, days;
    printf("Enter the number of years to time-travel: ");
    scanf("%d", &years);
    printf("Enter the number of months to time-travel: ");
    scanf("%d", &months);
    printf("Enter the number of days to time-travel: ");
    scanf("%d", &days);

    time_travel(tm_now->tm_year + 1900 + years, tm_now->tm_mon + 1 + months, tm_now->tm_mday + days);

    return 0;
}