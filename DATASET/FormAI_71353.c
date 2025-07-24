//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ephemeral
// Ephemeral Traffic Light Controller Example Program
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

// Function to handle the Green light
void* green(void* arg) {
    int* counter = (int*)arg;

    while (*counter > 0) {
        printf("Green Light\n");
        sleep(10);
        (*counter)--;
    }

    pthread_exit(NULL);
}

// Function to handle the Yellow light
void* yellow(void* arg) {
    int* counter = (int*)arg;

    while (*counter > 0) {
        printf("Yellow Light\n");
        sleep(2);
        (*counter)--;
    }

    pthread_exit(NULL);
}

// Function to handle the Red light
void* red(void* arg) {
    int* counter = (int*)arg;

    while (*counter > 0) {
        printf("Red Light\n");
        sleep(15);
        (*counter)--;
    }

    pthread_exit(NULL);
}

int main() {
    int green_counter = 3;
    int yellow_counter = 2;
    int red_counter = 4;

    pthread_t green_thread, yellow_thread, red_thread;

    // Starting the Green Light Thread
    if (pthread_create(&green_thread, NULL, green, &green_counter)) {
        printf("Error creating Green light thread\n");
        exit(1);
    }

    // Starting the Yellow Light Thread
    if (pthread_create(&yellow_thread, NULL, yellow, &yellow_counter)) {
        printf("Error creating Yellow light thread\n");
        exit(1);
    }

    // Starting the Red Light Thread
    if (pthread_create(&red_thread, NULL, red, &red_counter)) {
        printf("Error creating Red light thread\n");
        exit(1);
    }

    // Waiting for all the threads to complete
    pthread_join(green_thread, NULL);
    pthread_join(yellow_thread, NULL);
    pthread_join(red_thread, NULL);

    printf("End of Traffic Light program\n");

    return 0;
}