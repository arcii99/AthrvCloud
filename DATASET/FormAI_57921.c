//FormAI DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    // Declare weather conditions and temperatures
    char* conditions[] = {"Sunny", "Cloudy", "Rainy", "Snowy"};
    int temps[] = {70, 60, 50, 40, 30, 20};
    // Generate random weather condition and temperature
    int rand_cond = rand() % 4;
    int rand_temp = temps[rand() % 6];
    // Print weather report
    printf("Today's weather is %s with a temperature of %d degrees Fahrenheit.\n", conditions[rand_cond], rand_temp);
    printf("What is your location (city, state/province, country)?\n");
    char location[50];
    scanf("%s", location);
    printf("Here is the weather forecast for %s:\n", location);
    // Generate forecast by adding or subtracting up to 10 degrees from current temperature
    for (int i = 1; i <= 5; i++) {
        int temp_change = rand() % 21 - 10;
        int forecast_temp = rand_temp + temp_change;
        if (forecast_temp <= 32) {
            printf("Day %d: %d degrees Fahrenheit and snowy.\n", i, forecast_temp);
        } else if (forecast_temp <= 45) {
            printf("Day %d: %d degrees Fahrenheit and rainy.\n", i, forecast_temp);
        } else if (forecast_temp <= 65) {
            printf("Day %d: %d degrees Fahrenheit and cloudy.\n", i, forecast_temp);
        } else {
            printf("Day %d: %d degrees Fahrenheit and sunny.\n", i, forecast_temp);
        }
    }
    return 0;
}