//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, wind_speed, wind_direction;
    srand(time(NULL));

    printf("Enter temperature (in Celsius): ");
    scanf("%d", &temperature);

    printf("Enter humidity (in percentage): ");
    scanf("%d", &humidity);

    printf("Enter wind speed (in km/h): ");
    scanf("%d", &wind_speed);

    printf("Enter wind direction (in degrees): ");
    scanf("%d", &wind_direction);

    // Generate random values for cloud cover and precipitation
    int cloud_cover = rand() % 101;
    int precipitation = rand() % 101;

    printf("\n");
    printf("Current temperature: %dC\n", temperature);
    printf("Current humidity: %d%%\n", humidity);
    printf("Current wind speed: %dkm/h\n", wind_speed);
    printf("Current wind direction: %d degrees\n", wind_direction);
    printf("Current cloud cover: %d%%\n", cloud_cover);
    printf("Current precipitation: %d%%\n", precipitation);

    return 0;
}