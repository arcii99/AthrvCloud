//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SENSOR_MAX_RANGE 100
#define SENSOR_MIN_RANGE -50

float get_temperature() {
    float temp = ((float)rand()/(float)(RAND_MAX)) * (SENSOR_MAX_RANGE - SENSOR_MIN_RANGE) + SENSOR_MIN_RANGE;
    return temp;
}

int main() {
    srand(time(NULL));
    float temperature;
    while(1) {
        temperature = get_temperature();
        printf("Current temperature: %.2f°C\n", temperature);
        sleep(1);
    }
    return 0;
}