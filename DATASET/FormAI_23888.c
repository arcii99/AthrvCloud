//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define STATE_TIME 5
#define YELLOWSTATE_TIME 2

int currentState;

pthread_mutex_t mutex;

// Function to change the state of the traffic light
void changeState(int newState) {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Print out the current state and the new state
    printf("Traffic Light State: %d -> %d\n", currentState, newState);

    // Update the current state
    currentState = newState;

    // Sleep for the appropriate amount of time
    switch(currentState) {
        case RED:
            usleep(STATE_TIME * 1000 * 1000);
            break;
        case YELLOW:
            usleep(YELLOWSTATE_TIME * 1000 * 1000);
            break;
        case GREEN:
            usleep(STATE_TIME * 1000 * 1000);
            break;
        default:
            printf("Invalid traffic light state.\n");
            exit(EXIT_FAILURE);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// Function to run the simulation
void* runSimulation(void* arg) {
    // Loop forever
    while(true) {
        // Change the traffic light to green
        changeState(GREEN);

        // Change the traffic light to yellow
        changeState(YELLOW);

        // Change the traffic light to red
        changeState(RED);
    }

    return NULL;
}

int main() {
    // Initialize the mutex
    if(pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return EXIT_FAILURE;
    }

    // Initialize the current state to red
    currentState = RED;

    // Create a thread to run the simulation
    pthread_t simulationThread;
    if(pthread_create(&simulationThread, NULL, &runSimulation, NULL) != 0) {
        printf("Thread creation failed.\n");
        return EXIT_FAILURE;
    }

    // Loop forever, printing out the current state of the traffic light
    while(true) {
        switch(currentState) {
            case RED:
                printf("Traffic Light State: RED\n");
                break;
            case YELLOW:
                printf("Traffic Light State: YELLOW\n");
                break;
            case GREEN:
                printf("Traffic Light State: GREEN\n");
                break;
            default:
                printf("Invalid traffic light state.\n");
                return EXIT_FAILURE;
        }

        // Sleep for 1 second
        usleep(1000 * 1000);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}