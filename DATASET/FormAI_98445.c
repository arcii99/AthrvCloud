//FormAI DATASET v1.0 Category: Smart home automation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROOMS 3
#define NUM_SENSORS 4
#define NUM_DEVICES 4

typedef struct {
    int id;
    bool motion_detected;
    int temperature;
} sensor_t;

typedef struct {
    int id;
    bool connected;
} device_t;

sensor_t sensors[NUM_ROOMS][NUM_SENSORS];
device_t devices[NUM_ROOMS][NUM_DEVICES];

void initialize_sensors() {
    for(int i=0; i<NUM_ROOMS; i++) {
        for(int j=0; j<NUM_SENSORS; j++) {
            sensors[i][j].id = i*10 + j;
            sensors[i][j].motion_detected = false;
            sensors[i][j].temperature = 0;
        }
    }
}

void initialize_devices() {
    for(int i=0; i<NUM_ROOMS; i++) {
        for(int j=0; j<NUM_DEVICES; j++) {
            devices[i][j].id = i*10 + j;
            devices[i][j].connected = false;
        }
    }
}

void update_sensor_data() {
    for(int i=0; i<NUM_ROOMS; i++) {
        for(int j=0; j<NUM_SENSORS; j++) {
            sensors[i][j].motion_detected = rand()%2;
            sensors[i][j].temperature = rand()%30;
        }
    }
}

void detect_intrusion(int room) {
    bool intrusion_detected = false;
    for(int i=0; i<NUM_SENSORS; i++) {
        if(sensors[room][i].motion_detected == true) {
            intrusion_detected = true;
            break;
        }
    }
    if(intrusion_detected) {
        printf("Intrusion detected in Room %d!\n", room);
        for(int i=0; i<NUM_DEVICES; i++) {
            if(devices[room][i].connected) {
                printf("Sending notification to device %d\n", devices[room][i].id);
            }
        }
    }
}

void control_temperature(int room) {
    int avg_temp = 0;
    for(int i=0; i<NUM_SENSORS; i++) {
        avg_temp += sensors[room][i].temperature;
    }
    avg_temp /= NUM_SENSORS;
    printf("Average temperature in Room %d: %d\n", room, avg_temp);
    if(avg_temp > 25) {
        for(int i=0; i<NUM_DEVICES; i++) {
            if(devices[room][i].connected) {
                printf("Turning on AC in device %d to cool the room\n", devices[room][i].id);
            }
        }
    } else if(avg_temp < 15) {
        for(int i=0; i<NUM_DEVICES; i++) {
            if(devices[room][i].connected) {
                printf("Turning on Heater in device %d to warm the room\n", devices[room][i].id);
            }
        }
    }
}

int main() {
    initialize_sensors();
    initialize_devices();
    while(true) {
        update_sensor_data();
        for(int i=0; i<NUM_ROOMS; i++) {
            detect_intrusion(i);
            control_temperature(i);
        }
        printf("\n");
        sleep(5); //wait for 5 seconds before updating sensor data again
    }
    return 0;
}