//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to calculate traffic flow
int calculateFlow(int numVehicles, int speed) {
    return numVehicles * speed;
}

// Function to print traffic flow status
void printStatus(int flow) {
    printf("Traffic Flow: %d vehicles per hour.\n", flow);
    if(flow < 100) {
        printf("Low traffic volume.\n");
    } else if(flow >= 100 && flow < 300) {
        printf("Medium traffic volume.\n");
    } else {
        printf("High traffic volume.\n");
    }
}

int main() {
    int numVehicles, speed, flow;
    srand(time(0)); // Seed for random number generation

    printf("Welcome to the Traffic Flow Simulation program.\n");

    // Loop for simulating traffic flow
    while(1) {
        // Generate random number of vehicles and speed
        numVehicles = rand() % 100 + 1;
        speed = rand() % 60 + 30;

        // Calculate traffic flow
        flow = calculateFlow(numVehicles, speed);

        // Print traffic flow status
        printStatus(flow);

        // Sleep for 3 seconds before simulating next traffic flow
        printf("Simulating next traffic flow in 3 seconds...\n");
        sleep(3);
    }

    return 0;
}