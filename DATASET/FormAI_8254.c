//FormAI DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50
#define MIN_TEMP -10
#define MAX_MONTH 12
#define MAX_DAY 31

int main() {
    int month, day, temperature[MAX_MONTH][MAX_DAY];
    srand(time(NULL)); // Initialize random seed

    // Generate temperatures for each day of each month
    for (month = 0; month < MAX_MONTH; month++) {
        int max_day = (month == 1) ? 28 : ((month % 2 == 0) ? 30 : 31);
        for (day = 0; day < max_day; day++) {
            temperature[month][day] = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
        }
    }

    // Show temperature for every day of every month
    for (month = 0; month < MAX_MONTH; month++) {
        int max_day = (month == 1) ? 28 : ((month % 2 == 0) ? 30 : 31);
        printf("Month %d:\n", month + 1);
        for (day = 0; day < max_day; day++) {
            printf("%d\t", temperature[month][day]);
        }
        printf("\n");
    }

    // Show average temperature for each month
    printf("Average temperature per month:\n");
    for (month = 0; month < MAX_MONTH; month++) {
        int max_day = (month == 1) ? 28 : ((month % 2 == 0) ? 30 : 31);
        int sum = 0;
        for (day = 0; day < max_day; day++) {
            sum += temperature[month][day];
        }
        printf("Month %d: %.2f\n", month + 1, (float)sum / max_day);
    }

    return 0;
}