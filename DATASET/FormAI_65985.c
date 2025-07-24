//FormAI DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_BOUND -50
#define UPPER_BOUND 150
#define NUM_READINGS 10
#define MIN_ACCEPTABLE_TEMP 0
#define MAX_ACCEPTABLE_TEMP 100

float readings[NUM_READINGS];

float get_temperature_reading() {
    float temp_reading = (float) (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;
    return temp_reading;
}

float get_average_temperature() {
    float total = 0;
    for(int i = 0; i < NUM_READINGS; i++) {
        total += readings[i];
    }
    float average = total / NUM_READINGS;
    return average;
}

int main(void) {
    srand(time(0));
    printf("Welcome to the temperature monitor!\n\n");
    for(int i = 0; i < NUM_READINGS; i++) {
        float temp_reading = get_temperature_reading();
        readings[i] = temp_reading;
        printf("Temperature reading %d: %.2f °C\n", i+1, temp_reading);
    }
    printf("\n");
    float average_temp = get_average_temperature();
    printf("The average temperature reading is: %.2f °C\n", average_temp);
    if(average_temp < MIN_ACCEPTABLE_TEMP || average_temp > MAX_ACCEPTABLE_TEMP) {
        printf("ALERT: Average temperature is outside acceptable range!\n");
    } else {
        printf("Average temperature is within acceptable range.\n");
    }
    return 0;
}