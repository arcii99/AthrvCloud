//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_DELAY 10 // in milliseconds

int main() {
    srand(time(NULL)); // seed random number generator with current time
    
    // initialize QoS variables
    int packets_lost = 0;
    float avg_delay = 0.0;
    int total_packets = 0;
    
    // start monitoring network QoS
    while(1) {
        int packet_size = rand() % MAX_PACKET_SIZE + 1; // generate random packet size
        int delay = rand() % MAX_DELAY + 1; // generate random delay
        
        // simulate packet loss
        if(rand() % 100 < 10) { // 10% chance of packet loss
            packets_lost++;
            printf("Lost packet of size %d\n", packet_size);
            continue;
        }
        
        // simulate delay
        total_packets++;
        avg_delay = (avg_delay * (total_packets - 1) + delay) / total_packets;
        printf("Received packet of size %d with delay %dms\n", packet_size, delay);
        
        // print QoS statistics
        printf("\n----- Network QoS statistics -----\n");
        printf("Packets lost: %d\n", packets_lost);
        printf("Average delay: %.2fms\n", avg_delay);
        printf("Total packets: %d\n", total_packets);
        printf("----------------------------------\n\n");
        
        // wait for next packet
        usleep(delay * 1000); // convert delay from milliseconds to microseconds
    }
    
    return 0;
}