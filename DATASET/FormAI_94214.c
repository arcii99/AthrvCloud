//FormAI DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seeding the random number generator
    int temperature = (rand() % 50) - 20; // generates a random temperature between -20 and 30 degrees Celsius
    int humidity = rand() % 101; // generates a random humidity level between 0% and 100%
    int wind_speed = rand() % 80; // generates a random wind speed between 0 and 80 km/h
    int wind_direction = rand() % 360; // generates a random wind direction in degrees

    printf("Current temperature: %d degrees Celsius\n", temperature);
    printf("Current humidity: %d%%\n", humidity);

    if (temperature < 0) {
        printf("It is extremely cold today. Make sure to dress warmly!\n");
    } else if (temperature >= 0 && temperature < 10) {
        printf("It is cold out there. Please wear a jacket.\n");
    } else if (temperature >= 10 && temperature < 20) {
        printf("It is cool today. You may not need a jacket, but take something warm with you.\n");
    } else if (temperature >= 20 && temperature < 30) {
        printf("It is warm today. A t-shirt and shorts will be perfect.\n");
    } else {
        printf("It is hot today. Make sure to hydrate yourself frequently.\n");
    }

    if (humidity < 30) {
        printf("It is dry out there. Carry a moisturizer and drink lots of water.\n");
    } else if (humidity >= 30 && humidity < 70) {
        printf("It is mildly humid today. You may not notice it much.\n");
    } else {
        printf("It is very humid today. You may feel sweaty and uncomfortable.\n");
    }

    if (wind_speed < 20) {
        printf("It is a calm day today. The wind won't affect you much.\n");
    } else if (wind_speed >= 20 && wind_speed < 50) {
        printf("It is a windy day today. Make sure to take care of your belongings.\n");
    } else {
        printf("It is a very windy day today. Be careful when you are walking outside.\n");
    }

    char wind_direction_text[16]; // to store the wind direction text
    if (wind_direction >= 0 && wind_direction < 45) {
        sprintf(wind_direction_text, "North");
    } else if (wind_direction >= 45 && wind_direction < 90) {
        sprintf(wind_direction_text, "North-East");
    } else if (wind_direction >= 90 && wind_direction < 135) {
        sprintf(wind_direction_text, "East");
    } else if (wind_direction >= 135 && wind_direction < 180) {
        sprintf(wind_direction_text, "South-East");
    } else if (wind_direction >= 180 && wind_direction < 225) {
        sprintf(wind_direction_text, "South");
    } else if (wind_direction >= 225 && wind_direction < 270) {
        sprintf(wind_direction_text, "South-West");
    } else if (wind_direction >= 270 && wind_direction < 315) {
        sprintf(wind_direction_text, "West");
    } else if (wind_direction >= 315 && wind_direction < 360) {
        sprintf(wind_direction_text, "North-West");
    }

    printf("The wind is blowing from the %s at a speed of %d km/h.\n", wind_direction_text, wind_speed);
    return 0;
}