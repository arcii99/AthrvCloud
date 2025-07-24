//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define constants for the simulation
#define TOTAL_BAGS 50
#define MAX_WEIGHT 50
#define MAX_VOLUME 100

// Define struct for bags
typedef struct baggage_t{
    int weight;
    int volume;
} baggage;

// Initialize an array of bags with random weights and volumes
void init_bags(baggage* bags, int n){
    for(int i=0; i<n; i++){
        bags[i].weight = rand()%MAX_WEIGHT + 1;
        bags[i].volume = rand()%MAX_VOLUME + 1;
    }
}

// Calculate the total weight and volume of all bags
void total_weight_volume(baggage* bags, int n, int* total_weight, int* total_volume){
    *total_weight = 0;
    *total_volume = 0;
    for(int i=0; i<n; i++){
        *total_weight += bags[i].weight;
        *total_volume += bags[i].volume;
    }
}

int main(){
    int total_weight, total_volume;
    baggage bags[TOTAL_BAGS];
    init_bags(bags, TOTAL_BAGS);
    total_weight_volume(bags, TOTAL_BAGS, &total_weight, &total_volume);
    printf("Total weight of bags: %d\n", total_weight);
    printf("Total volume of bags: %d\n", total_volume);
    return 0;
}