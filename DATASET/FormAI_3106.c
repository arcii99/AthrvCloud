//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
// Decentralized Traffic Light Controller Example Program

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define constants
#define GREEN_LIGHT 0
#define YELLOW_LIGHT 1
#define RED_LIGHT 2
#define NUM_LIGHTS 3
#define NUM_SECONDS_GREEN 10
#define NUM_SECONDS_YELLOW 3
#define NUM_SECONDS_RED 15

// Define global variables
int currentLight = GREEN_LIGHT;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Define traffic light thread function
void *trafficLightFunction(void *args) {
    int light = *(int *)args; // Cast args to int
    int numSeconds; // Define variable to hold number of seconds for timing
    
    // Loop indefinitely
    while (1) {
        // Determine number of seconds for current light
        switch (light) {
            case GREEN_LIGHT:
                numSeconds = NUM_SECONDS_GREEN;
                break;
            case YELLOW_LIGHT:
                numSeconds = NUM_SECONDS_YELLOW;
                break;
            case RED_LIGHT:
                numSeconds = NUM_SECONDS_RED;
                break;
        }
        
        // Wait for mutex lock
        pthread_mutex_lock(&mutex);
        
        // Wait for current light to be signaled
        while (currentLight != light) {
            pthread_cond_wait(&cond, &mutex);
        }
        
        // Print message and sleep for number of seconds
        printf("Light %d ON for %d seconds\n", light, numSeconds);
        sleep(numSeconds);
        
        // Change light to next value and signal condition variable
        if (light == RED_LIGHT) {
            currentLight = GREEN_LIGHT;
        } else {
            currentLight++;
        }
        pthread_cond_broadcast(&cond);
        
        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }
    
    return NULL;
}

int main() {
    // Define traffic light threads
    pthread_t greenLightThread, yellowLightThread, redLightThread;
    
    // Create traffic light threads
    int threadArgs[NUM_LIGHTS] = {GREEN_LIGHT, YELLOW_LIGHT, RED_LIGHT};
    pthread_create(&greenLightThread, NULL, trafficLightFunction, &threadArgs[0]);
    pthread_create(&yellowLightThread, NULL, trafficLightFunction, &threadArgs[1]);
    pthread_create(&redLightThread, NULL, trafficLightFunction, &threadArgs[2]);
    
    // Wait for threads to finish (should never happen)
    pthread_join(greenLightThread, NULL);
    pthread_join(yellowLightThread, NULL);
    pthread_join(redLightThread, NULL);
    
    return 0;
}