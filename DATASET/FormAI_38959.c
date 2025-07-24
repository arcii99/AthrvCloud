//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 // Number of threads

void* cpu_monitor(void* arg) {
    int cpuUsage = rand() % 100;
    printf("CPU Usage: %d%%\n", cpuUsage);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS]; // Thread array
    int i;
    
    printf("CPU Usage Monitor for Multiplayers:\n");
    
    for(i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, cpu_monitor, NULL); // Create thread
    }
    
    for(i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL); // Wait for thread to exit
    }
    
    printf("All threads have completed\n");
    
    return 0;
}