//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void travelThroughTime(int year) {
    if (year == 2022) {
        printf("Welcome to the present time!\n");
    } else if (year > 2022) {
        printf("You traveled %d years into the future.\n", year - 2022);
        travelThroughTime(year - 1);
    } else if (year < 2022) {
        printf("You traveled %d years into the past.\n", 2022 - year);
        travelThroughTime(year + 1);
    }
}

int main() {
    int year;
    printf("Enter a year to time travel to: ");
    scanf("%d", &year);
    travelThroughTime(year);
    return 0;
}