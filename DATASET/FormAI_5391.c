//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the road network as a graph
#define NUM_NODES 2
#define NUM_EDGES 2
int roads[NUM_EDGES][2] = {{0, 1}, {1, 0}};

// Define the vehicle structure
#define MAX_VEHICLES 10
struct Vehicle {
    int id;
    int src;
    int dest;
    int current_road;
    float position;
} vehicles[MAX_VEHICLES];
int num_vehicles = 0;

// Generate traffic flow randomly
void generate_traffic_flow() {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (num_vehicles >= MAX_VEHICLES) {
            break;
        }
        int src = rand() % NUM_NODES;
        int dest = rand() % NUM_NODES;
        if (src == dest) {
            continue;
        }
        vehicles[num_vehicles].id = num_vehicles;
        vehicles[num_vehicles].src = src;
        vehicles[num_vehicles].dest = dest;
        vehicles[num_vehicles].current_road = -1;
        vehicles[num_vehicles].position = 0.0;
        num_vehicles++;
    }
}

// Simulate the movement of vehicles on the road network
void simulate() {
    float time_step = 0.1;
    int max_iterations = 100;
    for (int iter = 0; iter < max_iterations; iter++) {
        for (int v = 0; v < num_vehicles; v++) {
            if (vehicles[v].current_road < 0) {
                // Find a road that connects the source and the destination
                for (int r = 0; r < NUM_EDGES; r++) {
                    int src = vehicles[v].src;
                    int dest = vehicles[v].dest;
                    if (roads[r][0] == src && roads[r][1] == dest) {
                        vehicles[v].current_road = r;
                        break;
                    }
                }
            }
            if (vehicles[v].current_road >= 0) {
                // Update the position of the vehicle on the current road
                int r = vehicles[v].current_road;
                float speed = 1.0;
                float new_position = vehicles[v].position + speed * time_step;
                if (new_position >= 1.0) {
                    // The vehicle has reached the end of the current road
                    vehicles[v].current_road = -1;
                    vehicles[v].position = 0.0;
                } else {
                    vehicles[v].position = new_position;
                }
            }
        }
    }
}

int main() {
    // Initialize random seed
    srand(time(0));

    // Generate traffic flow
    generate_traffic_flow();

    // Simulate traffic flow
    simulate();

    // Print the final positions of vehicles
    for (int v = 0; v < num_vehicles; v++) {
        printf("Vehicle %d: position=%.2f on road %d\n", vehicles[v].id, vehicles[v].position,
        vehicles[v].current_road);
    }

    return 0;
}