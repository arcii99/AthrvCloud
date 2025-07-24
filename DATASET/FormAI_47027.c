//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Initialize variables
    int ping = 0;
    int jitter = 0;
    int packetLoss = 0;
    int bandwidth = 0;
    int QoS = 0;
    
    // Get current time
    time_t t;
    srand((unsigned) time(&t));
    
    // Generate random network stats
    ping = rand() % 100 + 1;
    jitter = rand() % 20 + 1;
    packetLoss = rand() % 10 + 1;
    bandwidth = rand() % 1000 + 1;
    
    // Calculate QoS score
    QoS = (100 - jitter) + (100 - packetLoss) + (1000 - bandwidth) + ping;
    
    // Determine QoS rating
    if (QoS >= 900) {
        printf("Excellent network quality!\n");
    } else if (QoS >= 700 && QoS < 900) {
        printf("Good network quality.\n");
    } else if (QoS >= 500 && QoS < 700) {
        printf("Fair network quality.\n");
    } else if (QoS >= 300 && QoS < 500) {
        printf("Poor network quality.\n");
    } else {
        printf("Bad network quality!\n");
    }
    
    // Print out network stats
    printf("Ping: %d ms\n", ping);
    printf("Jitter: %d ms\n", jitter);
    printf("Packet Loss: %d%%\n", packetLoss);
    printf("Bandwidth: %d Mbps\n", bandwidth);
    printf("QoS Score: %d\n", QoS);
    
    return 0;
}