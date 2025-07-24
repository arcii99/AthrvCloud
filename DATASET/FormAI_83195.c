//FormAI DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random temperature
int generate_temperature(int min_temp, int max_temp) {
    return (rand() % (max_temp - min_temp + 1)) + min_temp;
}

// function to simulate the weather
void simulate_weather(int num_days, int min_temp, int max_temp, const char *city_name) {
    srand(time(NULL)); // initialize random number generator

    // print header
    printf("Weather forecast for %s for the next %d days:\n", city_name, num_days);
    printf("------------------------------------------------------\n");
    printf("Day       Temperature (C)\n");

    // loop over each day and generate a temperature
    for (int i = 1; i <= num_days; i++) {
        int temperature = generate_temperature(min_temp, max_temp);
        printf("%-10d%d\n", i, temperature);
    }
}

int main() {
    // simulate weather for different cities and temperature ranges
    simulate_weather(7, 10, 20, "Paris");
    printf("\n");
    simulate_weather(14, 0, 10, "New York");
    printf("\n");
    simulate_weather(30, 20, 40, "Dubai");

    return 0;
}