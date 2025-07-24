//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10 // Total number of floors in building
#define MAX_ELEVATORS 3 // Total number of elevators in building

pthread_mutex_t elevator_mutex = PTHREAD_MUTEX_INITIALIZER;

struct Elevator {
    int current_floor; // Current floor elevator is on
    bool is_moving; // Flag to indicate if elevator is moving
    int dest_floor; // Floor where elevator is going
    bool is_full; // Flag to indicate if elevator is full
};

struct Person {
    int current_floor; // Floor where the person is waiting
    int dest_floor; // Floor where the person is going
};

struct Building {
    struct Elevator elevators[MAX_ELEVATORS];
    pthread_t elevator_threads[MAX_ELEVATORS];
    struct Person waiting[MAX_FLOORS][MAX_FLOORS]; // Array to store persons waiting on each floor
};

struct Building building; // Global variable representing the building

// Function to initialize the elevators
void init_elevators() {
    for (int i=0; i<MAX_ELEVATORS; i++) {
        building.elevators[i].current_floor = 0;
        building.elevators[i].is_moving = false;
        building.elevators[i].dest_floor = -1;
        building.elevators[i].is_full = false;
    }
}

// Function to add a person to a floor
void add_person(struct Person p) {
    building.waiting[p.current_floor][p.dest_floor] = p;
}

// Function to remove a person from a floor
void remove_person(int floor, int dest_floor) {
    building.waiting[floor][dest_floor].current_floor = -1;
    building.waiting[floor][dest_floor].dest_floor = -1;
}

// Function to handle elevator movement
void move_elevator(int elevator_num) {
    int current_floor = building.elevators[elevator_num].current_floor;
    int dest_floor = building.elevators[elevator_num].dest_floor;
    
    if (current_floor > dest_floor) {
        building.elevators[elevator_num].current_floor -= 1;
        printf("Elevator %d is on floor %d\n", elevator_num, building.elevators[elevator_num].current_floor);
    }
    else if (current_floor < dest_floor) {
        building.elevators[elevator_num].current_floor += 1;
        printf("Elevator %d is on floor %d\n", elevator_num, building.elevators[elevator_num].current_floor);
    }
    
    if (building.elevators[elevator_num].current_floor == dest_floor) {
        building.elevators[elevator_num].is_moving = false;
        building.elevators[elevator_num].is_full = false;
        
        // Remove persons from elevator that have reached their destination
        for (int i=0; i<MAX_FLOORS; i++) {
            if (building.elevators[elevator_num].current_floor == i && building.elevators[elevator_num].is_full == true) {
                remove_person(i, dest_floor);
            }
        }
        
        pthread_mutex_unlock(&elevator_mutex);
    }
}

// Function to move elevator to a requested floor
void request_elevator(int elevator_num, int dest_floor) {
    building.elevators[elevator_num].dest_floor = dest_floor;
    building.elevators[elevator_num].is_moving = true;
    building.elevators[elevator_num].is_full = true;
    
    while (building.elevators[elevator_num].is_moving == true) {
        move_elevator(elevator_num);
    }
}

// Function to find the closest elevator to a floor
int find_closest_elevator(int floor) {
    int closest_elevator = -1;
    int distance = MAX_FLOORS;
    
    for (int i=0; i<MAX_ELEVATORS; i++) {
        if (building.elevators[i].is_moving == false && building.elevators[i].is_full == false) {
            int elevator_floor = building.elevators[i].current_floor;
            if (abs(floor - elevator_floor) < distance) {
                closest_elevator = i;
                distance = abs(floor - elevator_floor);
            }
        }
    }
    
    return closest_elevator;
}

// Function to handle a person waiting on a floor
void *person_thread(void *arg) {
    struct Person *p = (struct Person *)arg;
    
    int closest_elevator = find_closest_elevator(p->current_floor);
    
    pthread_mutex_lock(&elevator_mutex);
    request_elevator(closest_elevator, p->dest_floor);
    
    printf("Person going from floor %d to floor %d has entered elevator %d\n", p->current_floor, p->dest_floor, closest_elevator);
}

// Function to handle an elevator moving
void *elevator_thread(void *arg) {
    int *elevator_num = (int *)arg;
    
    while (true) {
        // Check if there are persons waiting on the current floor
        for (int i=0; i<MAX_FLOORS; i++) {
            if (building.waiting[building.elevators[*elevator_num].current_floor][i].current_floor != -1) {
                struct Person p = building.waiting[building.elevators[*elevator_num].current_floor][i];
                pthread_t person_thread_id;
                pthread_create(&person_thread_id, NULL, person_thread, (void *)&p);
                pthread_join(person_thread_id, NULL);
            }
        }
        
        pthread_mutex_lock(&elevator_mutex);
        building.elevators[*elevator_num].is_full = false;
        building.elevators[*elevator_num].is_moving = false;
        
        // Set destination floor as lowest floor where there are persons waiting
        for (int i=0; i<MAX_FLOORS; i++) {
            for (int j=0; j<MAX_FLOORS; j++) {
                if (building.waiting[i][j].dest_floor != -1 && j < building.elevators[*elevator_num].dest_floor) {
                    building.elevators[*elevator_num].dest_floor = j;
                }
            }
        }
        
        if (building.elevators[*elevator_num].dest_floor == -1) {
            building.elevators[*elevator_num].dest_floor = 0;
        }
        
        while (building.elevators[*elevator_num].current_floor != building.elevators[*elevator_num].dest_floor) {
            move_elevator(*elevator_num);
        }
        
        // Drop off persons at the current floor
        for (int i=0; i<MAX_FLOORS; i++) {
            if (building.waiting[building.elevators[*elevator_num].current_floor][i].current_floor != -1) {
                remove_person(building.elevators[*elevator_num].current_floor, i);
            }
        }
    }
}

// Function to initialize the building
void init_building() {
    for (int i=0; i<MAX_FLOORS; i++) {
        for (int j=i+1; j<MAX_FLOORS; j++) {
            struct Person p = {i, j};
            add_person(p);
        }
    }
}

int main() {
    init_elevators();
    init_building();
    
    // Start elevator threads
    for (int i=0; i<MAX_ELEVATORS; i++) {
        pthread_create(&building.elevator_threads[i], NULL, elevator_thread, (void *)&i);
    }
    
    // Join elevator threads
    for (int i=0; i<MAX_ELEVATORS; i++) {
        pthread_join(building.elevator_threads[i], NULL);
    }
    
    return 0;
}