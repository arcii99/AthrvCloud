//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define thread data structure
typedef struct {
    pthread_t tid;
    int number;
} thread_data_t;

// Define vehicle data structure
typedef struct {
    int speed;
    int direction;
} vehicle_t;

// Function that simulates the remote control vehicle movement
void* move_vehicle(void* arg) {
    vehicle_t* vehicle = (vehicle_t*) arg;
    
    while (1) {
        printf("Vehicle speed: %d\n", vehicle->speed);
        printf("Vehicle direction: %d\n", vehicle->direction);
        sleep(1);
    }
    
    return NULL;
}

// Main function
int main() {
    // Initialize vehicle object
    vehicle_t vehicle = {0, 0};
    
    // Define threads
    thread_data_t thread_speed, thread_direction;
    
    // Create speed thread
    thread_speed.number = 1;
    pthread_create(&thread_speed.tid, NULL, move_vehicle, &vehicle);
    
    // Create direction thread
    thread_direction.number = 2;
    pthread_create(&thread_direction.tid, NULL, move_vehicle, &vehicle);
    
    // Join threads
    pthread_join(thread_speed.tid, NULL);
    pthread_join(thread_direction.tid, NULL);
    
    return 0;
}