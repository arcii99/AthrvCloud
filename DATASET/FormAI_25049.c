//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEVICES 20
#define MAX_NODES 100

struct Device {
    char name[10];
    int node1;
    int node2;
    double value;
    double prevVoltage;
    double prevCurrent;
};

struct Node {
    int numConnectedDevices;
    int connectedDevices[MAX_DEVICES];
    double voltage;
};

int numNodes = 0;
int numDevices = 0;

struct Node nodes[MAX_NODES];
struct Device devices[MAX_DEVICES];

void addDevice(char name[], int node1, int node2, double value) {
    struct Device device;
    strcpy(device.name, name);
    device.node1 = node1;
    device.node2 = node2;
    device.value = value;
    device.prevVoltage = 0.0;
    device.prevCurrent = 0.0;

    devices[numDevices++] = device;
}

void addNode(int deviceIndex, int nodeIndex) {
    if (nodes[nodeIndex].numConnectedDevices >= MAX_DEVICES) {
        printf("Error: Node has too many connected devices!\n");
        exit(1);
    }

    nodes[nodeIndex].connectedDevices[nodes[nodeIndex].numConnectedDevices++] = deviceIndex;
}

void simulate(double timestep, double endTime) {
    double currentTime = 0.0;

    while (currentTime <= endTime) {
        // Calculate current through each device
        for (int i = 0; i < numDevices; i++) {
            struct Device device = devices[i];
            struct Node node1 = nodes[device.node1];
            struct Node node2 = nodes[device.node2];

            double voltageDiff = node1.voltage - node2.voltage;
            double current = voltageDiff / device.value;

            device.prevCurrent = current;
            devices[i] = device;

            addNode(i, device.node1);
            addNode(i, device.node2);
        }

        // Calculate new voltage for each node
        for (int i = 0; i < numNodes; i++) {
            double totalCurrent = 0.0;

            for (int j = 0; j < nodes[i].numConnectedDevices; j++) {
                int deviceIndex = nodes[i].connectedDevices[j];
                struct Device device = devices[deviceIndex];

                if (i == device.node1) {
                    totalCurrent += device.prevCurrent;
                } else {
                    totalCurrent -= device.prevCurrent;
                }
            }

            nodes[i].voltage = nodes[i].voltage + (totalCurrent * timestep);
        }

        // Print out voltage for each node
        printf("Time: %.2f \n", currentTime);
        for (int i = 0; i < numNodes; i++) {
            printf("Node %d voltage: %.2f \n", i, nodes[i].voltage);
        }
        printf("\n");

        currentTime += timestep;
    }
}

int main() {
    addDevice("R1", 0, 1, 100.0);
    addDevice("R2", 1, 2, 50.0);

    numNodes = 3;
    nodes[0].voltage = 10.0;

    simulate(0.01, 1.0);

    return 0;
}