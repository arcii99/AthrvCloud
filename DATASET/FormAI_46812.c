//FormAI DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YEAR 2021
#define NUM_MONTHS 12
#define NUM_DAYS 30
#define MIN_TEMP -5
#define MAX_TEMP 35

typedef struct {
    int year;
    int month;
    int day;
    float temperature;
    char* conditions;
} WeatherData;

char* generate_conditions(float temp) {
    if (temp < 0) {
        return "Winter";
    } else if (temp >= 0 && temp < 10) {
        return "Spring";
    } else if (temp >= 10 && temp < 25) {
        return "Summer";
    } else {
        return "Fall";
    }
}

void print_weather_data(WeatherData* data) {
   printf("%d-%d-%d: %.2f degrees C, %s\n", data->year, data->month, data->day, data->temperature, data->conditions);
}

int main() {
    srand(time(NULL));
    WeatherData weather[NUM_MONTHS * NUM_DAYS];  // Set up array to store weather data for each day

    // Generate and store weather data for each day in 2021
    for (int i = 0; i < NUM_MONTHS; i++) {
        int days_in_month;
        if (i == 1) {
            days_in_month = 28;  // February
        } else if (i == 3 || i == 5 || i == 8 || i == 10) {
            days_in_month = 30;  // April, June, September, November
        } else {
            days_in_month = 31;  // January, March, May, July, August, October, December
        }
        for (int j = 1; j <= days_in_month; j++) {
            WeatherData data = {
                .year = YEAR, 
                .month = i + 1, 
                .day = j, 
                .temperature = (float) (rand() % (MAX_TEMP - MIN_TEMP)) + MIN_TEMP,  // Generate random temperature
                .conditions = generate_conditions(data.temperature)
            };
            weather[i * NUM_DAYS + j - 1] = data;  // Store data in the array
        }
    }

    // Print out the weather data for each day in 2021
    for (int i = 0; i < NUM_MONTHS * NUM_DAYS; i++) {
        print_weather_data(&weather[i]);
    }
    
    return 0;
}