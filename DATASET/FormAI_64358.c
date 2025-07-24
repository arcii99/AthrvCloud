//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4

void* monitor_RAM(void* arg);
void* update_data(void* arg);

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];
    int rc;

    printf("Starting RAM usage monitor...\n");

    // Create thread to monitor RAM usage
    rc = pthread_create(&threads[1], NULL, monitor_RAM, NULL);

    if (rc) {
        printf("Error creating RAM usage monitor thread... Exiting.\n");
        exit(-1);
    }

    // Create thread to update data
    rc = pthread_create(&threads[2], NULL, update_data, NULL);

    if (rc) {
        printf("Error creating data update thread... Exiting.\n");
        exit(-1);
    }

    // Wait for threads to finish execution
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("RAM usage monitor successfully terminated.\n");
    return 0;
}

void* monitor_RAM(void* arg) {
    int ram_usage = 0;
    int counter = 0;

    while (1) {
        sleep(5);
        ram_usage = rand() % 100;
        printf("RAM usage: %d%%\n", ram_usage);
        counter++;

        // Terminate thread after 10 iterations
        if (counter >= 10) {
            printf("RAM usage monitor thread terminated.\n");
            pthread_exit(NULL);
        }
    }
}

void* update_data(void* arg) {
    while (1) {
        sleep(2);
        printf("Updating data...\n");
    }
}