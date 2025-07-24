//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int temperature = rand() % 41 - 10; // Temperature ranges from -10 to 30 degree Celsius
    int humidity = rand() % 101; //Humidity ranges from 0% to 100%
    float pressure = (float)(rand() % 101 + 900); //Pressure ranges from 900 to 1000 hPa

    printf("Today's weather simulation: \n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %.1f hPa\n", pressure);

    //Analyzing temperature 
    if (temperature < 0) {
        printf("It's freezing out there!\n");
    } else if (temperature >= 0 && temperature < 10) {
        printf("It's very cold outside.\n");
    } else if (temperature >= 10 && temperature < 20) {
        printf("It's chilled outside.\n");
    } else if (temperature >= 20 && temperature < 30) {
        printf("It's warm outside.\n");
    } else {
        printf("It's hot outside!\n");
    }

    //Analyzing humidity
    if (humidity < 30) {
        printf("It's very dry outside.\n");
    } else if (humidity >= 30 && humidity < 60) {
        printf("It's moderately humid outside.\n");
    } else {
        printf("It's very humid outside!\n");
    }

    //Analyzing pressure 
    if (pressure < 950) {
        printf("There is a low pressure system.\n");
    } else if (pressure >= 950 && pressure < 1000) {
        printf("The pressure is just right.\n");
    } else {
        printf("There is a high pressure system.\n");
    }

    return 0;
}