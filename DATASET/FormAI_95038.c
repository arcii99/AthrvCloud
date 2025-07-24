//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_ELEVATORS 3
#define NUM_FLOORS 10

// Global variables
int floor_requests[NUM_FLOORS] = {0};
int elevator_requests[NUM_ELEVATORS] = {0};
int elevators_on_floor[NUM_FLOORS][NUM_ELEVATORS] = {0};
int current_floor = 0;

// Function declarations
void* elevator_routine(void* arg);
void* floor_routine(void* arg);
int get_floor_request();
int get_elevator_request();
void move_elevator(int elevator_num);

// Main function
int main()
{
    // Initialize random seed
    srand(time(NULL));
    
    // Create threads for the elevators
    pthread_t elevator_threads[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, elevator_routine, (void*)i);
    }
    
    // Create thread for the floor
    pthread_t floor_thread;
    pthread_create(&floor_thread, NULL, floor_routine, NULL);
    
    // Wait for threads to finish
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }
    pthread_join(floor_thread, NULL);
    
    return 0;
}

// Elevator thread routine
void* elevator_routine(void* arg)
{
    int elevator_num = (int)arg;
    
    while (1) {
        // Check if there are any elevator requests
        if (elevator_requests[elevator_num] != 0) {
            // Move elevator to requested floor
            move_elevator(elevator_num);
            // Reset elevator request
            elevator_requests[elevator_num] = 0;
            // Remove elevator from the floor
            elevators_on_floor[current_floor][elevator_num] = 0;
        }
        
        // Sleep for a random amount of time before checking again
        usleep(rand() % 500000);
    }
    
    return NULL;
}

// Floor thread routine
void* floor_routine(void* arg)
{
    while (1) {
        // Check if there are any floor requests
        int floor_num = get_floor_request();
        if (floor_num != -1) {
            // Send elevator to requested floor
            int elevator_num = get_elevator_request();
            if (elevator_num != -1) {
                // Add elevator to the floor
                elevators_on_floor[floor_num][elevator_num] = 1;
                // Set elevator request
                elevator_requests[elevator_num] = floor_num;
                // Wait for elevator to arrive
                while (current_floor != floor_num || elevators_on_floor[floor_num][elevator_num] != 0) {
                    usleep(rand() % 100000);
                }
                // Reset floor request
                floor_requests[floor_num] = 0;
                // Remove elevator from the floor
                elevators_on_floor[floor_num][elevator_num] = 0;
            }
        }
        
        // Sleep for a random amount of time before checking again
        usleep(rand() % 500000);
    }
    
    return NULL;
}

// Get the next floor request
int get_floor_request()
{
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (floor_requests[i] != 0) {
            return i;
        }
    }
    return -1;
}

// Get the next elevator request
int get_elevator_request()
{
    int min_count = NUM_ELEVATORS;
    int min_elevator = -1;
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        int count = 0;
        for (int j = 0; j < NUM_FLOORS; j++) {
            if (elevators_on_floor[j][i] != 0) {
                count++;
            }
        }
        if (count < min_count) {
            min_count = count;
            min_elevator = i;
        }
    }
    return min_elevator;
}

// Move elevator to requested floor
void move_elevator(int elevator_num)
{
    int direction;
    if (elevator_requests[elevator_num] > current_floor) {
        direction = 1;
    } else {
        direction = -1;
    }
    
    while (current_floor != elevator_requests[elevator_num]) {
        printf("Elevator %d moving to floor %d\n", elevator_num, current_floor+direction);
        current_floor += direction;
        usleep(rand() % 300000);
    }
    
    printf("Elevator %d has arrived at floor %d\n", elevator_num, current_floor);
}