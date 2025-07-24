//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <time.h>

void timeTravel(int year) {
    time_t t = time(NULL); // get current time
    struct tm* localTime = localtime(&t); // convert to local time
    localTime->tm_year = year - 1900; // set year for time travel
    t = mktime(localTime); // convert back to time_t
    printf("Welcome to the year %d!\n", year);
    printf("Today is %s", ctime(&t));
}

int main() {
    printf("Welcome to the Time Travel Simulator\n");
    printf("Enter a year in the future or past to travel to: ");

    int year;
    scanf("%d", &year);

    timeTravel(year);

    return 0;
}