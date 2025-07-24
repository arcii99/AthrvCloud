//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define NUM_BAGS 100
#define MAX_DELAY 10

// Struct to hold information about a single bag
typedef struct {
    int id;
    int weight;
    int destination_gate;
} Baggage;

// Struct to hold information about a single gate
typedef struct {
    int id;
    int num_bags;
    pthread_mutex_t lock;
} Gate;

// Global arrays to hold bags and gates, and a mutex lock for the main thread
Baggage bags[NUM_BAGS];
Gate gates[4];
pthread_mutex_t main_lock;

// Function to generate bags with random weights and destination gates
void generate_bags() {
    srand(time(NULL));
    for(int i=0; i<NUM_BAGS; i++) {
        bags[i].id = i;
        bags[i].weight = rand()%50 + 1;
        bags[i].destination_gate = rand()%4;
    }
}

// Function for a baggage handler to unload bags from a plane and place them onto the appropriate gate
void* baggage_handler(void* arg) {
    int gate_id = *((int*)arg);
    for(int i=0; i<NUM_BAGS; i++) {
        // Check if bag is supposed to go to this gate
        if(bags[i].destination_gate == gate_id) {
            // Delay for random amount of time to simulate unloading from plane
            int delay = rand()%MAX_DELAY + 1;
            printf("Bag %d being unloaded onto Gate %d\n", bags[i].id, gate_id);
            sleep(delay);
            // Add bag to gate
            pthread_mutex_lock(&gates[gate_id].lock);
            gates[gate_id].num_bags++;
            pthread_mutex_unlock(&gates[gate_id].lock);
            printf("Bag %d added to Gate %d\n", bags[i].id, gate_id);
        }
    }
    free(arg);
    pthread_exit(NULL);
}

// Main function to start simulation
int main() {
    generate_bags();
    pthread_t handlers[4];
    // Initialize gates
    for(int i=0; i<4; i++) {
        gates[i].id = i;
        gates[i].num_bags = 0;
        pthread_mutex_init(&gates[i].lock, NULL);
    }
    // Initialize main lock
    pthread_mutex_init(&main_lock, NULL);
    // Start baggage handlers for each gate
    for(int i=0; i<4; i++) {
        int* arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&handlers[i], NULL, baggage_handler, arg);
    }
    // Wait for baggage handlers to finish
    for(int i=0; i<4; i++) {
        pthread_join(handlers[i], NULL);
    }
    // Output final bag counts for each gate
    for(int i=0; i<4; i++) {
        printf("Gate %d has %d bags\n", i, gates[i].num_bags);
    }
    // Destroy gates and main lock
    for(int i=0; i<4; i++) {
        pthread_mutex_destroy(&gates[i].lock);
    }
    pthread_mutex_destroy(&main_lock);
    return 0;
}