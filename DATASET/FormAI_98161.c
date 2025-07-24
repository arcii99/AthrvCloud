//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

// Define constants for QoS monitoring
#define MIN_PACKET_SIZE 64
#define MAX_PACKET_SIZE 1500
#define MAX_QUEUE_LENGTH 1000
#define MIN_QUEUE_LENGTH 1
#define MAX_RATE 1000000000 // 1 Gbps
#define MIN_RATE 1000000 // 1 Mbps
#define QUEUE_THRESHOLD 90 // percentage

// Function to check if a given queue length is within bounds
bool is_queue_length_valid(int queue_length) {
    if (queue_length < MIN_QUEUE_LENGTH || queue_length > MAX_QUEUE_LENGTH) {
        return false;
    }
    return true;
}

// Function to check if a given packet size is within bounds
bool is_packet_size_valid(int packet_size) {
    if (packet_size < MIN_PACKET_SIZE || packet_size > MAX_PACKET_SIZE) {
        return false;
    }
    return true;
}

// Function to check if a given rate is within bounds
bool is_rate_valid(int rate) {
    if (rate < MIN_RATE || rate > MAX_RATE) {
        return false;
    }
    return true;
}

// Function to monitor QoS
void monitor_qos(int packet_size, int queue_length, int rate) {
    int current_queue_length = 0;
    int packets_received = 0;
    int packets_dropped = 0;
    int current_rate = 0;

    // Loop to send packets and monitor queue length, packets received and dropped
    while (true) {
        // Check if queue length is within threshold
        if (current_queue_length >= (QUEUE_THRESHOLD * queue_length / 100)) {
            printf("Alert! Queue length above threshold!\n");
        }

        // Check if rate is within bounds
        if (current_rate > rate) {
            printf("Alert! Rate above limit!\n");
        }

        // Simulate receiving a packet
        usleep((1000000 / rate) * packet_size);
        current_rate += packet_size;

        // Check if queue is full
        if (current_queue_length < queue_length) {
            current_queue_length += packet_size;
            packets_received++;
        } else {
            packets_dropped++;
        }

        // Print statistics
        printf("Packets received: %d\n", packets_received);
        printf("Packets dropped: %d\n", packets_dropped);
        printf("Current queue length: %d\n", current_queue_length);
        printf("Current rate: %d\n", current_rate);

        usleep(1000000); // Wait for a second before sending next packet
    }
}

int main() {
    int packet_size, queue_length, rate;

    // Get user input for packet size
    printf("Enter packet size (between %d and %d bytes): ", MIN_PACKET_SIZE, MAX_PACKET_SIZE);
    scanf("%d", &packet_size);

    // Validate packet size input
    while (!is_packet_size_valid(packet_size)) {
        printf("Invalid packet size. Enter packet size (between %d and %d bytes): ", MIN_PACKET_SIZE, MAX_PACKET_SIZE);
        scanf("%d", &packet_size);
    }

    // Get user input for queue length
    printf("Enter queue length (between %d and %d packets): ", MIN_QUEUE_LENGTH, MAX_QUEUE_LENGTH);
    scanf("%d", &queue_length);

    // Validate queue length input
    while (!is_queue_length_valid(queue_length)) {
        printf("Invalid queue length. Enter queue length (between %d and %d packets): ", MIN_QUEUE_LENGTH, MAX_QUEUE_LENGTH);
        scanf("%d", &queue_length);
    }

    // Get user input for rate
    printf("Enter rate (between %d and %d bps): ", MIN_RATE, MAX_RATE);
    scanf("%d", &rate);

    // Validate rate input
    while (!is_rate_valid(rate)) {
        printf("Invalid rate. Enter rate (between %d and %d bps): ", MIN_RATE, MAX_RATE);
        scanf("%d", &rate);
    }

    // Start monitoring QoS
    monitor_qos(packet_size, queue_length, rate);

    return 0;
}