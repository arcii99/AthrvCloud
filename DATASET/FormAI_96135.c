//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); // initialize random number generator

    const int MAX_TEMP = 100; // maximum temperature limit
    const int MIN_TEMP = 0; // minimum temperature limit
    const int MAX_DAYS = 7; // maximum days in weather simulation
    const int MAX_PRECIP = 5; // maximum precipitation

    int i, j; // loop variables
    int day; // current day
    int temp; // current temperature
    int precip; // current precipitation

    // display week forecast
    printf("Weather forecast for the next 7 days:\n");

    for (day = 1; day <= MAX_DAYS; day++) { // iterate through 7 days
        temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // generate random temperature
        precip = rand() % (MAX_PRECIP + 1); // generate random precipitation

        printf("Day %d: ", day); // display day
        // display temperature
        if (temp < 32) {
            printf("%d°F (Cold)\n", temp);
        } else if (temp >= 32 && temp < 60) {
            printf("%d°F (Cool)\n", temp);
        } else if (temp >= 60 && temp < 80) {
            printf("%d°F (Warm)\n", temp);
        } else {
            printf("%d°F (Hot)\n", temp);
        }

        // display precipitation
        printf("Precipitation: ");
        switch (precip) {
            case 0:
                printf("None\n");
                break;
            case 1:
            case 2:
                printf("Light\n");
                break;
            case 3:
            case 4:
                printf("Moderate\n");
                break;
            case 5:
                printf("Heavy\n");
                break;
            default:
                printf("Unknown\n"); // should never happen
        }

        printf("\n"); // separate each day's forecast
    }

    return 0;
}