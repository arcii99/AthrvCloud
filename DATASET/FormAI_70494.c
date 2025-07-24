//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>

void travel(int year) {
    if (year == 2021) {
        printf("You have reached your destination: Present day.\n");
        return;
    }
    printf("You are now in the year %d.\n", year);
    if (year > 2021) {
        year--;
    } else {
        year++;
    }
    travel(year);
}

int main() {
    int inputYear;
    printf("Enter a year to time travel to: ");
    scanf("%d", &inputYear);
    printf("Initiating time travel to %d.\n", inputYear);
    travel(inputYear);
    return 0;
}