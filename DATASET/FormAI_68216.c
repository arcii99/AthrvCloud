//FormAI DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP -20

int main() {
    srand(time(NULL));
    
    int city_temps[7][24]; // 7 days, 24 hours each
    
    // generate random temperatures for each hour of each day
    for (int i = 0; i < 7; i++) { // for each day
        for (int j = 0; j < 24; j++) { // for each hour
            int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // random temperature within range
            city_temps[i][j] = temp;
        }
    }
    
    // calculate average temperature for each day
    double daily_avg[7];
    for (int i = 0; i < 7; i++) { // for each day
        double sum = 0;
        for (int j = 0; j < 24; j++) { // for each hour
            sum += city_temps[i][j];
        }
        daily_avg[i] = sum / 24;
    }
    
    // find the hottest and coldest day of the week
    int hottest_day = 0;
    int coldest_day = 0;
    double hottest_temp = daily_avg[0];
    double coldest_temp = daily_avg[0];
    
    for (int i = 1; i < 7; i++) { // start from index 1 since we are already checking index 0
        if (daily_avg[i] > hottest_temp) {
            hottest_day = i;
            hottest_temp = daily_avg[i];
        }
        if (daily_avg[i] < coldest_temp) {
            coldest_day = i;
            coldest_temp = daily_avg[i];
        }
    }
    
    // print out table of temperatures and daily averages
    printf("   |");
    for (int i = 0; i < 24; i++) {
        printf("%02d|", i);
    }
    printf(" Avg\n");
    printf("---+");
    for (int i = 0; i < 24; i++) {
        printf("--+");
    }
    printf("----\n");
    
    for (int i = 0; i < 7; i++) {
        printf("%02d |", i);
        for (int j = 0; j < 24; j++) {
            printf("%2d|", city_temps[i][j]);
        }
        printf(" %.1f", daily_avg[i]);
        if (i == hottest_day) {
            printf(" (HOTTEST)");
        }
        if (i == coldest_day) {
            printf(" (COLDEST)");
        }
        printf("\n");
    }
    
    return 0;
}