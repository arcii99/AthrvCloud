//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    float temperature = ((float)(rand() % 100))/10;
    float humidity = ((float)(rand() % 100))/10;
    int wind_speed = rand() % 50;
    int wind_direction = rand() % 360;
    char sky[10];
    char rain[10];
    char snow[10];

    if (humidity >= 7.0 && temperature >= 27.0) {
        sprintf(sky, "Clear");
        sprintf(rain, "No");
        sprintf(snow, "No");
    }
    else if (humidity >= 5.0 && temperature >= 25.0) {
        sprintf(sky, "Partly Cloudy");
        sprintf(rain, "No");
        sprintf(snow, "No");
    }
    else if (humidity >= 3.0 && temperature >= 20.0) {
        sprintf(sky, "Mostly Cloudy");
        sprintf(rain, "No");
        sprintf(snow, "No");
    }
    else if (humidity >= 1.0 && temperature >= 15.0) {
        sprintf(sky, "Cloudy");
        sprintf(rain, "No");
        sprintf(snow, "No");
    }
    else if (humidity >= 0.5 && temperature >= 10.0) {
        sprintf(sky, "Rainy");
        sprintf(rain, "Yes");
        sprintf(snow, "No");
    }
    else if (humidity >= 0.3 && temperature >= 5.0) {
        sprintf(sky, "Snowy");
        sprintf(rain, "No");
        sprintf(snow, "Yes");
    }
    else {
        sprintf(sky, "Blizzard");
        sprintf(rain, "No");
        sprintf(snow, "Yes");
    }

    printf("Temperature: %0.1f C\n", temperature);
    printf("Humidity: %0.1f %%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);
    printf("Wind Direction: %d degrees\n", wind_direction);
    printf("Sky: %s\n", sky);
    printf("Rain: %s\n", rain);
    printf("Snow: %s\n", snow);
    
    return 0;
}