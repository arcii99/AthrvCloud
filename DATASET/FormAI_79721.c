//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WAYPOINTS 100            // Maximum number of waypoints
#define MAX_DISTANCE 200            // Maximum distance between two waypoints
#define MAX_COORDINATE 1000         // Maximum coordinate value

typedef struct Waypoint {
    int id;                         // Waypoint id
    int x, y;                       // Coordinates of waypoint
} Waypoint;

int num_waypoints;                  // Number of waypoints
Waypoint waypoints[MAX_WAYPOINTS];  // Array of waypoints

// Function to create random coordinates for a waypoint
void createWaypoint(int id) {
    waypoints[id].id = id;
    waypoints[id].x = rand() % MAX_COORDINATE;
    waypoints[id].y = rand() % MAX_COORDINATE;
}

// Function to calculate distance between two waypoints
double distance(int i, int j) {
    return sqrt(pow(waypoints[i].x - waypoints[j].x, 2) + pow(waypoints[i].y - waypoints[j].y, 2));
}

// Function to print the waypoint coordinates
void printWaypoints() {
    printf("Waypoints:\n");
    for (int i = 0; i < num_waypoints; i++) {
        printf("Waypoint %d: (%d, %d)\n", waypoints[i].id, waypoints[i].x, waypoints[i].y);
    }
}

// Main function
int main() {
    srand(time(NULL));                      // Seed random number generator
    num_waypoints = rand() % MAX_WAYPOINTS;  // Generate number of waypoints randomly

    // Create random coordinates for each waypoint
    for (int i = 0; i < num_waypoints; i++) {
        createWaypoint(i);
    }

    printWaypoints();   // Print the waypoint coordinates

    // Calculate and print distances between all waypoints
    printf("Distances:\n");
    for (int i = 0; i < num_waypoints; i++) {
        for (int j = i+1; j < num_waypoints; j++) {
            double d = distance(i, j);
            printf("Distance between Waypoint %d and Waypoint %d: %.2f units\n", i, j, d);
        }
    }

    return 0;
}