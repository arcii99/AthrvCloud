//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLOORS 5

int main()
{
    srand(time(NULL));
    int num_bags = rand() % MAX_BAGS + 1;
    int num_floors = rand() % MAX_FLOORS + 1;
    
    printf("Starting baggage handling simulation...\n");
    printf("Number of bags: %d\n", num_bags);
    printf("Number of floors: %d\n", num_floors);
    
    int floors[num_floors][MAX_BAGS]; // Create array for bags on each floor
    for (int i = 0; i < num_floors; i++) {
        for (int j = 0; j < num_bags; j++) {
            floors[i][j] = 0; // Initialize all bags to not on this floor
        }
    }
    
    // Move bags to different floors at random
    for (int i = 0; i < num_bags; i++) {
        int floor = rand() % num_floors;
        floors[floor][i] = 1;
    }
    
    // Print out the final location of each bag
    printf("Final baggage location:\n");
    for (int i = 0; i < num_bags; i++) {
        printf("Bag %d: Floor ", i+1);
        for (int j = 0; j < num_floors; j++) {
            if (floors[j][i] == 1) {
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
    
    return 0;
}