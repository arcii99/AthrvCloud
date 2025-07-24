//FormAI DATASET v1.0 Category: Weather simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    int temperature = (rand() % (105 - 20 + 1)) + 20; // Temperature range between 20 to 105 degrees Fahrenheit
    int wind_speed = (rand() % (60 - 0 + 1)) + 0; // Wind speed range between 0 to 60 mph.
    int precipitation = (rand() % (50 - 0 + 1)) + 0; // Precipitation range between 0 to 50 percent.
    int cloud_cover = (rand() % (100 - 0 + 1)) + 0; // Cloud cover range between 0 to 100 percent.
    int humidity = (rand() % (100 - 0 + 1)) + 0; // Humidity range between 0 to 100 percent.
    printf("Temperature: %dF\n", temperature);
    printf("Wind Speed: %dmph\n", wind_speed);
    printf("Precipitation: %d%%\n", precipitation);
    printf("Cloud Cover: %d%%\n", cloud_cover);
    printf("Humidity: %d%%\n", humidity);

    if(temperature <= 32 && precipitation > 0){ // If temperature is below freezing point and precipitation is greater than 0, then it will snow.
        printf("It is snowing today.\n");
    }
    else if(temperature <= 40 && precipitation > 0){ // If temperature is below 40 and precipitation is greater than 0, then it will be raining.
        printf("It is raining today.\n");
    }
    else if(wind_speed >= 25){ // If wind speed is greater than or equal to 25mph, then it will be windy.
        printf("It is windy today.\n");
    }
    else if(cloud_cover >= 75){ // If cloud cover is greater than or equal to 75%, then it will be cloudy.
        printf("It is cloudy today.\n");
    }
    else if(temperature >= 90 && humidity >= 50){ // If temperature is greater than or equal to 90F and humidity is greater than or equal to 50%, then it will be humid.
        printf("It is humid today.\n");
    }
    else{
        printf("It's a beautiful day outside.\n"); // If none of the above conditions apply then it's a beautiful day outside.
    }

    return 0;
}