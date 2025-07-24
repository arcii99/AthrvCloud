//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PACKET_SIZE 300 // Maximum packet size in bytes
#define MAX_PACKETS 2000 // Maximum number of packets in a single experiment
#define R 10 // Data rate in Mbps
#define L 100 // Link length in km
#define C 10 // Propagation speed in km/s
#define ALPHA 0.125 // Fairness parameter for RED
#define BETA 0.25 // Fairness parameter for RED
#define MIN_THRESHOLD 4000 // Minimum threshold for RED
#define MAX_THRESHOLD 8000 // Maximum threshold for RED

// Function to generate random numbers between 0 and 1
double rand_0_to_1() {
    return (double)rand() / (double)RAND_MAX;
}

int main() {
    // Initialize variables
    int num_packets = 0;
    int num_dropped_packets = 0;
    double avg_queue_size = 0;
    double avg_delay = 0;
    double avg_throughput = 0;
    double prev_avg_queue_size = 0;
    double prev_threshold = MAX_THRESHOLD;
    int i, j;
    double packet_size[MAX_PACKETS];
    double packet_arrival_time[MAX_PACKETS];
    double packet_departure_time[MAX_PACKETS];
    double queue_size = 0;
    double threshold = prev_threshold;
    
    // Generate packets with random sizes and arrival times
    for (i = 0; i < MAX_PACKETS; i++) {
        packet_size[i] = rand_0_to_1() * MAX_PACKET_SIZE;
        packet_arrival_time[i] = rand_0_to_1() * 0.2;
    }
    
    // Simulate packet transmission and queueing
    for (i = 0; i < MAX_PACKETS; i++) {
        // Compute time required to transmit the packet
        double transmission_time = packet_size[i] / (R * 1000000);
        
        // Compute propagation delay
        double propagation_delay = (L * 1000) / (C * 1000000);
        
        // Compute total packet delay
        double packet_delay = transmission_time + propagation_delay;
        
        // Compute time of packet departure
        if (i == 0) {
            packet_departure_time[i] = packet_arrival_time[i] + packet_delay;
        } else {
            double prev_departure_time = packet_departure_time[i-1];
            if (packet_arrival_time[i] < prev_departure_time) {
                packet_departure_time[i] = prev_departure_time + packet_delay;
            } else {
                packet_departure_time[i] = packet_arrival_time[i] + packet_delay;
            }
        }
        
        // Update queue size
        double prev_queue_size = queue_size;
        queue_size = fmax(0, queue_size - (packet_departure_time[i] - packet_arrival_time[i]) * R * 1000000);
        double new_queue_size = queue_size + packet_size[i];
        
        // Apply RED if queue size is too large
        if (new_queue_size > threshold) {
            double p_drop = ALPHA * (new_queue_size - threshold) / (prev_queue_size + packet_size[i] - threshold) + BETA;
            if (rand_0_to_1() < p_drop) {
                num_dropped_packets++;
                queue_size = prev_queue_size;
            }
        }
        
        // Update average queue size and delay
        avg_queue_size += queue_size;
        avg_delay += packet_departure_time[i] - packet_arrival_time[i];
        
        // Update threshold using packet drop history
        if (num_packets > 0) {
            double packet_drop_ratio = (double)num_dropped_packets / (double)num_packets;
            if (packet_drop_ratio > 0.002) {
                threshold = fmin(MAX_THRESHOLD, prev_threshold * 1.1);
            } else {
                threshold = fmax(MIN_THRESHOLD, prev_threshold * 0.9);
            }
            prev_threshold = threshold;
        }
        
        num_packets++;
    }
    
    // Compute average queue size, delay, and throughput
    avg_queue_size /= num_packets;
    avg_delay /= num_packets;
    avg_throughput = (num_packets - num_dropped_packets) * MAX_PACKET_SIZE / (packet_departure_time[MAX_PACKETS-1] - packet_arrival_time[0]);
    
    // Print results
    printf("Average queue size: %f\n", avg_queue_size);
    printf("Average delay: %f\n", avg_delay);
    printf("Average throughput: %f\n", avg_throughput);
    
    return 0;
}