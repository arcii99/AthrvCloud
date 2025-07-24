//FormAI DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_float(float min, float max) {
    return (max - min) * (((float) rand()) / ((float) RAND_MAX)) + min;
}

int main(void) {
    srand(time(NULL));

    float temperature = rand_float(20.0, 30.0);

    printf("Current temperature: %0.2f C\n", temperature);

    if (temperature < 25.0) {
        printf("The temperature is too low, consider turning up the heat.\n");
    } else if (temperature > 27.0) {
        printf("The temperature is too high, consider turning down the heat.\n");
    } else {
        printf("The temperature is just right.\n");
    }

    return 0;
}