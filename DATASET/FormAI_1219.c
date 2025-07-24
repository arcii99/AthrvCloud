//FormAI DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    float temperature = rand() % 51 - 10;
    float humidity = rand() % 101;
    float wind_speed = rand() % 31;
    char sky_conditions[13][10] = {"sunny", "partly cloudy", "cloudy",
                                   "overcast", "foggy", "misty", "rainy",
                                   "snowy", "sleet", "hail", "stormy",
                                   "windy", "tornado"};
    int sky_index = rand() % 13;
    char wind_direction[8][10] = {"north", "northeast", "east", "southeast",
                                  "south", "southwest", "west", "northwest"};
    int wind_index = rand() % 8;

    printf("** Welcome to the Weather Simulation Program **\n");
    printf("Today's temperature is: %.1f°C\n", temperature);
    printf("Today's humidity is: %.1f%%\n", humidity);
    printf("Today's windspeed is: %.1f km/h\n", wind_speed);
    printf("Today's sky condition is: %s\n", sky_conditions[sky_index]);
    printf("Today's wind direction is: %s\n", wind_direction[wind_index]);

    if (temperature >= 30 && sky_index >= 6) {
        printf("Time to hit the beach!\n");
    } else if (temperature >= 20 && sky_index >= 4) {
        printf("Perfect weather for a picnic!\n");
    } else if (temperature >= 10 && sky_index >= 2) {
        printf("Great day to go for a hike!\n");
    } else if (temperature < 0 && sky_index >= 7) {
        printf("Stay warm and cozy inside with a good book!\n");
    } else {
        printf("Time to relax at home and enjoy the weather on TV!\n");
    }
    printf("** Have a nice day! **\n");

    return 0;
}