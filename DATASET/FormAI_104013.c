//FormAI DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DAYS_IN_A_MONTH = 30;
const int MAX_TEMPERATURE = 35;
const int MIN_TEMPERATURE = 10;

int main() {
    srand(time(0)); // set random seed based on current time
    
    int temperature[DAYS_IN_A_MONTH];
    
    // generate random temperature for each day of the month
    for (int i = 0; i < DAYS_IN_A_MONTH; i++) {
        temperature[i] = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    }
    
    printf("Temperature simulation for this month:\n");
    
    // print out the temperature for each day of the month
    for (int i = 0; i < DAYS_IN_A_MONTH; i++) {
        printf("Day %d: %d degrees Celsius\n", i+1, temperature[i]);
    }
    
    // calculate the average temperature for the month
    int sum_temperature = 0;
    for (int i = 0; i < DAYS_IN_A_MONTH; i++) {
        sum_temperature += temperature[i];
    }
    float avg_temperature = sum_temperature / (float)DAYS_IN_A_MONTH;
    
    printf("\nAverage temperature for this month: %.2f degrees Celsius\n", avg_temperature);
    
    // calculate the number of days that the temperature was above the average
    int above_avg_days = 0;
    for (int i = 0; i < DAYS_IN_A_MONTH; i++) {
        if (temperature[i] > avg_temperature) {
            above_avg_days++;
        }
    }
    
    printf("Number of days above average temperature: %d\n", above_avg_days);
    
    return 0;
}