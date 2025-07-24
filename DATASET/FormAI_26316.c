//FormAI DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_MIN -20
#define TEMP_MAX 50

int get_random_temperature() {
    int temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    return temperature;
}

void print_weather_simulation(int temperature) {
    printf("Temperature: %dC\n", temperature);

    if (temperature <= 0) {
        printf("It's freezing outside! Make sure to dress warmly.\n");
    } else if (temperature > 0 && temperature <= 15) {
        printf("It's chilly outside. A light jacket may be needed.\n");
    } else if (temperature > 15 && temperature <= 25) {
        printf("It's a beautiful day! Enjoy the sunshine.\n");
    } else if (temperature > 25 && temperature <= 35) {
        printf("It's hot out! Make sure to stay hydrated.\n");
    } else {
        printf("It's scorching out there! Stay indoors if possible.\n");
    }
}

int main() {
    srand(time(NULL));
    
    int temperature = get_random_temperature();

    print_weather_simulation(temperature);

    return 0;
}