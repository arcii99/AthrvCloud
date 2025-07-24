//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
/* Unique C Network Quality of Service (QoS) monitor example program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 1024

/* Function to calculate the average packet delay */
double calc_avg_packet_delay(double *delays, int num_packets) {
    double sum_delay = 0.0;
    for(int i=0; i<num_packets; i++) {
        sum_delay += delays[i];
    }
    return sum_delay / num_packets;
}

/* Function to calculate the standard deviation of packet delay */
double calc_packet_delay_sd(double *delays, int num_packets) {
    double sum_delay_sq = 0.0;
    double mean_delay = calc_avg_packet_delay(delays, num_packets);

    for(int i=0; i<num_packets; i++) {
        sum_delay_sq += pow((delays[i] - mean_delay), 2);
    }
    return sqrt(sum_delay_sq / num_packets);
}

/* Function to simulate network traffic and measure QoS parameters */
int simulate_network_traffic() {
    srand(time(NULL));
    double packet_delays[BUFFER_SIZE];
    int num_packets = rand() % BUFFER_SIZE;

    /* Simulating packet delay using random numbers */
    for(int i=0; i<num_packets; i++) {
        packet_delays[i] = rand() % 100 + 1;    // delay between 1 to 100 milliseconds
    }

    printf("QoS Parameters: \n");
    printf("Number of packets: %d\n", num_packets);
    printf("Average packet delay: %.2lf ms\n", calc_avg_packet_delay(packet_delays, num_packets));
    printf("Standard deviation of packet delay: %.2lf ms\n", calc_packet_delay_sd(packet_delays, num_packets));

    return 0;
}

/* Main function */
int main() {
    simulate_network_traffic();
    return 0;
}