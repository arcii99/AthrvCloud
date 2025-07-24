//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_TERMINALS 5
#define MAX_CONVEYORS 20

typedef struct {
    int id;
    int terminal;
} Baggage;

typedef struct {
    int id;
    int source_terminal;
    int destination_terminal;
    int speed;
} Conveyor;

Baggage baggage[MAX_BAGGAGE];
Conveyor conveyors[MAX_CONVEYORS];
int baggage_count = 0;
int conveyor_count = 0;
int baggage_in_system = 0;

void init_baggage() {
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i].id = i;
        baggage[i].terminal = rand() % MAX_TERMINALS + 1;
    }
    baggage_count = MAX_BAGGAGE;
}

void init_conveyors() {
    for (int i = 0; i < MAX_CONVEYORS; i++) {
        conveyors[i].id = i;
        conveyors[i].source_terminal = rand() % MAX_TERMINALS + 1;
        conveyors[i].destination_terminal = rand() % MAX_TERMINALS + 1;
        conveyors[i].speed = rand() % 10 + 1; // speed is in meters per second
    }
    conveyor_count = MAX_CONVEYORS;
}

void move_baggage(Baggage *baggage, Conveyor *conveyor) {
    printf("Moving baggage %d from terminal %d to terminal %d\n", baggage->id, conveyor->source_terminal, conveyor->destination_terminal);
    baggage->terminal = conveyor->destination_terminal;
    baggage_in_system--;
}

void update_system() {
    for (int i = 0; i < conveyor_count; i++) {
        Conveyor *conveyor = &conveyors[i];
        for (int j = 0; j < baggage_count; j++) {
            Baggage *baggage = &baggage[j];
            if (baggage->terminal == conveyor->source_terminal) {
                if (rand() % 100 < conveyor->speed) {
                    move_baggage(baggage, conveyor);
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    init_baggage();
    init_conveyors();
    
    // Main loop
    while (1) {
        // Generate new baggage
        if (baggage_in_system < MAX_BAGGAGE) {
            int new_baggage_count = rand() % 10 + 1;
            for (int i = 0; i < new_baggage_count; i++) {
                Baggage *new_baggage = &baggage[baggage_count];
                new_baggage->id = baggage_count++;
                new_baggage->terminal = rand() % MAX_TERMINALS + 1;
                baggage_in_system++;
                printf("New baggage %d added to terminal %d\n", new_baggage->id, new_baggage->terminal);
            }
        }
        
        // Update system
        update_system();
        
        // Delay for 1 second
        struct timespec delay = { 1, 0 };
        nanosleep(&delay, NULL);
    }
    
    return 0;
}