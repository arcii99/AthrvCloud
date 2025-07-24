//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int temperature, humidity, windspeed, precipitation;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Weather Simulation Program!\n\n");

    // generate random values for weather parameters
    temperature = rand() % 60 - 10; // temperature between -10C and 50C
    humidity = rand() % 101; // humidity between 0% and 100%
    windspeed = rand() % 101; // windspeed between 0mph and 100mph
    precipitation = rand() % 101; // precipitation between 0mm and 100mm

    // Output the weather report
    printf("Today's Weather Report:\n");
    printf("Temperature: %dC\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Windspeed: %dmph\n", windspeed);
    printf("Precipitation: %dmm\n\n", precipitation);

    // Determine the weather conditions based on parameters
    if (temperature < 0) {
        printf("It's freezing outside!");
    } else if (temperature >= 0 && temperature < 10) {
        printf("It's very cold outside.");
    } else if (temperature >= 10 && temperature < 20) {
        printf("It's chilly outside.");
    } else if (temperature >= 20 && temperature < 30) {
        printf("It's comfortable outside.");
    } else if (temperature >= 30 && temperature < 40) {
        printf("It's hot outside.");
    } else {
        printf("It's scorching outside!");
    }

    if (humidity < 30) {
        printf(" The air is dry.");
    } else if (humidity >= 30 && humidity < 60) {
        printf(" The air is humid.");
    } else {
        printf(" The air is very humid!");
    }

    if (windspeed < 10) {
        printf(" There's barely any wind today, so it should feel warmer.");
    } else if (windspeed >= 10 && windspeed < 30) {
        printf(" There's a moderate breeze outside.");
    } else if (windspeed >= 30 && windspeed < 60) {
        printf(" There's a strong wind outside, so be careful!");
    } else {
        printf(" There's a hurricane outside! Stay indoors.");
    }

    if (precipitation == 0) {
        printf(" There's no chance of rain today.");
    } else if (precipitation > 0 && precipitation < 25) {
        printf(" There may be some light showers today.");
    } else if (precipitation >= 25 && precipitation < 50) {
        printf(" There's a good chance of rain today.");
    } else if (precipitation >= 50 && precipitation < 75) {
        printf(" There may be some heavy rain today. Don't forget your umbrella!");
    } else {
        printf(" It's a monsoon outside! Stay indoors and stay safe.");
    }

    printf("\n\nThank you for checking the Weather Simulation Program. Stay safe!\n");

    return 0;
}