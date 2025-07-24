//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    float temperature_array[10];
    float min_temperature, max_temperature, avg_temperature, sum_temperature;
    int i;
    time_t t;

    // Generate a seed for random number generation
    srand((unsigned) time(&t));

    printf("Temperature Monitor\n");

    // Generate random temperatures
    for (i = 0; i < 10; i++){
        temperature_array[i] = (float) ((rand() % 10000) - 5000) / 100;
        printf("Temperature reading #%d: %.2f°C\n", i+1, temperature_array[i]);
    }

    // Calculate minimum temperature
    min_temperature = temperature_array[0];
    for (i = 1; i < 10; i++){
        if (temperature_array[i] < min_temperature){
            min_temperature = temperature_array[i];
        }
    }
    printf("Minimum temperature: %.2f°C\n", min_temperature);

    // Calculate maximum temperature
    max_temperature = temperature_array[0];
    for (i = 1; i < 10; i++){
        if (temperature_array[i] > max_temperature){
            max_temperature = temperature_array[i];
        }
    }
    printf("Maximum temperature: %.2f°C\n", max_temperature);

    // Calculate average temperature
    sum_temperature = 0;
    for (i = 0; i < 10; i++){
        sum_temperature += temperature_array[i];
    }
    avg_temperature = sum_temperature / 10;
    printf("Average temperature: %.2f°C\n", avg_temperature);

    return 0;
}