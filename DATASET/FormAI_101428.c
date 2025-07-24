//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct thread_info {
    char* ip_address;
    int port;
};

void *scan(void *arg) {
    struct thread_info *info = (struct thread_info *)arg;

    // Connect to wireless network
    printf("Scanning wireless network at %s:%d...\n", info->ip_address, info->port);
    sleep(2);

    // Scan for available devices
    printf("Devices found on network: \n");
    sleep(2);
    printf("Device 1: iPhone\n");
    sleep(1);
    printf("Device 2: Samsung Galaxy\n");
    sleep(1);
    printf("Device 3: Google Pixel\n\n");

    // Close connection
    printf("Finished scanning wireless network at %s:%d.\n", info->ip_address, info->port);
    sleep(1);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    struct thread_info thread_args[3];

    // Create thread for each IP address
    thread_args[0].ip_address = "192.168.1.1";
    thread_args[0].port = 80;

    thread_args[1].ip_address = "192.168.1.2";
    thread_args[1].port = 80;

    thread_args[2].ip_address = "192.168.1.3";
    thread_args[2].port = 80;

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, scan, (void *)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nAll scans complete.\n");

    return 0;
}