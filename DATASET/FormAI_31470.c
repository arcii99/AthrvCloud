//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Constant to define the maximum number of probes that can be launched
#define MAX_PROBES 10000

// Global variables for the number of probes and the probability of an alien invasion
int probes_launched = 0;
float invasion_probability = 0.0;

// Function to launch a probe and determine its results randomly
void* launch_probe(void* arg) {
    while (probes_launched < MAX_PROBES) {
        int result = rand() % 2;
        if (result == 1) {
            invasion_probability += 0.01;
        }
        probes_launched++;
    }
    pthread_exit(NULL);
}

int main() {
    // Initializing the random number generator
    srand(time(NULL));

    // Array to store the threads launched to run the probes
    pthread_t probes[MAX_PROBES];

    // Launching the probes with multi-threading
    for (int i = 0; i < MAX_PROBES; i++) {
        pthread_create(&probes[i], NULL, launch_probe, NULL);
    }

    // Joining the threads once all probes have been launched
    for (int i = 0; i < MAX_PROBES; i++) {
        pthread_join(probes[i], NULL);
    }

    // Printing the final invasion probability
    printf("Probability of an alien invasion: %f", invasion_probability);

    return 0;
}