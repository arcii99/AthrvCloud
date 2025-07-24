//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOOR 5
#define NUM_ELEVATORS 3

// Data structures to represent the state of an elevator
typedef enum {
    IDLE,
    UP,
    DOWN
} Direction;

typedef struct {
    int current_floor;
    Direction direction;
    int passengers;
    sem_t mutex;
} Elevator;

// Global variables to represent the state of the elevator system
int waiting[MAX_FLOOR]; // Number of passengers waiting on each floor
int in_transit = 0; // Number of passengers currently in transit
Elevator elevators[NUM_ELEVATORS]; // Array of Elevator structs

// Function to simulate the passage of time in the elevator system
void* simulate_time(void* arg) {
    while (1) {
        // Sleep for 1 second
        sleep(1);
        
        // Check each elevator for updates to its state
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            Elevator* e = &elevators[i];
            
            // Acquire the elevator's mutex before modifying its state
            sem_wait(&e->mutex);
            
            switch (e->direction) {
                case UP:
                    e->current_floor++;
                    break;
                case DOWN:
                    e->current_floor--;
                    break;
                default:
                    break;
            }
            
            // If the elevator arrives at a floor where passengers are waiting, let them on
            if (waiting[e->current_floor] > 0) {
                int passengers_boarded = waiting[e->current_floor];
                waiting[e->current_floor] = 0;
                e->passengers += passengers_boarded;
                in_transit += passengers_boarded;
                printf("Elevator %d picks up %d passengers on floor %d\n", i, passengers_boarded, e->current_floor);
            }
            
            // If the elevator arrives at its final destination, change direction and release any passengers on board
            if (e->current_floor == 0 || e->current_floor == MAX_FLOOR) {
                e->direction = e->current_floor == 0 ? UP : DOWN;
                printf("Elevator %d changes direction to %s\n", i, e->direction == UP ? "UP" : "DOWN");
                
                in_transit -= e->passengers;
                e->passengers = 0;
            }
            
            // Release the elevator's mutex before finishing
            sem_post(&e->mutex);
        }
        
        // If there are no passengers left in the system, terminate the simulation
        if (in_transit == 0) {
            printf("All passengers have reached their destination. Simulation terminating.\n");
            exit(0);
        }
    }
}

int main() {
    // Initialize the elevators and their semaphores
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].direction = UP;
        elevators[i].passengers = 0;
        sem_init(&elevators[i].mutex, 0, 1);
    }
    
    // Initialize the waiting array to 0 passengers on every floor
    for (int i = 0; i < MAX_FLOOR; i++) {
        waiting[i] = 0;
    }
    
    // Spawn a new thread to simulate the passage of time in the system
    pthread_t time_thread;
    pthread_create(&time_thread, NULL, simulate_time, NULL);
    
    // Prompt the user to enter the number of passengers waiting on each floor
    for (int i = 0; i < MAX_FLOOR; i++) {
        printf("Enter the number of passengers waiting on floor %d: ", i);
        scanf("%d", &waiting[i]);
    }
    
    return 0;
}