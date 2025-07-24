//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int x; // x-coordinate of the vehicle
    int y; // y-coordinate of the vehicle
    float xPos; // x-position of the vehicle
    float yPos; // y-position of the vehicle
    float speed; // speed of the vehicle
    float direction; // direction of the vehicle
} Vehicle;

static void* simulate(Vehicle* v) {
    while (1) {
        // Update position of the vehicle based on speed and direction
        v->xPos += v->speed * cos(v->direction);
        v->yPos += v->speed * sin(v->direction);
        
        // Update x-coordinate and y-coordinate based on x-position and y-position
        v->x = (int) round(v->xPos);
        v->y = (int) round(v->yPos);
        
        // Print current position of the vehicle
        printf("Current position: (%d, %d)\n", v->x, v->y);
        
        usleep(50000); // Wait for 50 milliseconds before next update
    }
    return NULL;
}

int main() {
    // Create vehicle instance with initial values
    Vehicle v = { 0, 0, 0.0, 0.0, 0.0, 0.0 };
    
    // Create thread for the vehicle simulation
    pthread_t simThread;
    if (pthread_create(&simThread, NULL, (void*) &simulate, &v)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    
    // Loop for receiving commands from remote control
    char input[256];
    while (1) {
        printf("Enter command: ");
        fgets(input, 256, stdin);
        
        if (!strncasecmp(input, "quit", 4)) {
            break; // Quit program if command is "quit"
        }
        
        if (!strncasecmp(input, "speed", 5)) {
            float speed = atof(input + 6);
            v.speed = speed; // Set speed of vehicle if command is "speed"
        }
        
        if (!strncasecmp(input, "direction", 9)) {
            float direction = atof(input + 10);
            v.direction = direction; // Set direction of vehicle if command is "direction"
        }
    }
    
    // Wait for simulation thread to finish before exiting program
    if (pthread_join(simThread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 1;
    }
    
    return 0;
}