//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>

void timeTravel(int year) {
    if (year == 2021) {
        printf("Arrived in the present day!\n");
        return;
    } else if (year < 2021) {
        printf("Traveling back in time to %d...\n", year);
    } else {
        printf("Traveling forward in time to %d...\n", year);
    }
    timeTravel(year + (year < 2021 ? 1 : -1));
}

int main() {
    int desiredYear;
    printf("Welcome to the time travel simulator!\n");
    printf("Enter a year to travel to: ");
    scanf("%d", &desiredYear);
    printf("Initializing time travel sequence...\n");
    timeTravel(desiredYear);
    return 0;
}