//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE 0
#define MAX_WIND_SPEED 100
#define MIN_WIND_SPEED 0
#define MAX_RAINFALL 1000
#define MIN_RAINFALL 0

typedef struct {
    double temperature;
    int wind_speed;
    double rainfall;
} weather_info;

void generate_weather_info(weather_info *info) {
    srand(time(NULL));
    info->temperature = (double) rand() / (double) RAND_MAX * (MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE;
    info->wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    info->rainfall = (double) rand() / (double) RAND_MAX * (MAX_RAINFALL - MIN_RAINFALL) + MIN_RAINFALL;
}

void print_weather_info(weather_info info) {
    printf("Temperature: %.2f\n", info.temperature);
    printf("Wind Speed: %d\n", info.wind_speed);
    printf("Rainfall: %.2f\n", info.rainfall);
}

int main() {
    weather_info info;

    generate_weather_info(&info);
    printf("Weather Simulation 1:\n");
    print_weather_info(info);

    generate_weather_info(&info);
    printf("Weather Simulation 2:\n");
    print_weather_info(info);

    generate_weather_info(&info);
    printf("Weather Simulation 3:\n");
    print_weather_info(info);

    return 0;
}