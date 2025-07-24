//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/* Define constants for QoS thresholds */
#define MIN_LATENCY 10
#define MAX_LATENCY 50
#define MIN_THROUGHPUT 100
#define MAX_THROUGHPUT 500
#define MIN_JITTER 5
#define MAX_JITTER 50

/* Define a struct for storing QoS data */
typedef struct {
    unsigned int latency;
    unsigned int throughput;
    unsigned int jitter;
} QoSData;

/* Function to generate a random integer within a given range */
int randInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to generate random QoS data */
QoSData generateRandomQoSData() {
    QoSData data;
    data.latency = randInRange(MIN_LATENCY, MAX_LATENCY);
    data.throughput = randInRange(MIN_THROUGHPUT, MAX_THROUGHPUT);
    data.jitter = randInRange(MIN_JITTER, MAX_JITTER);
    return data;
}

/* Main function */
int main() {

    /* Seed random number generator */
    srand(time(NULL));

    /* Loop to generate QoS data and check thresholds */
    while (1) {
        /* Generate random QoS data */
        QoSData data = generateRandomQoSData();

        /* Check latency threshold */
        if (data.latency > MAX_LATENCY) {
            printf("ALERT: Latency threshold exceeded! (current value: %d)\n", data.latency);
        }

        /* Check throughput threshold */
        if (data.throughput < MIN_THROUGHPUT) {
            printf("ALERT: Throughput threshold exceeded! (current value: %d)\n", data.throughput);
        }

        /* Check jitter threshold */
        if (data.jitter > MAX_JITTER) {
            printf("ALERT: Jitter threshold exceeded! (current value: %d)\n", data.jitter);
        }

        /* Sleep for 1 second before generating next QoS data */
        sleep(1);
    }

    return 0;
}