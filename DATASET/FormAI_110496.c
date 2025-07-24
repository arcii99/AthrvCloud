//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    int qos;
    int delay;
    int jitter;
    int packet_loss;
} Network;

void *monitor_qos(void *arg) {
    Network *network = (Network*) arg;
    int previous_qos = network->qos;

    while (1) {
        // Check for changes in QoS
        if (network->qos != previous_qos) {
            printf("My love, the network QoS has changed:\n");
            printf("  - QoS: %d\n", network->qos);
            printf("  - Delay: %d ms\n", network->delay);
            printf("  - Jitter: %d ms\n", network->jitter);
            printf("  - Packet loss: %d%%\n", network->packet_loss);
            previous_qos = network->qos;
        }

        // Take a break
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;

    pthread_t threads[MAX_THREADS];
    Network network = {80, 50, 20, 2};

    printf("My dearest love, I have written a program to monitor our network QoS:\n");
    printf("  - QoS: %d\n", network.qos);
    printf("  - Delay: %d ms\n", network.delay);
    printf("  - Jitter: %d ms\n", network.jitter);
    printf("  - Packet loss: %d%%\n", network.packet_loss);

    // Start monitor thread
    pthread_create(&threads[0], NULL, monitor_qos, &network);

    // Wait for all threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("My sweet beloved, the program has ended.\n");

    return 0;
}