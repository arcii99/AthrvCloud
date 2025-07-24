//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 4

double generateData() {
    return ((double)rand() / (double)RAND_MAX);
}

double computeThroughput(double dataRate, double packetSize) {
    return (dataRate / (packetSize * 8));
}

double computeDelay(double serviceTime, double packetSize, double queueSize, double dataRate) {
    return ((queueSize * packetSize) / dataRate) + serviceTime;
}

double computePacketLoss(double queueSize, double bufferCapacity) {
    return ((queueSize / bufferCapacity) * 100);
}

void* threadFunction(void* args) {
    int id = *(int*)args;

    double dataRate = 100 + generateData() * 400; // generate random data rate between 100 and 500 Mbps
    double packetSize = 64 + generateData() * 448; // generate random packet size between 64 and 512 bytes
    double queueSize = 1 + generateData() * 9; // generate random queue size between 1 and 10 packets
    double bufferCapacity = 10 + generateData() * 40; // generate random buffer capacity between 10 and 50 packets
    double serviceTime = 0.001 + generateData() * 0.005; // generate random service time between 1 and 5 ms

    // compute network metrics
    double throughput = computeThroughput(dataRate, packetSize);
    double delay = computeDelay(serviceTime, packetSize, queueSize, dataRate);
    double packetLoss = computePacketLoss(queueSize, bufferCapacity);

    // print network metrics
    printf("Thread %d:\n", id);
    printf("\tData rate: %.2f Mbps\n", dataRate);
    printf("\tPacket size: %.2f bytes\n", packetSize);
    printf("\tQueue size: %.2f packets\n", queueSize);
    printf("\tBuffer capacity: %.2f packets\n", bufferCapacity);
    printf("\tService time: %.2f ms\n", serviceTime);
    printf("\tThroughput: %.2f packets/s\n", throughput);
    printf("\tDelay: %.2f ms\n", delay);
    printf("\tPacket loss: %.2f%%\n", packetLoss);

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t threads[MAX_THREADS];
    int threadIds[MAX_THREADS];

    // create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, threadFunction, &threadIds[i]);
    }

    // join threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}