//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40        // maximum temperature in degrees Celsius
#define MIN_TEMP -20       // minimum temperature in degrees Celsius
#define MAX_RAINFALL 100   // maximum rainfall in millimeters
#define MIN_RAINFALL 0     // minimum rainfall in millimeters
#define MAX_WIND_SPEED 50  // maximum wind speed in kilometers per hour
#define MIN_WIND_SPEED 0   // minimum wind speed in kilometers per hour

// function prototypes
int random_int(int min, int max);
float random_float(float min, float max);

int main() {
    const int NUM_DAYS = 7;     // number of days in the simulation
    int day;                    // current day
    int temperature;            // current temperature in degrees Celsius
    int rainfall;               // current rainfall in millimeters
    float wind_speed;           // current wind speed in kilometers per hour
    int max_temp = MIN_TEMP;    // maximum temperature for the week
    int min_temp = MAX_TEMP;    // minimum temperature for the week
    int total_rainfall = 0;     // total rainfall for the week
    float avg_wind_speed = 0.0; // average wind speed for the week

    // seed the random number generator
    srand(time(NULL));

    // simulate the weather for each day
    for (day = 1; day <= NUM_DAYS; day++) {
        // generate a random temperature between MIN_TEMP and MAX_TEMP
        temperature = random_int(MIN_TEMP, MAX_TEMP);

        // generate a random rainfall between MIN_RAINFALL and MAX_RAINFALL
        rainfall = random_int(MIN_RAINFALL, MAX_RAINFALL);

        // generate a random wind speed between MIN_WIND_SPEED and MAX_WIND_SPEED
        wind_speed = random_float(MIN_WIND_SPEED, MAX_WIND_SPEED);

        // check if the temperature is the highest or lowest for the week so far
        if (temperature > max_temp) {
            max_temp = temperature;
        }
        if (temperature < min_temp) {
            min_temp = temperature;
        }

        // add the rainfall to the total for the week
        total_rainfall += rainfall;

        // add the wind speed to the average for the week
        avg_wind_speed += wind_speed;

        // print out the weather data for the day
        printf("Day %d:\n", day);
        printf("    Temperature: %dC\n", temperature);
        printf("    Rainfall: %dmm\n", rainfall);
        printf("    Wind Speed: %.1fkm/h\n", wind_speed);
    }

    // calculate the average wind speed for the week
    avg_wind_speed /= NUM_DAYS;

    // print out the weather summary for the week
    printf("Weather Summary for the Week:\n");
    printf("    Maximum Temperature: %dC\n", max_temp);
    printf("    Minimum Temperature: %dC\n", min_temp);
    printf("    Total Rainfall: %dmm\n", total_rainfall);
    printf("    Average Wind Speed: %.1fkm/h\n", avg_wind_speed);

    return 0;
}

// generate a random integer between min and max
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// generate a random floating-point number between min and max
float random_float(float min, float max) {
    return (rand() / (float)RAND_MAX) * (max - min) + min;
}