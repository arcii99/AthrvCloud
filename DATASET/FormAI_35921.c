//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity, wind_speed, rainfall;
    srand(time(0)); // to generate random values

    temperature = rand() % 50; // temperature range from 0 to 50 degree Celsius
    humidity = rand() % 100; // humidity range from 0 to 100 percent
    wind_speed = rand() % 50; // wind speed range from 0 to 50 kmph
    rainfall = rand() % 100; // rainfall range from 0 to 100 mm/month

    printf("Today's weather simulation:\n");
    printf("Temperature: %d degree Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d kmph\n", wind_speed);
    printf("Rainfall: %d mm/month\n", rainfall);

    // weather conditions based on temperature, humidity, wind speed and rainfall
    if (temperature >= 30 && humidity >= 60 && rainfall < 50) {
        printf("It's a hot and humid day. Drink plenty of water and stay indoors.\n");
    }
    else if (temperature <= 10 && wind_speed >= 25 && rainfall >= 50) {
        printf("It's a cold and windy day with heavy rainfall. Stay warm and dry.\n");
    }
    else if (wind_speed >= 50) {
        printf("It's a stormy day. Stay indoors and be cautious.\n");
    }
    else {
        printf("Weather conditions are normal today. Enjoy your day!\n");
    }

    return 0;
}