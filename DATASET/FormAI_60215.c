//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_PACKET_SIZE 1024
#define MIN_PACKET_SIZE 64
#define MAX_PACKET_RATE 1000 // Packets per second
#define MIN_PACKET_RATE 10

// Function to generate random packet size
int generate_random_packet_size() {
    int range = MAX_PACKET_SIZE - MIN_PACKET_SIZE + 1;
    return (rand() % range) + MIN_PACKET_SIZE;
}

// Function to generate random packet rate
int generate_random_packet_rate() {
    int range = MAX_PACKET_RATE - MIN_PACKET_RATE + 1;
    return (rand() % range) + MIN_PACKET_RATE;
}

int main() {
    // Set up the random number generator
    srand(time(NULL));
    
    // Initialize variables
    int average_packet_size = 0;
    int average_packet_rate = 0;
    int packet_count = 0;
    int total_bytes_sent = 0;
    
    // Display initial message
    printf("Starting Network Quality of Service (QoS) monitor...\n");
    
    // Loop to simulate network traffic for 60 seconds
    for (int i = 0; i < 60; i++) {
        // Generate random packet size and rate
        int packet_size = generate_random_packet_size();
        int packet_rate = generate_random_packet_rate();
        
        // Calculate total bytes sent in one second
        int bytes_sent = packet_size * packet_rate;
        
        // Update variables
        average_packet_size = ((average_packet_size * packet_count) + packet_size) / (packet_count + 1);
        average_packet_rate = ((average_packet_rate * i) + packet_rate) / (i + 1);
        packet_count++;
        total_bytes_sent += bytes_sent;
        
        // Display current network statistics
        printf("Second %d - Packet Size: %d bytes - Packet Rate: %d packets/s\n", i+1, packet_size, packet_rate);
    }
    
    // Calculate average throughput
    float average_throughput = ((float)total_bytes_sent / 60) * 8 / 1000000;
    
    // Display final network statistics
    printf("\nAverage Packet Size: %d bytes\n", average_packet_size);
    printf("Average Packet Rate: %d packets/s\n", average_packet_rate);
    printf("Average Throughput: %.2f Mbps\n", average_throughput);
    
    // End program
    printf("\nExiting Network Quality of Service (QoS) monitor...\n");
    return 0;
}