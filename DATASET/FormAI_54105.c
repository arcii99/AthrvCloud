//FormAI DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // initialize random seed

    int temperature, humidity, pressure;
    temperature = rand() % 50 - 10; // generate random temperature between -10°C and 40°C
    humidity = rand() % 101; // generate random humidity between 0% and 100%
    pressure = rand() % 1013 + 990; // generate random pressure between 990 hPa and 2003 hPa

    printf("The current weather simulation:\n");
    printf("Temperature: %d°C\nHumidity: %d%%\nPressure: %dhPa\n", temperature, humidity, pressure);

    // Determine weather conditions based on values

    if (temperature < 0) {
        puts("It's freezing outside!");
    } else if (temperature < 10) {
        if (humidity > 70) {
            puts("It's wet and chilly!");
        } else {
            puts("It's chilly outside!");
        }
    } else if (temperature < 20) {
        if (humidity > 70) {
            puts("It's humid and mild!");
        } else {
            puts("It's mild outside!");
        }
    } else if (temperature < 30) {
        if (humidity > 70) {
            puts("It's humid and warm!");
        } else {
            puts("It's warm outside!");
        }
    } else if (temperature < 40) {
        if (humidity > 70) {
            puts("It's humid and hot!");
        } else {
            puts("It's hot outside!");
        }
    } else {
        puts("It's scorching outside!");
    }

    if (pressure < 990) {
        puts("The pressure is extremely low!");
    } else if (pressure < 1000) {
        puts("The pressure is low!");
    } else if (pressure < 1013) {
        puts("The pressure is normal.");
    } else if (pressure < 1030) {
        puts("The pressure is high!");
    } else {
        puts("The pressure is extremely high!");
    }

    return 0;
}