//FormAI DATASET v1.0 Category: Weather simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    float temperature = 0;
    float pressure = 0;
    int humidity = 0;
    int wind_speed = 0;
    char wind_direction[5];

    // Generate random weather conditions
    temperature = -10.0 + rand() / ((RAND_MAX / 40.0) + 1);
    pressure = 900 + rand() % 200;
    humidity = rand() % 101;
    wind_speed = rand() % 51;
    switch (rand() % 8) {
        case 0: strncpy(wind_direction, "N", 5); break;
        case 1: strncpy(wind_direction, "E", 5); break;
        case 2: strncpy(wind_direction, "W", 5); break;
        case 3: strncpy(wind_direction, "S", 5); break;
        case 4: strncpy(wind_direction, "NE", 5); break;
        case 5: strncpy(wind_direction, "NW", 5); break;
        case 6: strncpy(wind_direction, "SE", 5); break;
        case 7: strncpy(wind_direction, "SW", 5); break;
    }

    // Print out the weather conditions
    printf("The weather today is:\n");
    printf("Temperature: %.1f degrees Celsius\n", temperature);
    printf("Pressure: %.0f hPa\n", pressure);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Wind direction: %s\n\n", wind_direction);

    // If it's below freezing, warn about icy conditions
    if (temperature <= 0) {
        printf("Warning: Icy conditions!\n");
    }

    // If the wind is strong and coming from the north quadrant, warn about a cold front
    if (wind_speed >= 30 && (strcmp(wind_direction, "N") == 0 || strcmp(wind_direction, "NE") == 0 || strcmp(wind_direction, "NW") == 0)) {
        printf("Warning: Possible cold front approaching!\n");
    }

    // If the pressure is low, warn about possible storms
    if (pressure < 1000) {
        printf("Warning: Possible storms on the way!\n");
    }

    return 0;
}