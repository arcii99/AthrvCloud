//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int year = rand() % 10000; // generate a random year between 0 and 9999
    int month = rand() % 12 + 1; // generate a random month between 1 and 12
    int day;
    switch (month) {
        case 2: // February
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
                // leap year
                day = rand() % 29 + 1; // generate a random day between 1 and 29
            } else {
                day = rand() % 28 + 1; // generate a random day between 1 and 28
            }
            break;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            day = rand() % 30 + 1; // generate a random day between 1 and 30
            break;
        default: // all other months
            day = rand() % 31 + 1; // generate a random day between 1 and 31
            break;
    }
    printf("Year: %d\n", year);
    printf("Month: %d\n", month);
    printf("Day: %d\n", day);
    return 0;
}