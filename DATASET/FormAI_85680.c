//FormAI DATASET v1.0 Category: Weather simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables for simulation settings
int num_days = 7;
int num_cities = 3;
double max_temp = 30.0;
double min_temp = 10.0;

// Declare functions for generating random temperature and humidity values
double generate_temperature() {
    return ((double)rand() / RAND_MAX) * (max_temp - min_temp) + min_temp;
}

int generate_humidity() {
    return rand() % 101;
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Declare variables for simulation
    int city, day;
    double temperatures[num_days][num_cities];
    int humidity[num_days][num_cities];

    // Print simulation settings
    printf("Simulation settings:\nNumber of days: %d\nNumber of cities: %d\nMax temperature: %.1f\nMin temperature: %.1f\n\n", num_days, num_cities, max_temp, min_temp);

    // Generate random temperature and humidity values for each city and day
    for (city = 0; city < num_cities; city++) {
        printf("City %d:\n", city+1);
        for (day = 0; day < num_days; day++) {
            temperatures[day][city] = generate_temperature();
            humidity[day][city] = generate_humidity();
            printf("Day %d: Temperature=%.1f Humidity=%d%%\n", day+1, temperatures[day][city], humidity[day][city]);
        }
        printf("\n");
    }

    // Calculate average temperature and humidity for each city
    double avg_temperatures[num_cities];
    double avg_humidity[num_cities];
    for (city = 0; city < num_cities; city++) {
        double sum_temp = 0.0;
        int sum_humid = 0;
        for (day = 0; day < num_days; day++) {
            sum_temp += temperatures[day][city];
            sum_humid += humidity[day][city];
        }
        avg_temperatures[city] = sum_temp / num_days;
        avg_humidity[city] = (double)sum_humid / num_days;
    }

    // Print average temperature and humidity for each city
    printf("Average temperature and humidity for each city:\n");
    for (city = 0; city < num_cities; city++) {
        printf("City %d: Average temperature=%.1f Average humidity=%.1f%%\n", city+1, avg_temperatures[city], avg_humidity[city]);
    }

    return 0;
}