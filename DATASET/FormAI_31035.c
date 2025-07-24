//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set the seed for the random number generator
    srand(time(NULL));

    // Get a random year between 1900 and 2100
    int year = rand() % 201 + 1900;

    // Get a random month between 1 and 12
    int month = rand() % 12 + 1;

    // Get a random day between 1 and 31 (depending on month)
    int day;
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            day = rand() % 29 + 1;
        } else {
            day = rand() % 28 + 1;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        day = rand() % 30 + 1;
    } else {
        day = rand() % 31 + 1;
    }

    // Get a random hour between 0 and 23
    int hour = rand() % 24;

    // Get a random minute between 0 and 59
    int minute = rand() % 60;

    // Print out the date and time
    printf("You have traveled to: %02d/%02d/%d %02d:%02d\n", month, day, year, hour, minute);

    return 0;
}