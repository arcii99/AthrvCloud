//FormAI DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_TEMP -20
#define MAX_TEMP 40
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

void printWeather(int temperature, int humidity) {
    printf("Temperature: %dC\nHumidity: %d%%\n", temperature, humidity);
}

int main() {
    srand(time(NULL));
    int temperature = 0, humidity = 0;
    bool isWinter = false, isSummer = false;
    int month = rand() % 12 + 1;

    switch(month) {
        case 1:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            break;
        case 2:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            if (temperature < 0) {
                printf("It's snowing!\n");
                isWinter = true;
            }
            break;
        case 3:
            temperature = rand() % (MAX_TEMP - (MIN_TEMP + 10) + 1) + MIN_TEMP + 10;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            break;
        case 4:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            break;
        case 5:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            if (temperature > 25) {
                printf("It's hot outside! Wear sunscreen.\n");
                isSummer = true;
            }
            break;
        case 6:
            if (isSummer) {
                printf("It's officially summer!\n");
            }
            else {
                temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
                humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
                printWeather(temperature, humidity);
            }
            break;
        case 7:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            break;
        case 8:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            if (temperature > 25) {
                printf("It's hot outside! Wear sunscreen.\n");
                isSummer = true;
            }
            break;
        case 9:
            temperature = rand() % ((MAX_TEMP - 10) - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            break;
        case 10:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            break;
        case 11:
            temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
            printWeather(temperature, humidity);
            if (temperature < 10 && !isWinter) {
                printf("It's officially winter!\n");
                isWinter = true;
            }
            break;
        case 12:
            if (isWinter) {
                printf("It's officially winter!\n");
            }
            else {
                temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
                humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
                printWeather(temperature, humidity);
            }
            break;
    }

    return 0;
}