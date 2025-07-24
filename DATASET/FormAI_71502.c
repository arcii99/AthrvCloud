//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random temperature for each sensor
float generateTemp() {
    float temp = (float)rand()/(float)(RAND_MAX/100);
    return temp;
}

// data structure to hold information about each temperature sensor
struct Sensor {
    char name[50];
    float temperature;
    char location[50];
    int status; // 1 - Active, 0 - Inactive
};

// function to print details of each sensor
void printSensorDetails(struct Sensor sensor) {
    printf("Sensor Name: %s\n", sensor.name);
    printf("Temperature: %.2f\n", sensor.temperature);
    printf("Location: %s\n", sensor.location);
    printf("Status: %s\n", (sensor.status == 1) ? "Active" : "Inactive");
}

int main() {
    // array to hold all the temperature sensors
    struct Sensor sensors[5];
    
    // initialize values for each sensor
    sprintf(sensors[0].name, "Sensor 1");
    sensors[0].temperature = generateTemp();
    sprintf(sensors[0].location, "Room A");
    sensors[0].status = 1;
    
    sprintf(sensors[1].name, "Sensor 2");
    sensors[1].temperature = generateTemp();
    sprintf(sensors[1].location, "Room B");
    sensors[1].status = 1;
    
    sprintf(sensors[2].name, "Sensor 3");
    sensors[2].temperature = generateTemp();
    sprintf(sensors[2].location, "Room A");
    sensors[2].status = 0;
    
    sprintf(sensors[3].name, "Sensor 4");
    sensors[3].temperature = generateTemp();
    sprintf(sensors[3].location, "Room C");
    sensors[3].status = 1;
    
    sprintf(sensors[4].name, "Sensor 5");
    sensors[4].temperature = generateTemp();
    sprintf(sensors[4].location, "Room B");
    sensors[4].status = 0;
    
    // printing details of each sensor
    for(int i = 0; i < 5; i++) {
        printSensorDetails(sensors[i]);
        printf("\n");
    }
    
    return 0;
}