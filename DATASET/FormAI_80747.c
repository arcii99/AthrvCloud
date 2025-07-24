//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    int delay = rand() % 100; // simulate packet delay in milliseconds
    int jitter = rand() % 50; // simulate packet jitter in milliseconds

    float throughput = rand() % 1000; // simulate network throughput in bytes/sec
    float drop_rate = rand() % 10; // simulate packet drop rate as a percentage

    printf("Welcome to the Network Quality of Service (QoS) monitor!\n\n");
    printf("Packet Delay: %dms\n", delay);
    printf("Packet Jitter: %dms\n", jitter);
    printf("Throughput: %0.2f bytes/sec\n", throughput);
    printf("Packet Drop Rate: %0.2f percent\n", drop_rate);
    
    // determine network quality based on QoS metrics
    if (delay < 50 && jitter < 25 && throughput > 500 && drop_rate < 5) {
        printf("\nThe network is operating at an excellent level of quality!\n");
    } else if (delay < 75 && jitter < 40 && throughput > 250 && drop_rate < 7.5) {
        printf("\nThe network is operating at a good level of quality, but there is room for improvement.\n");
    } else {
        printf("\nThe network is experiencing significant issues that require attention.\n");
    }

    return 0;
}