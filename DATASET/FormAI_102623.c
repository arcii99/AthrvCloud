//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Constants */
#define MAX_FLOORS 20
#define MAX_ELEVATORS 5

/* Struct for Elevator */
typedef struct {
    int id;
    int current_floor;
    int num_people;
} elevator;

/* Struct for Floor */
typedef struct {
    int floor_num;
    int num_people_waiting;
    int people_waiting[MAX_ELEVATORS];
} floor;

/* Global Variables */
elevator elevators[MAX_ELEVATORS];
floor floors[MAX_FLOORS];

/* Function Prototypes */
void initialize_elevator_system(int num_elevators, int num_floors);
void simulate_elevator_system();
void print_elevator_system();
void elevator_move(int elevator_id);
void elevator_open_door(int elevator_id);
void elevator_close_door(int elevator_id);
void elevator_drop_off_people(int elevator_id);
void elevator_pick_up_people(int elevator_id);
int find_closest_elevator(int floor_num);
int find_elevator_with_space();
void move_elevator_to_floor(int elevator_id, int floor_num);
void person_arrives_at_floor(int floor_num, int num_people);

/* Main Function */
int main() {
    int num_elevators = 3;
    int num_floors = 10;
    
    initialize_elevator_system(num_elevators, num_floors);
    simulate_elevator_system();
    
    return 0;
}

/* Function Definitions */

// Initializes the elevator system
void initialize_elevator_system(int num_elevators, int num_floors) {
    printf("Initializing Elevator System...\n");
    
    // Initialize elevators
    for(int i = 0; i < num_elevators; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = 0;
        elevators[i].num_people = 0;
    }
    
    // Initialize floors
    for(int i = 0; i < num_floors; i++) {
        floors[i].floor_num = i;
        floors[i].num_people_waiting = 0;
        
        for(int j = 0; j < num_elevators; j++) {
            floors[i].people_waiting[j] = 0;
        }
    }
    
    printf("Initialization Complete!\n");
}

// Simulates the elevator system
void simulate_elevator_system() {
    bool done = false;
    
    while(!done) {
        // Print current status of elevator system
        print_elevator_system();
        
        // Move each elevator to the closest floor with people waiting
        for(int i = 0; i < MAX_ELEVATORS; i++) {
            elevator_move(i);
        }
        
        // If any elevator is at a floor with people waiting, open the door and pick them up
        for(int i = 0; i < MAX_ELEVATORS; i++) {
            if(floors[elevators[i].current_floor].num_people_waiting > 0) {
                elevator_open_door(i);
                elevator_pick_up_people(i);
            }
        }
        
        // If any elevator is at capacity, drop off the people at their desired floor
        for(int i = 0; i < MAX_ELEVATORS; i++) {
            if(elevators[i].num_people > 0) {
                elevator_drop_off_people(i);
            }
        }
        
        // If all people have reached their desired floor, end simulation
        done = true;
        for(int i = 0; i < MAX_FLOORS; i++) {
            if(floors[i].num_people_waiting > 0) {
                done = false;
                break;
            }
        }
    }
}

// Prints the current status of the elevator system
void print_elevator_system() {
    printf("\nElevator System Status:\n");
    
    // Print current floor of each elevator and number of people on board
    for(int i = 0; i < MAX_ELEVATORS; i++) {
        printf("Elevator %d | Current Floor: %d | Num People: %d\n", elevators[i].id, elevators[i].current_floor, elevators[i].num_people);
    }
    
    // Print number of people waiting on each floor for each elevator
    for(int i = 0; i < MAX_FLOORS; i++) {
        printf("Floor %d | Num People Waiting: %d\n", floors[i].floor_num, floors[i].num_people_waiting);
        
        for(int j = 0; j < MAX_ELEVATORS; j++) {
            printf("\tElevator %d | Num People: %d\n", j + 1, floors[i].people_waiting[j]);
        }
    }
}

