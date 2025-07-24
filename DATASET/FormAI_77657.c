//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed for random number generator
    srand(time(NULL));

    // Declare variables
    int temperature, wind_speed, rain_chance, snow_chance;

    // Initializing variables with random values
    temperature = rand() % 100 - 40;
    wind_speed = rand() % 50;
    rain_chance = rand() % 101;
    snow_chance = rand() % 101;

    // Displaying current weather conditions to the user
    printf("Current Weather Conditions:\n");
    printf("Temperature: %d℃\n", temperature);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Rain Chance: %d%%\n", rain_chance);
    printf("Snow Chance: %d%%\n\n", snow_chance);

    // Determining current precipitation type based on rain and snow chance
    if (rain_chance >= 50 && snow_chance < 50) {
        printf("It's currently raining.\n");
    }
    else if (snow_chance >= 50 && rain_chance < 50) {
        printf("It's currently snowing.\n");
    }
    else if (snow_chance >= 50 && rain_chance >= 50) {
        printf("It's currently sleeting.\n");
    }
    else {
        printf("There's no precipitation at the moment.\n");
    }

    // Determining wind chill based on temperature and wind speed
    if (temperature <= 10) {
        int wind_chill = 13.12 + 0.6215 * temperature - 11.37 * pow(wind_speed, 0.16) + 0.3965 * temperature * pow(wind_speed, 0.16);
        printf("The wind chill is %d℃.\n", wind_chill);
    }
    else {
        printf("Wind chill is not applicable at this temperature.\n");
    }

    return 0;
}