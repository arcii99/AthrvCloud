//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the paranoid threshold values for various metrics
const int BANDWIDTH_THRESHOLD = 500000;
const int LATENCY_THRESHOLD = 50;
const int PACKET_LOSS_THRESHOLD = 10;

// Define the structure to store the QoS metrics
typedef struct qos_data {
    int bandwidth;
    int latency;
    int packet_loss;
} QoSData;

// Define a function to simulate random values for QoS metrics
void simulate_data(QoSData *data) {
    srand(time(NULL));
    data->bandwidth = rand() % 1000000 + 1;
    data->latency = rand() % 100 + 1;
    data->packet_loss = rand() % 20 + 1;
}

int main() {
    QoSData data;
    bool paranoid_mode = false;
    int counter = 0;

    printf("Starting network QoS monitor...\n");

    // Infinite loop
    while (true) {
        // Simulate random QoS data
        simulate_data(&data);

        // Check if QoS metrics meet paranoid thresholds
        if (data.bandwidth < BANDWIDTH_THRESHOLD ||
            data.latency > LATENCY_THRESHOLD ||
            data.packet_loss > PACKET_LOSS_THRESHOLD) {
            paranoid_mode = true;
        } else {
            paranoid_mode = false;
        }

        // Print QoS data and paranoid mode status
        printf("\n### QoS Data ###\n");
        printf("Bandwidth: %d\n", data.bandwidth);
        printf("Latency: %d\n", data.latency);
        printf("Packet Loss: %d\n", data.packet_loss);
        printf("Paranoid Mode: %s\n", paranoid_mode ? "ON" : "OFF");

        // Sleep for 1 second
        counter++;
        if (counter == 5) {
            break;
        }
        printf("\nWaiting for 1 second...\n");
        sleep(1);
    }

    printf("\nExiting network QoS monitor...\n");

    return 0;
}