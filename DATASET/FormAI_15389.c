//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void timeTravel(int year) {
    int currentYear;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    currentYear = tm.tm_year + 1900;

    int yearsToTravel = year - currentYear;

    if (yearsToTravel == 0) {
        printf("You are already in the present year!");
        return;
    }

    if (yearsToTravel < 0) {
        printf("Time travel is only possible into the future!\n");
        return;
    }

    printf("Get ready! You will travel %d year%s into the future!\n", yearsToTravel, yearsToTravel != 1 ? "s" : "");

    for (int i = 1; i <= yearsToTravel; i++) {
        printf("Year %d...\n", currentYear+i);
        /* Code for travelling into the future goes here! */
    }

    printf("You have arrived in the year %d!\n", year);
}

int main() {
    int year;
    printf("Welcome to the time travel simulator!\n");
    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);
    getchar(); // Remove the \n from the input buffer

    timeTravel(year);

    printf("Thank you for using the time travel simulator!\n");

    return 0;
}