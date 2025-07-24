//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define INTERVAL 5 // in seconds

// Shared variables
int light_state = GREEN;
int program_state = 1;

void change_light_state() {
    while (program_state) {
        switch (light_state) {
            case RED:
                printf("Light is red.\n");
                sleep(INTERVAL);
                light_state = GREEN;
                break;
            case YELLOW:
                printf("Light is yellow.\n");
                sleep(INTERVAL);
                light_state = RED;
                break;
            case GREEN:
                printf("Light is green.\n");
                sleep(INTERVAL);
                light_state = YELLOW;
                break;
            default:
                printf("Unknown light state.\n");
                break;
        }
    }
}

void manual_override() {
    printf("Manual override: Enter new light state (0 = red, 1 = yellow, 2 = green):\n");
    scanf("%d", &light_state);
}

int main() {
    printf("Traffic Light Controller\n");
    printf("========================\n");
    printf("\n");

    // Create threads
    pthread_t light_thread, override_thread;

    // Start light management thread
    if (pthread_create(&light_thread, NULL, (void*) change_light_state, NULL)) {
        printf("Error starting light management thread");
        exit(1);
    }

    // Start manual override thread
    if (pthread_create(&override_thread, NULL, (void*) manual_override, NULL)) {
        printf("Error starting manual override thread");
        exit(1);
    }

    // Wait for threads to finish
    pthread_join(light_thread, NULL);
    pthread_join(override_thread, NULL);

    // Close program
    program_state = 0;
    printf("Exiting program...\n");

    return 0;
}