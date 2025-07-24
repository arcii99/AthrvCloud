//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMP_HIGH 80
#define TEMP_LOW 60

struct temp_sensor {
    int id;
    float temperature;
};

int main(void) {
    struct temp_sensor sensor1, sensor2, sensor3;
    char status1[10], status2[10], status3[10];

    sensor1.id = 1;
    sensor1.temperature = 72.5;
    sensor2.id = 2;
    sensor2.temperature = 85.0;
    sensor3.id = 3;
    sensor3.temperature = 54.0;

    // Determine status of temperature readings for sensor 1
    if (sensor1.temperature > TEMP_HIGH) {
        strcpy(status1, "high");
    } else if (sensor1.temperature < TEMP_LOW) {
        strcpy(status1, "low");
    } else {
        strcpy(status1, "normal");
    }

    // Determine status of temperature readings for sensor 2
    if (sensor2.temperature > TEMP_HIGH) {
        strcpy(status2, "high");
    } else if (sensor2.temperature < TEMP_LOW) {
        strcpy(status2, "low");
    } else {
        strcpy(status2, "normal");
    }

    // Determine status of temperature readings for sensor 3
    if (sensor3.temperature > TEMP_HIGH) {
        strcpy(status3, "high");
    } else if (sensor3.temperature < TEMP_LOW) {
        strcpy(status3, "low");
    } else {
        strcpy(status3, "normal");
    }

    // Output temperature readings and statuses
    printf("Sensor %d - Temperature reading: %.1f, Status: %s\n", sensor1.id, sensor1.temperature, status1);
    printf("Sensor %d - Temperature reading: %.1f, Status: %s\n", sensor2.id, sensor2.temperature, status2);
    printf("Sensor %d - Temperature reading: %.1f, Status: %s\n", sensor3.id, sensor3.temperature, status3);

    return 0;
}