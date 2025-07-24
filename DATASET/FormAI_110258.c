//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>

void time_travel(int year) {
    if (year < 2020) {
        printf("You cannot travel back before 2020. Please choose a different year.\n");
        return;
    }
    printf("Welcome to %d!\n", year);
    printf("You arrived safely in %d.\n", year);
    printf("What would you like to do? (1. Stay in this year 2. Continue traveling)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enjoy your stay in %d!\n", year);
        return;
    }
    time_travel(year - 10);
}

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose a year to travel to: ");
    int year;
    scanf("%d", &year);
    time_travel(year);
    printf("Thank you for using the Time Travel Simulator!\n");
    return 0;
}