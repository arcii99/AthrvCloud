//FormAI DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // array of weather types
    char *weather[] = {"sunny", "cloudy", "rainy", "thunderstorm", "snowy"};

    // array of temperature ranges for each weather type
    int temperature[][2] = {{60, 80}, {50, 70}, {40, 60}, {50, 80}, {20, 40}};

    // randomly select a weather type
    int weather_type = rand() % 5;

    // randomly generate a temperature within the range of the selected weather type
    int temp = rand() % (temperature[weather_type][1] - temperature[weather_type][0] + 1) + temperature[weather_type][0];

    // print out the weather information
    printf("Today's weather is %s with a temperature range of %d-%d degrees Fahrenheit.\n", weather[weather_type], temperature[weather_type][0], temperature[weather_type][1]);

    return 0;
}