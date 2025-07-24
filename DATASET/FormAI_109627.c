//FormAI DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_LIGHTS 4 // number of lights in the smart home system
#define TURN_ON 1
#define TURN_OFF 0

// function to simulate random light turning on and off
void *simulator(void *arg) {
    int *light = (int*) arg;
    srand(time(NULL)); // seed random number generator
    while (true) {
        sleep(rand() % 10 + 1); // sleep for random amount of seconds (between 1-10)
        *light = *light == TURN_ON ? TURN_OFF : TURN_ON; // turn light on/off by toggling value
    }
}

int main() {
    int lights[NUM_LIGHTS] = {TURN_OFF}; // array to store the state of each light (initialized as off)
    pthread_t threads[NUM_LIGHTS]; // array to store thread IDs

    for (int i = 0; i < NUM_LIGHTS; i++) {
        // create a thread for each light and pass a pointer to its corresponding element in the lights array
        if (pthread_create(&threads[i], NULL, simulator, &lights[i]) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    // main thread loops indefinitely and prints the state of each light
    while (true) {
        printf("Current state of lights: ");
        for (int i = 0; i < NUM_LIGHTS; i++) {
            printf("%d ", lights[i]);
        }
        printf("\n");
        sleep(1); // sleep for 1 second before printing again
    }

    // wait for all threads to finish (this code will never be reached in this program)
    for (int i = 0; i < NUM_LIGHTS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0; // end program
}