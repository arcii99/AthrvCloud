//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONTHS_PER_YEAR 12

void print_monthly_stats(float data[], int year, int month)
{
    float max_temp = data[0];
    float min_temp = data[0];
    float total_temp = data[0];

    for (int i = 1; i < MONTHS_PER_YEAR; i++) {
        if (data[i] > max_temp) {
            max_temp = data[i];
        }
        if (data[i] < min_temp) {
            min_temp = data[i];
        }
        total_temp += data[i];
    }

    float avg_temp = total_temp / MONTHS_PER_YEAR;

    printf("Year %d, Month %d\n", year, month);
    printf("Max Temperature: %.2f degrees\n", max_temp);
    printf("Min Temperature: %.2f degrees\n", min_temp);
    printf("Average Temperature: %.2f degrees\n", avg_temp);
}

int main()
{
    srand(time(NULL));

    int num_years = 10;
    float yearly_temps[num_years][MONTHS_PER_YEAR];

    for (int i = 0; i < num_years; i++) {
        for (int j = 0; j < MONTHS_PER_YEAR; j++) {
            yearly_temps[i][j] = (rand() % 60) - 10;
        }
    }

    for (int i = 0; i < num_years; i++) {
        for (int j = 0; j < MONTHS_PER_YEAR; j++) {
            print_monthly_stats(yearly_temps[i], i + 1, j + 1);
        }
    }

    return 0;
}