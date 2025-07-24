//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float upstream_bandwidth, downstream_bandwidth, latency, max_latency;
    int jitter, packet_loss;
    
    // User prompt
    printf("\n----- Network Quality of Service (QoS) Monitor -----");
    printf("\nEnter the upstream bandwidth (in Mbps): ");
    scanf("%f", &upstream_bandwidth);
    printf("Enter the downstream bandwidth (in Mbps): ");
    scanf("%f", &downstream_bandwidth);
    printf("Enter the network latency (in ms): ");
    scanf("%f", &latency);
    printf("Enter the maximum allowed latency (in ms): ");
    scanf("%f", &max_latency);
    printf("Enter the network jitter (in ms): ");
    scanf("%d", &jitter);
    printf("Enter the packet loss percentage (0-100): ");
    scanf("%d", &packet_loss);
    
    // Check QoS levels
    int QoS = 5;
    if (upstream_bandwidth < 1.0)
        QoS--;
    if (downstream_bandwidth < 5.0)
        QoS--;
    if (latency > max_latency)
        QoS--;
    if (jitter > 10)
        QoS--;
    if (packet_loss > 5)
        QoS--;
    
    // Display QoS rating
    printf("\n----- Results -----");
    printf("\nQoS rating: %d out of 5\n", QoS);
    
    return 0;
}