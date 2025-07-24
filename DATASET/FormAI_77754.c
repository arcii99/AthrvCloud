//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100           // Maximum number of bags that can be handled at a time
#define MAX_CONVEYORS 10       // Maximum number of conveyors in the system

#define ARRIVAL_DELAY 2        // Delay in seconds before a new set of bags arrives
#define CONVEYOR_SPEED 5       // Speed of each conveyor belt in meters per second
#define TURN_AROUND_TIME 10    // Time in seconds required to turn around a loaded conveyor belt

typedef struct {
    int id;                    // Unique ID assigned to each bag
    double weight;             // Weight of the bag in kg (up to 100 kg)
    double size;               // Size of the bag in meters cubed (up to 1 m cubed)
} Bag;

typedef struct {
    int id;                    // Unique ID assigned to each conveyor belt
    double length;             // Length of the conveyor belt in meters (up to 100 m)
    double capacity;           // Maximum weight capacity of the conveyor belt in kg (up to 1000 kg)
    Bag bags[MAX_BAGS];        // Array of bags currently on the conveyor belt
    int num_bags;              // Number of bags currently on the conveyor belt
    int loaded;                // Boolean flag indicating if the conveyor belt is loaded or not
} Conveyor;

int main() {
    srand(time(NULL));         // Generate a seed for the random number generator
    int num_conveyors = rand() % MAX_CONVEYORS + 1;   // Generate a random number of conveyors between 1 and MAX_CONVEYORS
    Conveyor conveyors[num_conveyors];              // Create an array of conveyors
    
    for (int i = 0; i < num_conveyors; i++) {      // Initialize each conveyor with random parameters
        conveyors[i].id = i;
        conveyors[i].length = (double)(rand() % 1000 + 1) / 10;
        conveyors[i].capacity = (double)(rand() % 1000 + 1);
        conveyors[i].num_bags = 0;
        conveyors[i].loaded = 0;
    }
    
    int turn_around = 0;       // Time counter for the turn around time of a loaded conveyor belt
    
    while (1) {                // Simulation loop
        
        // Check if any loaded conveyor belts have completed the turn around time
        for (int i = 0; i < num_conveyors; i++) {
            if (conveyors[i].loaded == 1) {
                if (turn_around == TURN_AROUND_TIME) {
                    conveyors[i].loaded = 0;
                    conveyors[i].num_bags = 0;
                }
            }
        }
        
        int num_bags = rand() % MAX_BAGS + 1;   // Generate a random number of bags between 1 and MAX_BAGS
        
        // Check if there is enough space on any of the conveyor belts for the bags
        int space_available = 0;
        for (int i = 0; i < num_conveyors; i++) {
            if (conveyors[i].num_bags + num_bags < MAX_BAGS && conveyors[i].loaded == 0) {
                space_available = 1;
                break;
            }
        }
        
        if (space_available == 1) {       // If space is available, load the bags on the conveyor belt with the most space remaining
            int max_space_remaining = -1;   // Initialize to a negative number to ensure the first conveyor is loaded
            
            for (int i = 0; i < num_conveyors; i++) {
                if (conveyors[i].num_bags + num_bags < MAX_BAGS && conveyors[i].loaded == 0) {
                    int space_remaining = MAX_BAGS - conveyors[i].num_bags;
                    if (space_remaining > max_space_remaining) {
                        max_space_remaining = space_remaining;
                    }
                }
            }
            
            for (int i = 0; i < num_conveyors; i++) {
                if (conveyors[i].num_bags + num_bags < MAX_BAGS && conveyors[i].loaded == 0) {
                    int space_remaining = MAX_BAGS - conveyors[i].num_bags;
                    if (space_remaining == max_space_remaining) {
                        // Load the bags onto the current conveyor belt
                        for (int j = 0; j < num_bags; j++) {
                            Bag bag;
                            bag.id = rand() % 10000 + 1;
                            bag.weight = (double)(rand() % 1000 + 1) / 10;
                            bag.size = (double)(rand() % 100 + 1) / 100;
                            conveyors[i].bags[conveyors[i].num_bags] = bag;
                            conveyors[i].num_bags++;
                        }
                        conveyors[i].loaded = 1;
                        break;
                    }
                }
            }
        }
        
        // Move all loaded conveyor belts by CONVEYOR_SPEED distance
        for (int i = 0; i < num_conveyors; i++) {
            if (conveyors[i].loaded == 1) {
                conveyors[i].length -= CONVEYOR_SPEED;
            }
        }
        
        // Check if any loaded conveyor belts have reached the end of their length
        for (int i = 0; i < num_conveyors; i++) {
            if (conveyors[i].loaded == 1) {
                if (conveyors[i].length <= 0) {
                    turn_around = 1;
                }
            }
        }
        
        // Sleep for ARRIVAL_DELAY seconds before generating a new set of bags
        sleep(ARRIVAL_DELAY);
        
    }
    
    return 0;
}