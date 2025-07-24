//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_TERMINALS 5
#define MAX_LANES 10

// Declare structs
typedef struct{
    int id;
    int weight;
    int terminal;
}Bag;

typedef struct{
    int id;
    int capacity;
    int terminal;
    Bag* bags[MAX_BAGS];
    int num_bags;
}Lane;

// Function prototypes
void initialize_lanes(Lane* lanes[MAX_LANES]);
void load_bags(Lane* l, int num_bags);
void transfer_bags(Lane* from_lane, Lane* to_lane);
void print_statistics(Lane* lanes[MAX_LANES]);

// Main function
int main(){
    // Initialize lanes
    Lane* lanes[MAX_LANES];
    initialize_lanes(lanes);
    
    // Load bags onto lanes
    srand(time(0));
    for(int i = 0; i < 50; i++){
        int num_bags = rand() % 50 + 1;
        int lane_index = rand() % MAX_LANES;
        load_bags(lanes[lane_index], num_bags);
    }
    
    // Transfer bags between lanes
    for(int i = 0; i < 10; i++){
        int from_index = rand() % MAX_LANES;
        int to_index = rand() % MAX_LANES;
        if(from_index == to_index){
            to_index = (to_index + 1) % MAX_LANES;
        }
        transfer_bags(lanes[from_index], lanes[to_index]);
    }
    
    // Print statistics
    print_statistics(lanes);
    
    // Free memory
    for(int i = 0; i < MAX_LANES; i++){
        free(lanes[i]);
    }
    
    return 0;
}

// Function to initialize lanes
void initialize_lanes(Lane* lanes[MAX_LANES]){
    for(int i = 0; i < MAX_LANES; i++){
        lanes[i] = (Lane*)malloc(sizeof(Lane));
        lanes[i]->id = i+1;
        lanes[i]->capacity = 100;
        lanes[i]->terminal = i % MAX_TERMINALS + 1;
        lanes[i]->num_bags = 0;
    }
}

// Function to load bags onto a lane
void load_bags(Lane* l, int num_bags){
    if(l->num_bags + num_bags > l->capacity){
        num_bags = l->capacity - l->num_bags;
    }
    for(int i = 0; i < num_bags; i++){
        Bag* b = (Bag*)malloc(sizeof(Bag));
        b->id = l->num_bags + i + 1;
        b->weight = rand() % 25 + 1;
        b->terminal = l->terminal;
        l->bags[l->num_bags + i] = b;
    }
    l->num_bags += num_bags;
}

// Function to transfer bags from one lane to another
void transfer_bags(Lane* from_lane, Lane* to_lane){
    int num_bags = rand() % from_lane->num_bags + 1;
    if(num_bags > to_lane->capacity - to_lane->num_bags){
        num_bags = to_lane->capacity - to_lane->num_bags;
    }
    for(int i = 0; i < num_bags; i++){
        to_lane->bags[to_lane->num_bags + i] = from_lane->bags[from_lane->num_bags - num_bags + i];
    }
    from_lane->num_bags -= num_bags;
    to_lane->num_bags += num_bags;
}

// Function to print statistics
void print_statistics(Lane* lanes[MAX_LANES]){
    printf("Lane ID\tTerminal ID\tNumber of Bags\n");
    for(int i = 0; i < MAX_LANES; i++){
        printf("%d\t%d\t\t%d\n", lanes[i]->id, lanes[i]->terminal, lanes[i]->num_bags);
    }
}