//FormAI DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding random number generator with current time

    int temperature = rand() % 101 - 50; // generating temperature between -50 and 50 degrees Celsius
    float humidity = (float)rand() / RAND_MAX; // generating humidity between 0 and 1
    int wind_speed = rand() % 101; // generating wind speed between 0 and 100 km/hour
    int cloud_cover = rand() % 101; // generating cloud cover percentage between 0 and 100

    printf("Today's weather:\n");
    printf("Temperature: %dC\n", temperature);
    printf("Humidity: %.2f\n", humidity);
    printf("Wind speed: %dkm/hour\n", wind_speed);
    printf("Cloud cover: %d%%\n", cloud_cover);

    return 0;
}