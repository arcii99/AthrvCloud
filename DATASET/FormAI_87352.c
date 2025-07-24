//FormAI DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 120
#define MIN_TEMP 32
#define TEMP_RANGE (MAX_TEMP - MIN_TEMP)

double get_temperature() {
    double temperature = ((double)(rand() % TEMP_RANGE) + MIN_TEMP) + ((double)(rand() % 100) / 100.0);
    return temperature;
}

int main() {
    srand(time(NULL));

    double temperature = get_temperature();
    char temperature_str[10];

    while (1) {
        if (temperature > MAX_TEMP) {
            printf("Temperature is too high!\n");
        } else if (temperature < MIN_TEMP) {
            printf("Temperature is too low!\n");
        } else {
            sprintf(temperature_str, "%.2f", temperature);
            printf("Current temperature is: %s\n", temperature_str);
        }

        sleep(5);
        temperature = get_temperature();
    }

    return 0;
}