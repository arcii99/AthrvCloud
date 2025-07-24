//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

// Define constants
#define MAX_SENSORS 10
#define MAX_TEMPERATURE 100.0
#define MIN_TEMPERATURE -100.0
#define TEMPERATURE_DIFF_THRESHOLD 10.0

// Define struct to store sensor data
typedef struct sensor {
    int id;
    double temperature;
} Sensor;

// Define function to generate random temperature
double generate_temperature() {
    return (double)rand() / RAND_MAX * (MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE;
}

int main() {

    // Initialize array of sensors
    Sensor sensors[MAX_SENSORS];
    int num_sensors = 0;

    // Add sensors to array
    for(int i=0; i<MAX_SENSORS; i++) {
        sensors[i].id = i+1;
        sensors[i].temperature = generate_temperature();
        num_sensors++;
    }

    // Print initial sensor data
    printf("Initial sensor data:\n");
    for(int i=0; i<num_sensors; i++) {
        printf("Sensor %d: %.2lf\n", sensors[i].id, sensors[i].temperature);
    }

    // Check for temperature differences and print warning if necessary
    printf("\nChecking for temperature differences...\n");
    for(int i=0; i<num_sensors-1; i++) {
        for(int j=i+1; j<num_sensors; j++) {
            double diff = abs(sensors[i].temperature - sensors[j].temperature);
            if(diff > TEMPERATURE_DIFF_THRESHOLD) {
                printf("WARNING: Sensor %d and Sensor %d have a temperature difference of %.2lf\n", sensors[i].id, sensors[j].id, diff);
            }
        }
    }

    return 0;
}