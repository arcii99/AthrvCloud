//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int random_value(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main() {
    srand(time(NULL));
    int packet_count = 0;
    int total_delay = 0;
    int max_delay = 0;
    int min_delay = 0;
    int avg_delay = 0;
    printf("Starting QoS monitor...\n");
    while(1) {
        int packet_size = random_value(1, MAX_PACKET_SIZE);
        int delay = random_value(10, 1000);
        printf("Packet #%d with size %d bytes and delay %d ms\n", packet_count+1, packet_size, delay);
        total_delay += delay;
        if(delay > max_delay) {
            max_delay = delay;
        }
        if(packet_count == 0) {
            min_delay = delay;
        }
        else if(delay < min_delay) {
            min_delay = delay;
        }
        avg_delay = total_delay / (packet_count + 1);
        printf("Current QoS statistics:\n");
        printf(" Total packets: %d\n", packet_count+1);
        printf(" Average delay: %d ms\n", avg_delay);
        printf(" Maximum delay: %d ms\n", max_delay);
        printf(" Minimum delay: %d ms\n", min_delay);
        printf("\n");
        usleep(delay * 1000);
        packet_count++;
    }
    return 0;
}