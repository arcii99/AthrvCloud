//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100

float get_current_temp(void) {
    srand(time(NULL));  // seed random number generator with current time
    return MIN_TEMP + rand() / (RAND_MAX / (MAX_TEMP - MIN_TEMP + 1) + 1.0);
}

int main(void) {
    float current_temp = get_current_temp();
    printf("Current temperature is: %.2f\n", current_temp);

    if (current_temp < 0) {
        printf("It's freezing out here!\n");
    } else if (current_temp >= 0 && current_temp < 25) {
        printf("It's a bit chilly, wear a jacket!\n");
    } else if (current_temp >= 25 && current_temp < 50) {
        printf("It's getting warmer, a light sweater will do!\n");
    } else if (current_temp >= 50 && current_temp < 75) {
        printf("It's quite warm, a t-shirt will suffice!\n");
    } else if (current_temp >= 75 && current_temp <= 100) {
        printf("It's hot outside, stay hydrated!\n");
    } else {
        printf("Invalid temperature value!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}