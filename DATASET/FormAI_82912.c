//FormAI DATASET v1.0 Category: Weather simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LOCATIONS 5 // number of locations to simulate weather for
#define MAX_TEMP 40 // maximum temperature for location in Celsius
#define MIN_TEMP -10 // minimum temperature for location in Celsius
#define MAX_WIND 100 // maximum wind speed for location in km/h
#define MIN_WIND 0 // minimum wind speed for location in km/h
#define MAX_HUMIDITY 100 // maximum humidity level for location
#define MIN_HUMIDITY 0 // minimum humidity level for location

// Structure to hold weather data for a given location
typedef struct weather_data {
    char* location_name;
    int temperature;
    int wind_speed;
    int humidity;
} weather_data;

// Function to generate random integer within range of min and max
int generate_random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    weather_data locations[NUM_LOCATIONS] = {
        {"New York", 0, 0, 0},
        {"Los Angeles", 0, 0, 0},
        {"Chicago", 0, 0, 0},
        {"Houston", 0, 0, 0},
        {"Philadelphia", 0, 0, 0}
    };

    // Set seed for random number generation based on current time
    srand(time(NULL));

    // Generate random weather data for each location
    for (int i = 0; i < NUM_LOCATIONS; i++) {
        // Generate random temperature within range of MIN_TEMP and MAX_TEMP
        locations[i].temperature = generate_random_int(MIN_TEMP, MAX_TEMP);

        // Generate random wind speed within range of MIN_WIND and MAX_WIND
        locations[i].wind_speed = generate_random_int(MIN_WIND, MAX_WIND);

        // Generate random humidity level within range of MIN_HUMIDITY and MAX_HUMIDITY
        locations[i].humidity = generate_random_int(MIN_HUMIDITY, MAX_HUMIDITY);
    }

    // Output weather data for each location
    for (int i = 0; i < NUM_LOCATIONS; i++) {
        printf("Weather for %s\n", locations[i].location_name);
        printf("Temperature: %d C\n", locations[i].temperature);
        printf("Wind Speed: %d km/h\n", locations[i].wind_speed);
        printf("Humidity: %d%%\n", locations[i].humidity);
        printf("=================================\n");
    }

    return 0;
}