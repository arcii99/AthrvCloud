//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <time.h>

int main() {

    time_t presentTime = time(NULL); // fetch the current time from the system clock
    struct tm *dt = localtime(&presentTime); // convert the time to local time

    int presentYear = dt->tm_year + 1900; // get the current year
    int presentMonth = dt->tm_mon + 1; // get the current month
    int presentDay = dt->tm_mday; // get the current day

    printf("Welcome to Grateful Time Travel Simulator!\n");
    printf("The current date is %d/%d/%d\n", presentDay, presentMonth, presentYear);
    printf("Let's go back in time! Enter the number of years you want to travel: ");

    int years; // variable to store the number of years to travel
    scanf("%d", &years);

    int targetYear = presentYear - years; // calculate the target year after time travel

    printf("\n...Travelling back in time...\n");
    printf("Your time travel journey has taken you %d years back, and you have arrived on %d/%d/%d\n", years, presentDay, presentMonth, targetYear);

    return 0;
}