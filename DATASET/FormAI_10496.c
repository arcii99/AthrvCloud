//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int packets_sent;
    int packets_dropped;
    float packet_loss;
} QoS;

int main(void) {
    int connection_speeds[3] = {10, 100, 1000};
    QoS net_quality[3];

    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        net_quality[i].packets_sent = rand() % 5000 + 1000; // random number of packets sent
        net_quality[i].packets_dropped = rand() % net_quality[i].packets_sent; // random number of packets dropped
        net_quality[i].packet_loss = (float)net_quality[i].packets_dropped / net_quality[i].packets_sent * 100;
        printf("QoS for connection speed %dMbps: %.2f%% packet loss\n", connection_speeds[i], net_quality[i].packet_loss);
    }
    
    return 0;
}