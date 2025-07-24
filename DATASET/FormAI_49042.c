//FormAI DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

// Data structure to hold weather information
typedef struct {
    float temperature;
    float precipitation;
} Weather;

// Function to generate a random weather report for a single day
Weather generate_report() {
    Weather report;
    report.temperature = (float)(rand() % 40);
    report.precipitation = (float)(rand() % 100) / 100.0;
    return report;
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    
    // Initialize an array of cities
    char* cities[NUM_CITIES] = {"New York", "San Francisco", "Chicago", "Miami", "Dallas"};
    
    // Initialize a 2D array to store weather reports for each city and day
    Weather weather_report[NUM_CITIES][NUM_DAYS];
    
    // Generate weather reports for each city and day
    for (int city_index = 0; city_index < NUM_CITIES; city_index++) {
        printf("Generating weather reports for %s\n\n", cities[city_index]);
        for (int day_index = 0; day_index < NUM_DAYS; day_index++) {
            Weather report = generate_report();
            weather_report[city_index][day_index] = report;
            printf("Day %d: Temperature - %.1f degrees Celsius, Precipitation - %.2f cm\n", day_index+1, report.temperature, report.precipitation);
        }
        printf("\n");
    }
    
    // Print the average temperature and precipitation for each city over all days
    for (int city_index = 0; city_index < NUM_CITIES; city_index++) {
        float temp_sum = 0.0;
        float prec_sum = 0.0;
        for (int day_index = 0; day_index < NUM_DAYS; day_index++) {
            temp_sum += weather_report[city_index][day_index].temperature;
            prec_sum += weather_report[city_index][day_index].precipitation;
        }
        float temp_avg = temp_sum / (float)NUM_DAYS;
        float prec_avg = prec_sum / (float)NUM_DAYS;
        printf("Average weather report for %s\n", cities[city_index]);
        printf("Temperature - %.1f degrees Celsius, Precipitation - %.2f cm\n\n", temp_avg, prec_avg);
    }
    
    return 0;
}