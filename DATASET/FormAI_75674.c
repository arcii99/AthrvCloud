//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of lanes and maximum length of each lane
#define MAX_LANES 5
#define MAX_LANE_LENGTH 10

// Define the TrafficLane data structure
typedef struct TrafficLane {
    int cars[MAX_LANE_LENGTH];
    int length;
} TrafficLane;

// Define the TrafficSimulation data structure
typedef struct TrafficSimulation {
    TrafficLane lanes[MAX_LANES];
    int num_lanes;
    int time_step;
} TrafficSimulation;

// Function to initialize a TrafficLane
void initialize_lane(TrafficLane* lane, int length) {
    lane->length = length;
    for (int i = 0; i < length; i++) {
        lane->cars[i] = 0;
    }
}

// Function to initialize a TrafficSimulation
void initialize_simulation(TrafficSimulation* simulation, int num_lanes, int lane_length) {
    simulation->num_lanes = num_lanes;
    simulation->time_step = 0;
    for (int i = 0; i < num_lanes; i++) {
        initialize_lane(&(simulation->lanes[i]), lane_length);
    }
}

// Function to print the current state of a TrafficSimulation
void print_simulation(TrafficSimulation* simulation) {
    printf("Time Step %d:\n", simulation->time_step);
    for (int i = 0; i < simulation->num_lanes; i++) {
        TrafficLane* lane = &(simulation->lanes[i]);
        printf("Lane %d: ", i+1);
        for (int j = 0; j < lane->length; j++) {
            printf("%d ", lane->cars[j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to update the state of a single TrafficLane based on the state of the neighboring lanes
void update_lane(TrafficLane* lane, TrafficLane* left_lane, TrafficLane* right_lane) {
    // First, check if the lane is empty
    int empty = 1;
    for (int i = 0; i < lane->length; i++) {
        if (lane->cars[i] != 0) {
            empty = 0;
            break;
        }
    }
    if (empty) {
        return;
    }
    // Now, update the lane based on the state of the neighboring lanes
    TrafficLane new_lane = *lane;
    for (int i = 0; i < lane->length; i++) {
        if (lane->cars[i] != 0) {
            // Check if there is a car in front of us
            if (i < lane->length - 1 && lane->cars[i+1] != 0) {
                // Check if we can change lanes
                int left = 0, right = 0;
                if (left_lane != NULL && left_lane->cars[i] == 0) {
                    left = 1;
                }
                if (right_lane != NULL && right_lane->cars[i] == 0) {
                    right = 1;
                }
                if (left && right) {
                    // Choose a lane randomly
                    if (rand() % 2 == 0) {
                        new_lane.cars[i] = 0;
                        left_lane->cars[i] = lane->cars[i];
                    } else {
                        new_lane.cars[i] = 0;
                        right_lane->cars[i] = lane->cars[i];
                    }
                } else if (left) {
                    new_lane.cars[i] = 0;
                    left_lane->cars[i] = lane->cars[i];
                } else if (right) {
                    new_lane.cars[i] = 0;
                    right_lane->cars[i] = lane->cars[i];
                }
            } else {
                // Move forward by one step
                new_lane.cars[i+1] = lane->cars[i];
                new_lane.cars[i] = 0;
            }
        }
    }
    *lane = new_lane;
}

// Function to update the state of a TrafficSimulation based on the state of the neighboring lanes
void update_simulation(TrafficSimulation* simulation) {
    TrafficLane* left_lane = NULL;
    for (int i = 0; i < simulation->num_lanes; i++) {
        TrafficLane* lane = &(simulation->lanes[i]);
        TrafficLane* right_lane = NULL;
        if (i > 0) {
            left_lane = &(simulation->lanes[i-1]);
        }
        if (i < simulation->num_lanes - 1) {
            right_lane = &(simulation->lanes[i+1]);
        }
        update_lane(lane, left_lane, right_lane);
    }
    simulation->time_step++;
}

// Recursive function to simulate traffic flow in a TrafficSimulation
void simulate_traffic(TrafficSimulation* simulation, int num_steps) {
    if (num_steps <= 0) {
        return;
    }
    print_simulation(simulation);
    update_simulation(simulation);
    simulate_traffic(simulation, num_steps - 1);
}

// Main function to run the simulation
int main() {
    TrafficSimulation simulation;
    initialize_simulation(&simulation, 3, 10);
    // Add some cars to the simulation
    simulation.lanes[0].cars[1] = 1;
    simulation.lanes[0].cars[5] = 1;
    simulation.lanes[1].cars[4] = 1;
    simulation.lanes[1].cars[6] = 1;
    simulation.lanes[2].cars[3] = 1;
    simulation.lanes[2].cars[7] = 1;
    simulate_traffic(&simulation, 5);
    return 0;
}