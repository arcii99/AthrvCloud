//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_ROOMS 3
#define NUM_DEVICES 3

// Room and Device structs
struct Room {
    int light;
    int temperature;
    int humidity;
    bool isOccupied;
};
typedef struct Room Room;

struct Device {
    bool isOn;
};
typedef struct Device Device;

// Global arrays to hold Room and Device data
Room rooms[NUM_ROOMS];
Device devices[NUM_DEVICES];

// Function prototypes
void* motionDetection(void*);
void* temperatureControl(void*);
void* lightControl(void*);

int main() {

    // Initialize the data for the smart home
    rooms[0].light = 50;
    rooms[0].temperature = 70;
    rooms[0].humidity = 45;
    rooms[0].isOccupied = true;

    rooms[1].light = 75;
    rooms[1].temperature = 65;
    rooms[1].humidity = 60;
    rooms[1].isOccupied = false;

    rooms[2].light = 25;
    rooms[2].temperature = 80;
    rooms[2].humidity = 50;
    rooms[2].isOccupied = false;

    devices[0].isOn = false;
    devices[1].isOn = false;
    devices[2].isOn = true;

    // Create threads for the asynchronous functions
    pthread_t motionThread;
    pthread_t temperatureThread;
    pthread_t lightThread;

    pthread_create(&motionThread, NULL, motionDetection, NULL);
    pthread_create(&temperatureThread, NULL, temperatureControl, NULL);
    pthread_create(&lightThread, NULL, lightControl, NULL);

    // Join the threads to the main thread when they finish
    pthread_join(motionThread, NULL);
    pthread_join(temperatureThread, NULL);
    pthread_join(lightThread, NULL);

    return 0;
}

// Function to simulate motion detection and adjust device state
void* motionDetection(void* arg) {

    while(true) {
        int count = 0;
        for(int i=0; i<NUM_ROOMS; i++) {
            if(rooms[i].isOccupied == true) {
                count++;
            }
        }
        if(count > 0) {
            for(int i=0; i<NUM_DEVICES; i++) {
                devices[i].isOn = true;
            }
        } else {
            for(int i=0; i<NUM_DEVICES; i++) {
                devices[i].isOn = false;
            }
        }
        usleep(500000);
    }
}

// Function to simulate temperature control and adjust room temperature
void* temperatureControl(void* arg) {
    while(true) {
        for(int i=0; i<NUM_ROOMS; i++) {
            if(rooms[i].isOccupied == true) {
                if(rooms[i].temperature > 70) {
                    rooms[i].temperature--;
                } else if(rooms[i].temperature < 70) {
                    rooms[i].temperature++;
                }
            }
        }
        usleep(1000000);
    }
}

// Function to simulate light control and adjust room light level
void* lightControl(void* arg) {
    while(true) {
        for(int i=0; i<NUM_ROOMS; i++) {
            if(rooms[i].isOccupied == true) {
                if(rooms[i].light > 50) {
                    rooms[i].light--;
                } else if(rooms[i].light < 50) {
                    rooms[i].light++;
                }
            }
        }
        usleep(500000);
    }
}