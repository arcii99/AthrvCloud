//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// define the different states of the traffic light
typedef enum {RED, YELLOW, GREEN} state_t;

// initialize the state of the traffic light
state_t state = RED;

// define the amount of time for each state in seconds
int redTime = 10; 
int yellowTime = 3;
int greenTime = 10;

// function to simulate the red light
void* redLight(void* arg) {
    while(1) {
        state = RED;
        printf("RED\n");
        sleep(redTime);
    }
}

// function to simulate the yellow light
void* yellowLight(void* arg) {
    while(1) {
        state = YELLOW;
        printf("YELLOW\n");
        sleep(yellowTime);
    }
}

// function to simulate the green light
void* greenLight(void* arg) {
    while(1) {
        state = GREEN;
        printf("GREEN\n");
        sleep(greenTime);
    }
}

int main() {
    // initialize the threads for each light
    pthread_t redThread;
    pthread_t yellowThread;
    pthread_t greenThread;

    // create the threads
    int ret1 = pthread_create(&redThread, NULL, redLight, NULL);
    int ret2 = pthread_create(&yellowThread, NULL, yellowLight, NULL);
    int ret3 = pthread_create(&greenThread, NULL, greenLight, NULL);

    // check for errors in creating threads
    if (ret1 || ret2 || ret3) {
        printf("Error creating threads\n");
        return 1;
    }

    // wait for threads to finish
    pthread_join(redThread, NULL);
    pthread_join(yellowThread, NULL);
    pthread_join(greenThread, NULL);

    return 0;
}