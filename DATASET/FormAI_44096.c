//FormAI DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int day, month, year, temperature;
    char weather[10];
    srand(time(NULL)); // seed random number generator
    
    // generate random weather condition and temperature
    int weatherCondition = rand() % 3;
    if (weatherCondition == 0) {
        strcpy(weather, "rainy");
        temperature = rand() % 10 + 10;
    } else if (weatherCondition == 1) {
        strcpy(weather, "cloudy");
        temperature = rand() % 15 + 15;
    } else {
        strcpy(weather, "sunny");
        temperature = rand() % 20 + 25;
    }
    
    // generate random date within past 30 days
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    day = tm->tm_mday - rand() % 30;
    month = tm->tm_mon + 1;
    year = tm->tm_year + 1900;
    
    // print weather forecast for the randomly generated date
    printf("On %d/%d/%d, the weather will be %s with a temperature of %d degrees Celsius.\n", day, month, year, weather, temperature);
    
    return 0;
}