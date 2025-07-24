//FormAI DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time

    float temperature;
    int humidity;
    int precipitation;
    int windSpeed;
    char windDirection[4];
    char skyCondition[10];

    // generate random values for weather parameters
    temperature = (rand() % 50) + 15; // temperature range: 15-64*C
    humidity = rand() % 101; // humidity range: 0-100%
    precipitation = rand() % 25; // precipitation range: 0-24 mm
    windSpeed = rand() % 71; // wind speed range: 0-70 km/h

    // choose a random wind direction
    switch (rand() % 16) {
        case 0:
            sprintf(windDirection, "N");
            break;
        case 1:
            sprintf(windDirection, "NNE");
            break;
        case 2:
            sprintf(windDirection, "NE");
            break;
        case 3:
            sprintf(windDirection, "ENE");
            break;
        case 4:
            sprintf(windDirection, "E");
            break;
        case 5:
            sprintf(windDirection, "ESE");
            break;
        case 6:
            sprintf(windDirection, "SE");
            break;
        case 7:
            sprintf(windDirection, "SSE");
            break;
        case 8:
            sprintf(windDirection, "S");
            break;
        case 9:
            sprintf(windDirection, "SSW");
            break;
        case 10:
            sprintf(windDirection, "SW");
            break;
        case 11:
            sprintf(windDirection, "WSW");
            break;
        case 12:
            sprintf(windDirection, "W");
            break;
        case 13:
            sprintf(windDirection, "WNW");
            break;
        case 14:
            sprintf(windDirection, "NW");
            break;
        case 15:
            sprintf(windDirection, "NNW");
            break;
    }

    // choose a random sky condition
    switch (rand() % 4) {
        case 0:
            sprintf(skyCondition, "Clear");
            break;
        case 1:
            sprintf(skyCondition, "Partly cloudy");
            break;
        case 2:
            sprintf(skyCondition, "Mostly cloudy");
            break;
        case 3:
            sprintf(skyCondition, "Overcast");
            break;
    }

    // print out the weather report
    printf("Temperature: %.1f*C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Precipitation: %d mm\n", precipitation);
    printf("Wind speed: %d km/h\n", windSpeed);
    printf("Wind direction: %s\n", windDirection);
    printf("Sky condition: %s\n", skyCondition);

    return 0;
}