// Moves the elevator to the closest floor with people waiting
void elevator_move(int elevator_id) {
    int closest_floor = -1;
    int dist = MAX_FLOORS + 1;
    
    // Find closest floor with people waiting
    for(int i = 0; i < MAX_FLOORS; i++) {
        if(floors[i].num_people_waiting > 0) {
            int curr_dist = abs(elevators[elevator_id].current_floor - i);
            
            if(curr_dist < dist) {
                closest_floor = i;
                dist = curr_dist;
            }
        }
    }
    
    // Move elevator to closest floor
    if(closest_floor != -1) {
        move_elevator_to_floor(elevator_id, closest_floor);
    }
}

// Opens the doors of the elevator to pick up people
void elevator_open_door(int elevator_id) {
    printf("Elevator %d opens door on Floor %d\n", elevators[elevator_id].id, elevators[elevator_id].current_floor);
    elevator_close_door(elevator_id);
}

// Closes the doors of the elevator after picking up or dropping off people
void elevator_close_door(int elevator_id) {
    printf("Elevator %d closes door\n", elevators[elevator_id].id);
}

// Drops off people at their desired floor
void elevator_drop_off_people(int elevator_id) {
    for(int i = 0; i < elevators[elevator_id].num_people; i++) {
        if(elevators[elevator_id].current_floor == floors[elevators[elevator_id].num_people].floor_num) {
            printf("Elevator %d drops off person at Floor %d\n", elevators[elevator_id].id, floors[elevators[elevator_id].num_people].floor_num);
            
            // Remove person from elevator
            elevators[elevator_id].num_people--;
        }
    }
}

// Picks up people waiting for the elevator
void elevator_pick_up_people(int elevator_id) {
    int num_picked_up = 0;
    
    for(int i = 0; i < MAX_ELEVATORS; i++) {
        if(floors[elevators[elevator_id].current_floor].people_waiting[elevator_id] > 0 && elevators[elevator_id].num_people < MAX_ELEVATORS) {
            printf("Elevator %d picks up person on Floor %d\n", elevators[elevator_id].id, elevators[elevator_id].current_floor);
            
            // Remove person from floor
            floors[elevators[elevator_id].current_floor].people_waiting[elevator_id]--;
            floors[elevators[elevator_id].current_floor].num_people_waiting--;
            
            // Add person to elevator
            elevators[elevator_id].num_people++;
            num_picked_up++;
        }
    }
    
    printf("Elevator %d picks up %d people\n", elevators[elevator_id].id, num_picked_up);
    elevator_close_door(elevator_id);
}

// Finds the elevator closest to the given floor that has space
int find_closest_elevator(int floor_num) {
    int closest_elevator = -1;
    int dist = MAX_FLOORS + 1;
    
    // Check each elevator for space and proximity
    for(int i = 0; i < MAX_ELEVATORS; i++) {
        if(elevators[i].num_people < MAX_ELEVATORS) {
            int curr_dist = abs(elevators[i].current_floor - floor_num);
            
            if(curr_dist < dist) {
                closest_elevator = i;
                dist = curr_dist;
            }
        }
    }
    
    return closest_elevator;
}

// Finds the first elevator with space
int find_elevator_with_space() {
    for(int i = 0; i < MAX_ELEVATORS; i++) {
        if(elevators[i].num_people < MAX_ELEVATORS) {
            return i;
        }
    }
    
    return -1;
}

// Moves the elevator to the given floor
void move_elevator_to_floor(int elevator_id, int floor_num) {
    printf("Elevator %d moves from Floor %d to Floor %d\n", elevators[elevator_id].id, elevators[elevator_id].current_floor, floor_num);
    elevators[elevator_id].current_floor = floor_num;
} 

// Adds people to the floor who are waiting for the elevator
void person_arrives_at_floor(int floor_num, int num_people) {
    printf("%d people arrive at Floor %d\n", num_people, floor_num);
    
    for(int i = 0; i < num_people; i++) {
        int elevator_id = find_closest_elevator(floor_num);
        
        if(elevator_id == -1) {
            printf("No elevators available for person waiting on Floor %d\n", floor_num);
            continue;
        }
        
        floors[floor_num].people_waiting[elevator_id]++;
        floors[floor_num].num_people_waiting++;
    }
}