//FormAI DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_weather(int type, int temp) {

    char* weather_type;

    switch(type) {
        case 1:
            weather_type = "Sunny";
            break;
        case 2:
            weather_type = "Cloudy";
            break;
        case 3:
            weather_type = "Rainy";
            break;
        case 4:
            weather_type = "Stormy";
            break;
        default:
            weather_type = "Unknown";
            break;
    }

    printf("Today's weather is %s with a temperature of %d degrees Celsius.\n", weather_type, temp);
}

int main() {

    int weather_type, temperature;

    srand(time(0));

    weather_type = rand() % 4 + 1;

    switch(weather_type) {
        case 1:
            temperature = rand() % 12 + 16;
            break;
        case 2:
            temperature = rand() % 8 + 8;
            break;
        case 3:
            temperature = rand() % 6 + 4;
            break;
        case 4:
            temperature = rand() % 10 + 20;
            break;
        default:
            temperature = 0;
            break;
    }

    print_weather(weather_type, temperature);

    return 0;
}