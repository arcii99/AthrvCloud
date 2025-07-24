//FormAI DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));  //set seed for random number generation
    int temperature = 25;  //starting temperature
    int humidity = 70;  //starting humidity
    int pressure = 101.3;  //starting pressure
    int wind_speed = 5;  //starting wind speed
    int clouds = 50;  //starting cloud coverage
    int day_count = 0;  //starting day count

    printf("Welcome to the Weather Simulator!\n");

    while (day_count < 7) {  //simulate weather for a week
        printf("\n================ DAY %d ================\n", day_count+1);

        //generate random temperature change
        int temp_change = rand() % 11 - 5;  //change between -5 and 5 degrees Celsius
        temperature += temp_change;
        printf("Temperature: %dC\n", temperature);

        //generate random humidity change
        int humid_change = rand() % 11 - 5;  //change between -5% and 5%
        humidity += humid_change;
        printf("Humidity: %d%%\n", humidity);

        //generate random pressure change
        float press_change = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;  //change between -1.0 and 1.0 kPa
        pressure += press_change;
        printf("Pressure: %.1fkPa\n", pressure);

        //generate random wind speed change
        int wind_change = rand() % 6 - 2;  //change between -2 and 3 m/s
        wind_speed += wind_change;
        printf("Wind Speed: %dm/s\n", wind_speed);

        //generate random cloud coverage change
        int cloud_change = rand() % 11 - 5;  //change between -5% and 5%
        clouds += cloud_change;
        printf("Cloud Coverage: %d%%\n", clouds);

        day_count++;
    }

    printf("\nThank you for using the Weather Simulator!\n");

    return 0;
}