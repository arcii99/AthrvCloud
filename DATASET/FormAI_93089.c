//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DEVICES 100

int device_count = 0;

pthread_mutex_t device_mutex = PTHREAD_MUTEX_INITIALIZER;

void* scan_wireless_network(void* arg) {
    int* device_id = (int*) arg;
    // Simulating scanning process
    // Sleep for a random interval to represent scanning time
    int sleep_interval = rand() % 5 + 1;
    printf("Scanning device %d...\n", *device_id);
    sleep(sleep_interval);
    printf("Finished scanning device %d.\n", *device_id);
    
    pthread_mutex_lock(&device_mutex);
    // Increment the device count
    device_count++;
    pthread_mutex_unlock(&device_mutex);
    
    return NULL;
}

int main() {
    pthread_t threads[MAX_DEVICES];
    int device_ids[MAX_DEVICES];
    
    // Simulating scanning multiple devices simultaneously
    int num_devices = rand() % MAX_DEVICES + 1;
    for (int i = 0; i < num_devices; i++) {
        device_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, scan_wireless_network, &device_ids[i]);
    }
    
    // Wait for all threads to finish scanning
    for (int i = 0; i < num_devices; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Scanned %d devices.\n", num_devices);
    printf("Found %d active devices on the network.\n", device_count);
    
    return 0;
}