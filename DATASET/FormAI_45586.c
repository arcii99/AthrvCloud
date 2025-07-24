//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

// Function to simulate network traffic
void *simulate_traffic(void *thread_arg) {
    int *traffic_count_ptr = (int *) thread_arg;
    while (true) {
        usleep(100000); // Sleep for 0.1 seconds
        (*traffic_count_ptr)++;
    }
}

// Function to detect network intrusions
void *detect_intrusion(void *thread_arg) {
    int *traffic_count_ptr = (int *) thread_arg;
    int last_traffic_count = 0; // Keep track of last traffic count
    while (true) {
        usleep(500000); // Sleep for 0.5 seconds
        int current_traffic_count = *traffic_count_ptr;
        if ((current_traffic_count - last_traffic_count) >= 100) {
            // There has been suspicious increase in traffic
            printf("Intrusion detected! Traffic count: %d\n", current_traffic_count);
        }
        last_traffic_count = current_traffic_count;
    }
}

int main() {
    int traffic_count = 0;
    pthread_t traffic_thread, intrusion_thread;
    pthread_create(&traffic_thread, NULL, simulate_traffic, &traffic_count);
    pthread_create(&intrusion_thread, NULL, detect_intrusion, &traffic_count);
    pthread_join(traffic_thread, NULL);
    pthread_join(intrusion_thread, NULL);
    return 0;
}