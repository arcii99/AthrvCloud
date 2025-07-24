//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // initialize variables
    int num_packets = rand() % 100 + 1;
    int total_bandwidth = rand() % 1000 + 1;
    int total_delay = rand() % 500 + 1;
    int lost_packets = rand() % num_packets;
    int successful_packets = num_packets - lost_packets;

    // calculate packet loss percentage
    double loss_percentage = (double) lost_packets / num_packets * 100;

    // print medieval-style report
    printf("***************** Network Quality of Service Report *****************\n");
    printf("Total packets sent: %d\n", num_packets);
    printf("Packets successfully delivered: %d\n", successful_packets);
    printf("Packets lost in transit: %d\n", lost_packets);
    printf("Packet loss percentage: %.2f%%\n", loss_percentage);
    printf("Total bandwidth available: %d MB/s\n", total_bandwidth);
    printf("Total delay experienced: %d ms\n", total_delay);
    printf("**********************************************************************\n");

    return 0;
}