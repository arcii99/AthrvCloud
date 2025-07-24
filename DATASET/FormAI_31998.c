//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STREETS 10
#define MAX_STREET_LEN 20

char streets[MAX_STREETS][MAX_STREET_LEN] = {
    "Sapphire Lane",
    "Emerald Road",
    "Ruby Avenue",
    "Topaz Street",
    "Amethyst Boulevard",
    "Diamond Drive",
    "Pearl Court",
    "Opal Way",
    "Onyx Place",
    "Garnet Lane"
};

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int num_streets = rand() % MAX_STREETS + 1; // select random number of streets
    char route[num_streets * MAX_STREET_LEN]; // create a route string
    
    // randomly choose streets and append to route string
    for (int i = 0; i < num_streets; i++) {
        int street_index = rand() % MAX_STREETS;
        strcat(route, streets[street_index]);
        strcat(route, " -> ");
    }
    
    // remove the last " -> " from the route string
    int len = strlen(route);
    route[len - 4] = '\0';
    
    // print the route to the console
    printf("GPS Navigation Simulation\n\n");
    printf("Route: %s\n\n", route);
    
    return 0;
}