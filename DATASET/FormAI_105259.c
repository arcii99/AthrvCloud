//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE 50 // Maximum number of luggage in the simulation
#define MAX_TIME 10 // Maximum time for a luggage to reach its destination

// Struct to hold luggage information
typedef struct {
    int id;
    int weight;
    int destination_gate;
    int arrival_time;
} Luggage;

// Function to generate random numbers
int random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(0));
    Luggage luggage_list[MAX_LUGGAGE];
    int total_weight = 0;
    for(int i = 0; i < MAX_LUGGAGE; i++) {
        luggage_list[i].id = i+1;
        luggage_list[i].weight = random_num(10, 100);
        total_weight += luggage_list[i].weight;
        luggage_list[i].destination_gate = random_num(1, 10);
        luggage_list[i].arrival_time = random_num(1, MAX_TIME);
    }
    
    int luggage_count[MAX_TIME];
    for(int i = 0; i < MAX_TIME; i++) {
        luggage_count[i] = 0;
    }
    
    printf("Simulating airport baggage handling...\n\n");
    printf("Total luggage generated: %d\n", MAX_LUGGAGE);
    printf("Total weight of luggage: %d lbs\n", total_weight);
    printf("\n=====================\n");
    
    for(int time = 1; time <= MAX_TIME; time++) {
        printf("Time: %d\n", time);
        printf("=====================\n");
        int luggage_processed = 0;
        int weight_processed = 0;
        int luggage_destinations[10];
        for(int i = 0; i < 10; i++) {
            luggage_destinations[i] = 0;
        }
        
        for(int i = 0; i < MAX_LUGGAGE; i++) {
            if(luggage_list[i].arrival_time == time) {
                printf("Luggage %d arrived at gate %d.\n", luggage_list[i].id, luggage_list[i].destination_gate);
                luggage_count[time-1]++;
                luggage_destinations[luggage_list[i].destination_gate-1]++;
            }
            
            if(luggage_processed == 5) {
                printf("\nMaximum luggage limit reached. Resuming at next time.\n");
                break;
            }
            
            if(luggage_list[i].destination_gate == 1) {
                printf("Luggage %d sent to local baggage claim.\n", luggage_list[i].id);
                luggage_processed++;
                weight_processed += luggage_list[i].weight;
            }
            
            else if(luggage_list[i].destination_gate != 1 && luggage_destinations[luggage_list[i].destination_gate-1] < 2) {
                printf("Luggage %d sent to gate %d baggage claim.\n", luggage_list[i].id, luggage_list[i].destination_gate);
                luggage_processed++;
                weight_processed += luggage_list[i].weight;
                luggage_destinations[luggage_list[i].destination_gate-1]++;
            }
        }
        
        printf("\nTotal luggage processed: %d\nTotal weight processed: %d lbs\n", luggage_processed, weight_processed);
        printf("\n=====================\n\n");
    }
    
    printf("Airport baggage handling simulation completed.\n\n");
    
    for(int i = 0; i < MAX_TIME; i++) {
        printf("Luggage arrived at time %d: %d\n", i+1, luggage_count[i]);
    }
    
    return 0;
}