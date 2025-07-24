//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HOSTS 10
#define MAX_PACKETS 100

int main()
{
    int i, j;
    char host[MAX_HOSTS][20];
    int latency[MAX_HOSTS][MAX_PACKETS];
    int packets_sent[MAX_HOSTS] = {0};
    float packet_loss[MAX_HOSTS] = {0};
    float packet_delay[MAX_HOSTS] = {0};
    float packet_jitter[MAX_HOSTS] = {0};

    // Initialize hosts
    strcpy(host[0], "www.google.com");
    strcpy(host[1], "www.facebook.com");
    strcpy(host[2], "www.yahoo.com");

    srand(time(NULL));

    // Simulate sending packets to hosts
    for(i=0; i<10000; i++)
    {
        for(j=0; j<MAX_HOSTS; j++)
        {
            if(rand()%2 == 0) // Randomly drop packet
            {
                packet_loss[j]++;
            }
            else // Calculate packet statistics
            {
                latency[j][packets_sent[j]] = rand()%20 + 1;
                packet_delay[j] += latency[j][packets_sent[j]];
                if(packets_sent[j] != 0)
                {
                    packet_jitter[j] += abs(latency[j][packets_sent[j]] - latency[j][packets_sent[j]-1]);
                }
                packets_sent[j]++;
            }
        }
    }

    // Calculate and print statistics for each host
    for(i=0; i<MAX_HOSTS; i++)
    {
        printf("Host: %s\n", host[i]);
        printf("Packets Sent: %d\n", packets_sent[i]);
        packet_loss[i] /= packets_sent[i];
        packet_loss[i] *= 100;
        printf("Packet Loss: %.2f%%\n", packet_loss[i]);
        packet_delay[i] /= packets_sent[i];
        printf("Packet Delay: %.2fms\n", packet_delay[i]);
        packet_jitter[i] /= packets_sent[i]-1;
        printf("Packet Jitter: %.2fms\n\n", packet_jitter[i]);
    }

    return 0;
}