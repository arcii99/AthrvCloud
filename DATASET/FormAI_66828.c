//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_ROUTES 10

typedef struct {
    int weight;
    int route;
} Baggage;

int main() {
    Baggage baggage[MAX_BAGGAGE];
    int routes[MAX_ROUTES][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 1}};
    int num_bags = 0;
    int total_weight = 0;
    int i, j;

    srand(time(NULL));

    // generate random baggage data
    for (i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i].weight = rand() % 20 + 1;
        baggage[i].route = rand() % MAX_ROUTES;
        total_weight += baggage[i].weight;
    }
    
    printf("Welcome to Airport Baggage Handling Simulation!\n");
    printf("Total number of baggage: %d, Total weight: %d\n", MAX_BAGGAGE, total_weight);

    // display routes
    printf("Available Routes: \n");
    for (i = 0; i < MAX_ROUTES; i++) {
        printf("%d -> %d\n", routes[i][0], routes[i][1]);
    }

    // distribute baggage to routes
    printf("\nDistributing baggage to routes...\n");
    for (i = 0; i < MAX_BAGGAGE; i++) {
        int route = baggage[i].route;
        printf("Baggage %d (weight %d) -> Route %d\n", i+1, baggage[i].weight, route+1);
    }

    // calculate total weight for each route
    int route_weight[MAX_ROUTES] = {0};
    for (i = 0; i < MAX_BAGGAGE; i++) {
        int route = baggage[i].route;
        route_weight[route] += baggage[i].weight;
    }

    // display route statistics
    printf("\nRoute Statistics:\n");
    for (i = 0; i < MAX_ROUTES; i++) {
        printf("Route %d -> Total Weight: %d\n", i+1, route_weight[i]);
    }

    // calculate average weight for each route
    float avg_weight[MAX_ROUTES] = {0};
    for (i = 0; i < MAX_ROUTES; i++) {
        avg_weight[i] = (float)route_weight[i] / MAX_BAGGAGE;
    }

    // display average route weight
    printf("\nAverage Route Weight:\n");
    for (i = 0; i < MAX_ROUTES; i++) {
        printf("Route %d -> Average Weight: %.2f\n", i+1, avg_weight[i]);
    }

    return 0;
}