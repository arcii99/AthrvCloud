//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
/* Romeo and Juliet QoS Monitor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

/* Define the maximum number of requests to handle */
#define MAX_REQUESTS 50

/* Define the maximum packet size */
#define MAX_PACKET_SIZE 1024

/* Define the maximum bandwidth speed */
#define MAX_BANDWIDTH_SPEED 10000 // in KB/s

int main()
{
    srand(time(NULL));
    int requests_handled = 0;
    long total_bandwidth_used = 0;
    bool is_network_congested = false;
    char* message = "A rose by any other name would smell as sweet.";

    while (requests_handled < MAX_REQUESTS) {
        /* Randomly generate the size of the packet */
        int packet_size = rand() % MAX_PACKET_SIZE;

        /* Calculate the bandwidth utilized */
        long bandwidth_used = packet_size / 1024; // convert bytes to KB
        total_bandwidth_used += bandwidth_used;

        /* Check if the network is congested */
        if (total_bandwidth_used >= MAX_BANDWIDTH_SPEED) {
            printf("Oh, there is much noise and congestion in the network!\n");
            is_network_congested = true;
        }

        /* Print the message along with the packet details */
        printf("Romeo sent a packet of size %d KB to Juliet: %s\n", packet_size / 1024, message);

        /* Delay for a random amount of time between 1 to 10 seconds */
        int delay = rand() % 10 + 1;
        sleep(delay);

        /* Increment the requests handled */
        requests_handled++;
    }

    if (is_network_congested) {
        printf("Alas, the network is congested! Let us reattempt another time.\n");
        /* Return error code to indicate network congestion */
        return 1;
    } else {
        printf("Oh happy dagger, this is thy sheath; there rust, and let me die.\n");
        /* Indicate successful end of program */
        return 0;
    }
}