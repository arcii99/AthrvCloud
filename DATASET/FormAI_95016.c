//FormAI DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // seeding the random number generator with current time
    double temperature = (rand() % 50) - 10;  // random temperature from -10°C to 40°C
    int humidity = rand() % 101;  // random humidity from 0% to 100%
    int wind_speed = rand() % 81;  // random wind speed from 0 km/h to 80 km/h
    int wind_direction = rand() % 360;  // random wind direction in degrees

    printf("Current weather conditions:\n");
    printf("Temperature: %.1lf°C\n", temperature);
    printf("Humidity: %d%\n", humidity);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Wind direction: %d degrees\n", wind_direction);

    if (temperature >= 30 && humidity >= 50) {  // hot and humid
        printf("It's hot and humid. Stay indoors and cool off.\n");
    }
    else if (temperature >= 20 && temperature < 30 && humidity >= 50) {  // warm and humid
        printf("It's warm and humid. Drink plenty of water.\n");
    }
    else if (temperature >= 0 && temperature < 20) {  // cold
        printf("It's cold. Wear warm clothes.\n");
    }
    else if (temperature < 0 && wind_speed >= 30) {  // windy and freezing
        printf("It's windy and freezing. Stay warm and avoid going outside if possible.\n");
    }

    // converting wind direction in degrees to cardinal direction
    char *cardinal_direction;
    if (wind_direction >= 0 && wind_direction < 22.5) {
        cardinal_direction = "North";
    }
    else if (wind_direction >= 22.5 && wind_direction < 67.5) {
        cardinal_direction = "Northwest";
    }
    else if (wind_direction >= 67.5 && wind_direction < 112.5) {
        cardinal_direction = "West";
    }
    else if (wind_direction >= 112.5 && wind_direction < 157.5) {
        cardinal_direction = "Southwest";
    }
    else if (wind_direction >= 157.5 && wind_direction < 202.5) {
        cardinal_direction = "South";
    }
    else if (wind_direction >= 202.5 && wind_direction < 247.5) {
        cardinal_direction = "Southeast";
    }
    else if (wind_direction >= 247.5 && wind_direction < 292.5) {
        cardinal_direction = "East";
    }
    else if (wind_direction >= 292.5 && wind_direction < 337.5) {
        cardinal_direction = "Northeast";
    }
    else if (wind_direction >= 337.5 && wind_direction < 360) {
        cardinal_direction = "North";
    }

    printf("Wind is blowing from %s direction.\n", cardinal_direction);

    return 0;
}