//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 10 // Maximum number of floors in the building
#define MAX_PEOPLE 50 // Maximum number of people in the building
#define ELEVATOR_CAPACITY 5 // Capacity of the elevator

// Define the direction of the elevator
typedef enum {
    UP,
    DOWN,
    IDLE
} dir_t;

// Define the state of the elevator
typedef struct {
    int current_floor; // The current floor the elevator is on
    dir_t direction; // The direction the elevator is moving in
    int occupancy; // The number of people in the elevator
} elevator_t;

// Define the state of each floor in the building
typedef struct {
    pthread_mutex_t lock; // Mutex to make the floor thread-safe
    pthread_cond_t call_elevator; // Condition variable for signaling the elevator
    pthread_cond_t wait_elevator; // Condition variable for waiting for the elevator to arrive
    int waiting; // The number of people waiting on the floor
    int serviced; // The number of people serviced by the elevator on this floor
} floor_t;

// Define the state of each person in the building
typedef struct {
    pthread_t thread_id; // The thread id of the person
    int current_floor; // The current floor the person is on
    int desired_floor; // The floor the person wants to go to
    int in_elevator; // Whether or not the person is in the elevator
} person_t;

elevator_t elevator = {0, IDLE, 0}; // Initialize the elevator state

floor_t floors[MAX_FLOORS]; // Initialize the floor array
person_t people[MAX_PEOPLE]; // Initialize the person array
int num_people = 0; // Keep track of the total number of people in the building

// Function prototypes
void* person_thread(void* arg);
void* elevator_thread(void* arg);
void move_elevator(int destination);
int get_floor(elevator_t *elevator);

int main(int argc, char** argv) {
    // Initialize the mutex and condition variables for each floor
    for (int i = 0; i < MAX_FLOORS; i++) {
        pthread_mutex_init(&floors[i].lock, NULL);
        pthread_cond_init(&floors[i].call_elevator, NULL);
        pthread_cond_init(&floors[i].wait_elevator, NULL);
        floors[i].waiting = 0;
        floors[i].serviced = 0;
    }

    // Initialize the people and start their threads
    for (int i = 0; i < MAX_PEOPLE; i++) {
        people[i].current_floor = rand() % MAX_FLOORS;
        people[i].desired_floor = rand() % MAX_FLOORS;
        if (people[i].current_floor == people[i].desired_floor) {
            people[i].desired_floor = (people[i].current_floor + 1) % MAX_FLOORS;
        }
        people[i].in_elevator = 0;
        pthread_create(&people[i].thread_id, NULL, person_thread, (void*)&people[i]);
        num_people++;
        usleep(5000); // Introduce a small delay between thread creation
    }

    // Start the elevator thread
    pthread_t elevator_id;
    pthread_create(&elevator_id, NULL, elevator_thread, NULL);

    // Wait for all of the threads to complete
    for (int i = 0; i < MAX_PEOPLE; i++) {
        pthread_join(people[i].thread_id, NULL);
    }
    pthread_join(elevator_id, NULL);

    // Output statistics
    printf("All people have been transported:\n");
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("Floor %d serviced %d people\n", i, floors[i].serviced);
    }
}

void* person_thread(void* arg) {
    person_t* person = (person_t*)arg;

    // Wait for the elevator to arrive
    pthread_mutex_lock(&floors[person->current_floor].lock);
    floors[person->current_floor].waiting++;
    while (!person->in_elevator) {
        pthread_cond_signal(&floors[person->current_floor].call_elevator);
        printf("Person on floor %d waiting for elevator\n", person->current_floor);
        pthread_cond_wait(&floors[person->current_floor].wait_elevator, &floors[person->current_floor].lock);
    }
    floors[person->current_floor].waiting--;
    pthread_mutex_unlock(&floors[person->current_floor].lock);

    // Ride the elevator to the desired floor
    printf("Person on floor %d getting in elevator going to floor %d\n", person->current_floor, person->desired_floor);
    while (get_floor(&elevator) != person->desired_floor) {
        person->in_elevator = 1;
    }

    // Exit the elevator and signal the floor that the person has been serviced
    pthread_mutex_lock(&floors[person->desired_floor].lock);
    printf("Person on floor %d getting out at floor %d\n", person->current_floor, person->desired_floor);
    floors[person->desired_floor].serviced++;
    pthread_mutex_unlock(&floors[person->desired_floor].lock);

    return NULL;
}

void* elevator_thread(void* arg) {
    // The elevator moves between floors infinitely
    while (1) {
        switch (elevator.direction) {
            case UP:
                move_elevator(elevator.current_floor + 1);
                break;

            case DOWN:
                move_elevator(elevator.current_floor - 1);
                break;

            case IDLE:
                // If the elevator is idle, wait for a call
                for (int i = 0; i < MAX_FLOORS; i++) {
                    pthread_mutex_lock(&floors[i].lock);
                    if (floors[i].waiting > 0) {
                        move_elevator(i);
                        break;
                    }
                    pthread_mutex_unlock(&floors[i].lock);
                }
                break;
        }
    }

    return NULL;
}

void move_elevator(int destination) {
    // Move the elevator to the desired floor
    printf("Elevator moving from floor %d to floor %d\n", elevator.current_floor, destination);
    while (elevator.current_floor != destination) {
        usleep(200000); // Introduce a small delay between floor changes
        elevator.current_floor += (destination > elevator.current_floor) ? 1 : -1;
        printf("Elevator now on floor %d\n", elevator.current_floor);

        // Service people on the current floor
        if (elevator.current_floor == get_floor(&elevator)) {
            printf("Elevator opening doors on floor %d\n", elevator.current_floor);
            pthread_mutex_lock(&floors[elevator.current_floor].lock);
            while (floors[elevator.current_floor].waiting > 0 && elevator.occupancy < ELEVATOR_CAPACITY) {
                pthread_cond_signal(&floors[elevator.current_floor].wait_elevator);
                elevator.occupancy++;
            }
            pthread_mutex_unlock(&floors[elevator.current_floor].lock);
        }
    }

    // Update the elevator direction
    int next_floor = get_floor(&elevator);
    if (next_floor > elevator.current_floor) {
        elevator.direction = UP;
    } else if (next_floor < elevator.current_floor) {
        elevator.direction = DOWN;
    } else {
        elevator.direction = IDLE;
    }
}

int get_floor(elevator_t *elevator) {
    // Determine the closest floor with waiting people
    int current_floor = elevator->current_floor;
    int closest_floor = -1;
    int distance = MAX_FLOORS + 1;
    for (int i = 0; i < MAX_FLOORS; i++) {
        int d = abs(current_floor - i);
        if (d < distance && floors[i].waiting > 0) {
            closest_floor = i;
            distance = d;
        }
    }
    return closest_floor;
}