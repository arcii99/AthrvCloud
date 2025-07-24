//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE_COUNT 100
#define MAX_GATE_COUNT 10

typedef struct {
    int flight_number;
    int gate_number;
    char destination[100];
} Flight;

typedef struct {
    int id;
    bool is_assigned;
    int flight_number;
} Gate;

typedef struct {
    int id;
    int flight_number;
    int start_time;
    int end_time;
} Baggage;

int main() {
    srand(time(NULL));
    
    // Generate random flight details
    Flight flights[MAX_BAGGAGE_COUNT];
    for(int i = 0; i < MAX_BAGGAGE_COUNT; i++) {
        flights[i].flight_number = i + 1;
        flights[i].gate_number = rand() % MAX_GATE_COUNT + 1;
        sprintf(flights[i].destination, "Destination %d", rand() % 10 + 1);
    }
    
    // Initialize gates
    Gate gates[MAX_GATE_COUNT];
    for(int i = 0; i < MAX_GATE_COUNT; i++) {
        gates[i].id = i + 1;
        gates[i].is_assigned = false;
        gates[i].flight_number = -1;
    }
    
    // Initialize baggage
    Baggage baggage[MAX_BAGGAGE_COUNT];
    for(int i = 0; i < MAX_BAGGAGE_COUNT; i++) {
        baggage[i].id = i + 1;
        baggage[i].flight_number = flights[i].flight_number;
        baggage[i].start_time = rand() % 10 + 1;
        baggage[i].end_time = -1;
    }
    
    // Start simulation
    int current_time = 0;
    while(1) {
        // Update gate status
        for(int i = 0; i < MAX_GATE_COUNT; i++) {
            if(gates[i].is_assigned && current_time > baggage[gates[i].flight_number - 1].end_time) {
                printf("Baggage %d for flight %d has been loaded onto gate %d and is ready for departure to %s\n",
                baggage[gates[i].flight_number - 1].id, baggage[gates[i].flight_number - 1].flight_number,
                gates[i].id, flights[gates[i].flight_number - 1].destination);
                gates[i].is_assigned = false;
                gates[i].flight_number = -1;
            }
        }
        
        // Assign gates to baggage
        for(int i = 0; i < MAX_BAGGAGE_COUNT; i++) {
            if(baggage[i].start_time == current_time) {
                for(int j = 0; j < MAX_GATE_COUNT; j++) {
                    if(!gates[j].is_assigned) {
                        gates[j].is_assigned = true;
                        gates[j].flight_number = baggage[i].flight_number;
                        baggage[i].end_time = current_time + rand() % 5 + 1;
                        printf("Baggage %d for flight %d has been assigned to gate %d\n",
                        baggage[i].id, baggage[i].flight_number, gates[j].id);
                        break;
                    }
                }
            }
        }
        
        // Check if simulation is finished
        bool is_finished = true;
        for(int i = 0; i < MAX_BAGGAGE_COUNT; i++) {
            if(baggage[i].end_time == -1) {
                is_finished = false;
                break;
            }
        }
        if(is_finished) {
            break;
        }
        
        current_time++;
    }
    
    return 0;
}