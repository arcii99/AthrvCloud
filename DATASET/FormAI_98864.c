//FormAI DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40.0f // maximum temperature
#define MIN_TEMP -20.0f // minimum temperature
#define MAX_HUMIDITY 100.0f // maximum humidity
#define MIN_HUMIDITY 0.0f // minimum humidity
#define MAX_PRECIPITATION 50.0f // maximum precipitation
#define MIN_PRECIPITATION 0.0f // minimum precipitation

typedef struct {
    float temperature; // temperature in degrees Celsius
    float humidity; // relative humidity in percentage
    float precipitation; // precipitation in mm
} WeatherData;

void generateWeatherData(WeatherData *data) {
    data->temperature = (float)rand()/(float)(RAND_MAX) * (MAX_TEMP - MIN_TEMP) + MIN_TEMP; // generate a random temperature between MIN_TEMP and MAX_TEMP
    data->humidity = (float)rand()/(float)(RAND_MAX) * (MAX_HUMIDITY - MIN_HUMIDITY) + MIN_HUMIDITY; // generate a random humidity between MIN_HUMIDITY and MAX_HUMIDITY
    data->precipitation = (float)rand()/(float)(RAND_MAX) * (MAX_PRECIPITATION - MIN_PRECIPITATION) + MIN_PRECIPITATION; // generate a random precipitation between MIN_PRECIPITATION and MAX_PRECIPITATION
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    WeatherData weatherData; // create a WeatherData struct to hold the weather data
    generateWeatherData(&weatherData); // generate the weather data

    printf("Temperature: %.1f C\n", weatherData.temperature);
    printf("Humidity: %.1f %%\n", weatherData.humidity);
    printf("Precipitation: %.1f mm\n", weatherData.precipitation);

    return 0;
}