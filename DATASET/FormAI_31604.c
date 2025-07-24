//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void timeTravel(int year) {
    printf("\n\nWelcome to the Time Travel Simulator!");
    printf("\n\nInitializing time travel sequence...\n\n");
    printf("3...");
    sleep(1);
    printf("2...");
    sleep(1);
    printf("1...");
    sleep(1);
    printf("Traveling through time...");
    sleep(1);
    printf("\n\nYou have arrived in the year %d!\n\n", year);
}

int main() {
    srand(time(0));
    int year = rand() % 5001;
    int choice;

    printf("You are about to embark on a journey through time. Are you ready?\n");
    printf("1. Yes\n");
    printf("2. No\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        timeTravel(year);
    } else if (choice == 2) {
        printf("OK, maybe next time.\n");
    } else {
        printf("Invalid input.");
    }

    return 0;
}