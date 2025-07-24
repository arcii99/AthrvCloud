//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define MAX_PACKET_SIZE 1500

typedef struct metrics {
    int data_rate;
    int latency;
    int packet_loss;
} Metrics;

typedef struct device {
    char name[20];
    Metrics metrics;
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;

void update_metrics() {
    int i;
    srand(time(0));
    for (i = 0; i < num_devices; i++) {
        devices[i].metrics.data_rate = rand() % 100 + 1;
        devices[i].metrics.latency = rand() % 10 + 1;
        devices[i].metrics.packet_loss = rand() % 5;
    }
}

void print_metrics() {
    int i;
    printf("-----------------------------------------------------\n");
    printf("Device Name\tData Rate\tLatency\tPacket Loss\n");
    printf("-----------------------------------------------------\n");
    for (i = 0; i < num_devices; i++) {
        printf("%s\t\t%d\t\t%d\t%d%%\n", devices[i].name, devices[i].metrics.data_rate, devices[i].metrics.latency, devices[i].metrics.packet_loss);
    }
    printf("-----------------------------------------------------\n");
}

void shapeshift() {
    int i;
    for (i = 0; i < num_devices; i++) {
        if (devices[i].metrics.data_rate < 50) {
            printf("%s is shapeshifting into a faster device!\n", devices[i].name);
            strcpy(devices[i].name, "Faster Device");
            devices[i].metrics.data_rate = rand() % 100 + 100;
            devices[i].metrics.latency = rand() % 5;
            devices[i].metrics.packet_loss = rand() % 2;
        }
        else if (devices[i].metrics.packet_loss > 3) {
            printf("%s is shapeshifting into a more stable device!\n", devices[i].name);
            strcpy(devices[i].name, "Stable Device");
            devices[i].metrics.data_rate = rand() % 50 + 50;
            devices[i].metrics.latency = rand() % 2;
            devices[i].metrics.packet_loss = rand() % 2;
        }
    }
}

int main() {
    int i;
    // Populate devices array with default values
    strcpy(devices[0].name, "Device 1");
    devices[0].metrics.data_rate = 75;
    devices[0].metrics.latency = 2;
    devices[0].metrics.packet_loss = 0;
    strcpy(devices[1].name, "Device 2");
    devices[1].metrics.data_rate = 50;
    devices[1].metrics.latency = 5;
    devices[1].metrics.packet_loss = 2;
    num_devices = 2;
    while (1) {
        update_metrics();
        print_metrics();
        shapeshift();
        sleep(5);
    }
    return 0;
}