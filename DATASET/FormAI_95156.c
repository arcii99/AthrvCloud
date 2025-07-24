//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_INTERVAL 10     // maximum interval between QoS measurements
#define MIN_INTERVAL 5      // minimum interval between QoS measurements

// QoS analytics data structure
typedef struct {
    float avg_latency;
    float avg_bandwidth;
    float packet_loss;
} QoS;

// function to generate random QoS values
QoS generate_random_qos_values() {
    QoS qos;
    qos.avg_latency = (float)rand()/RAND_MAX * 100;
    qos.avg_bandwidth = (float)rand()/RAND_MAX * 1000;
    qos.packet_loss = (float)rand()/RAND_MAX * 10;
    return qos;
}

// function to display QoS analytics
void display_qos(QoS qos) {
    printf("Average Latency: %.2f ms\t", qos.avg_latency);
    printf("Average Bandwidth: %.2f Mbps\t", qos.avg_bandwidth);
    printf("Packet Loss: %.2f %%\n", qos.packet_loss);
}

int main() {
    srand(time(0));     // seed for random number generation
    int interval = 0;
    QoS current_qos;

    printf("Starting QoS Monitor...\n");

    while (1) {
        // generate random QoS values
        current_qos = generate_random_qos_values();

        // display QoS analytics
        display_qos(current_qos);

        // generate random interval between measurements
        interval = (rand() % (MAX_INTERVAL-MIN_INTERVAL+1)) + MIN_INTERVAL;

        // wait for interval duration before next measurement
        sleep(interval);
    }

    return 0;
}