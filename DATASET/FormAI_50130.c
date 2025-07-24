//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Randomly generate traffic flow data
void generateFlowData(int* trafficFlow, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        trafficFlow[i] = rand() % 50;
    }
}

// Calculate average traffic flow across all lanes
float getAverageFlow(int* trafficFlow, int size) {
    int totalFlow = 0;
    for (int i = 0; i < size; i++) {
        totalFlow += trafficFlow[i];
    }
    return (float)totalFlow / size;
}

// Determine the busiest lane
int getBusiestLane(int* trafficFlow, int size) {
    int busiestLane = 0;
    for (int i = 1; i < size; i++) {
        if (trafficFlow[i] > trafficFlow[busiestLane]) {
            busiestLane = i;
        }
    }
    return busiestLane;
}

int main() {
    int laneCount = 5;
    int trafficFlow[laneCount];
    generateFlowData(trafficFlow, laneCount);

    printf("Traffic flow data:\n");
    for (int i = 0; i < laneCount; i++) {
        printf("Lane %d: %d cars per minute\n", i + 1, trafficFlow[i]);
    }

    float averageFlow = getAverageFlow(trafficFlow, laneCount);
    printf("\nAverage traffic flow: %.2f cars per minute\n", averageFlow);

    int busiestLane = getBusiestLane(trafficFlow, laneCount);
    printf("\nBusiest lane: Lane %d\n", busiestLane + 1);

    return 0;
}