//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Global variables
int network_bandwidth = 100; // Mbps
int delay = 50; // ms
int packet_loss_rate = 0; // percentage

// Thread function to continuously monitor the network QoS
void *monitor_network_qos(void *thread_id) {
    int id = *((int *) thread_id);
    printf("Thread %d started\n", id);

    while (1) {
        // Simulate a delay in fetching network statistics
        usleep(delay * 1000);

        // Check if network bandwidth is lower than expected
        if (network_bandwidth < 80) {
            printf("Low network bandwidth detected! Bandwidth = %d Mbps\n", network_bandwidth);
        }

        // Check if packet loss rate is higher than expected
        if (packet_loss_rate > 10) {
            printf("High packet loss rate detected! Packet loss rate = %d%%\n", packet_loss_rate);
        }
    }
}

// Thread function to generate network traffic
void *generate_network_traffic(void *thread_id) {
    int id = *((int *) thread_id);
    printf("Thread %d started\n", id);

    while (1) {
        // Simulate network traffic by sending packets
        usleep(rand() % 10000 + 1000);

        // Simulate packet loss by randomly dropping packets
        if (rand() % 100 < packet_loss_rate) {
            printf("Packet dropped!\n");
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the threads
    pthread_t thread1, thread2;

    // Create the network QoS monitoring thread
    int thread1_id = 1;
    pthread_create(&thread1, NULL, monitor_network_qos, &thread1_id);

    // Create the network traffic generation thread
    int thread2_id = 2;
    pthread_create(&thread2, NULL, generate_network_traffic, &thread2_id);

    // Simulate changes in network QoS
    while (1) {
        // Simulate a delay in updating network statistics
        usleep(delay * 1000);

        // Simulate changes in network bandwidth
        network_bandwidth = rand() % 100 + 1;

        // Simulate changes in packet loss rate
        packet_loss_rate = rand() % 20;

        printf("Network bandwidth = %d Mbps   Packet loss rate = %d%%\n", network_bandwidth, packet_loss_rate);
    }

    // Join the threads to wait for them to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}