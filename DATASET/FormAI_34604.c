//FormAI DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_SENSORS 5
#define MAX_TEMP 100.0
#define MIN_TEMP 0.0

typedef struct {
    int id;
    float temp;
} Sensor;

void updateTemperature(float*, int);
void printTemperatures(Sensor*, int);
float generateRandomTemp(float, float);

int main() {
    Sensor sensors[NUM_SENSORS];

    // initialize sensors
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensors[i].id = i+1;
        sensors[i].temp = generateRandomTemp(MIN_TEMP, MAX_TEMP);
    }

    // monitor temperatures every second
    printf("Monitoring temperatures...\n");
    while(1) {
        updateTemperature(&sensors[0].temp, NUM_SENSORS);
        printTemperatures(sensors, NUM_SENSORS);
        sleep(1);
    }
    return 0;
}

void updateTemperature(float* tempArray, int len) {
    for (int i = 0; i < len; i++) {
        *(tempArray+i) = generateRandomTemp(MIN_TEMP, MAX_TEMP);
    }
}

void printTemperatures(Sensor* sensors, int len) {
    printf("Sensor\tTemperature\n");
    for (int i = 0; i < len; i++) {
        printf("%d\t%.2f\n", sensors[i].id, sensors[i].temp);
    }
}

float generateRandomTemp(float min, float max) {
    float range = max - min;
    return ((float) rand() / RAND_MAX * range) + min;
}