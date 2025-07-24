//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 15
#define MAX_ELEVATORS 4

pthread_mutex_t mutex, mutex_elev[MAX_ELEVATORS];
pthread_cond_t cond_up[MAX_FLOORS], cond_down[MAX_FLOORS], cond_elev[MAX_ELEVATORS];

int n = MAX_FLOORS;    // Total number of floors
int m = MAX_ELEVATORS; // Total number of elevators

// enum for the states of an elevator
typedef enum {
    IDLE,
    UP,
    DOWN
} ElevatorState;

// struct representing a floor
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond_up, cond_down;
    bool up_pressed, down_pressed;
} Floor;

Floor floors[MAX_FLOORS];

// struct representing an elevator
typedef struct {
    pthread_t tid;
    ElevatorState state;
    int current_floor;
    bool up_destinations[MAX_FLOORS], down_destinations[MAX_FLOORS];
} Elevator;

Elevator elevators[MAX_ELEVATORS];

// function to simulate elevator movement
void *elevator(void *e) {
    Elevator *elev = (Elevator *) e;
    while (true) {
        usleep(1000000); // wait 1 second to simulate movement
        pthread_mutex_lock(&mutex_elev[elev->current_floor]);
        elev->up_destinations[elev->current_floor] = false;
        elev->down_destinations[elev->current_floor] = false;
        if (elev->state == UP) {
            elev->current_floor++;
            if (elev->current_floor == n-1) {
                elev->state = DOWN;
            }
        } else if (elev->state == DOWN) {
            elev->current_floor--;
            if (elev->current_floor == 0) {
                elev->state = UP;
            }
        } else {
            // if idle, check if there are any pending requests
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (elev->up_destinations[i] || elev->down_destinations[i]) {
                    found = true;
                    if (i > elev->current_floor) {
                        elev->state = UP;
                        break;
                    } else if (i < elev->current_floor) {
                        elev->state = DOWN;
                        break;
                    }
                }
            }
            if (!found) {
                pthread_cond_wait(&cond_elev[elev-elevators], &mutex_elev[elev->current_floor]);
                continue;
            }
        }
        printf("Elevator %ld arrived at floor %d\n", elev-elevators, elev->current_floor);
        pthread_cond_signal(&cond_up[elev->current_floor]);
        pthread_cond_signal(&cond_down[elev->current_floor]);
        for (int i = 0; i < n; i++) {
            if (elev->up_destinations[i] || elev->down_destinations[i]) {
                pthread_cond_signal(&cond_elev[elev-elevators]);
                break;
            }
        }
        pthread_mutex_unlock(&mutex_elev[elev->current_floor]);
    }
}

// function to simulate person presses up or down button
void press_button(int floor, bool up) {
    Floor *f = &floors[floor];
    pthread_mutex_lock(&mutex);
    if (up) {
        f->up_pressed = true;
        pthread_cond_signal(&f->cond_up);
    } else {
        f->down_pressed = true;
        pthread_cond_signal(&f->cond_down);
    }
    pthread_mutex_unlock(&mutex);
}

// function to simulate person entering elevator
void enter_elevator(Elevator *elev, int floor, bool up) {
    pthread_mutex_lock(&mutex_elev[floor]);
    if (up) {
        elev->up_destinations[floor] = true;
        pthread_cond_signal(&cond_elev[elev-elevators]);
    } else {
        elev->down_destinations[floor] = true;
        pthread_cond_signal(&cond_elev[elev-elevators]);
    }
    pthread_mutex_unlock(&mutex_elev[floor]);
}

// function to simulate person exiting the elevator
void exit_elevator(Elevator *elev, int floor) {
    pthread_mutex_lock(&mutex_elev[floor]);
    if (elev->up_destinations[floor] || elev->down_destinations[floor]) {
        elev->up_destinations[floor] = false;
        elev->down_destinations[floor] = false;
    }
    pthread_mutex_unlock(&mutex_elev[floor]);
}

int main() {
    // initialize mutexes and conditions
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < n; i++) {
        pthread_mutex_init(&floors[i].mutex, NULL);
        pthread_cond_init(&floors[i].cond_up, NULL);
        pthread_cond_init(&floors[i].cond_down, NULL);
    }
    for (int i = 0; i < m; i++) {
        pthread_mutex_init(&mutex_elev[i], NULL);
        pthread_cond_init(&cond_elev[i], NULL);
    }

    // create elevators
    for (int i = 0; i < m; i++) {
        elevators[i].tid = pthread_self()+i+1;
        elevators[i].state = IDLE;
        elevators[i].current_floor = 0;
        for (int j = 0; j < n; j++) {
            elevators[i].up_destinations[j] = false;
            elevators[i].down_destinations[j] = false;
        }
        pthread_create(&elevators[i].tid, NULL, elevator, (void *) &elevators[i]);
    }

    // simulate people pressing buttons
    press_button(3, true);
    press_button(2, false);
    press_button(5, true);
    press_button(0, false);
    press_button(12, true);
    press_button(7, false);

    // simulate people entering/exiting the elevator
    enter_elevator(&elevators[0], 3, true);
    enter_elevator(&elevators[0], 5, true);
    exit_elevator(&elevators[0], 3);
    enter_elevator(&elevators[0], 7, false);
    enter_elevator(&elevators[0], 2, false);
    enter_elevator(&elevators[1], 12, true);

    // cleanup
    for (int i = 0; i < m; i++) {
        pthread_cancel(elevators[i].tid);
    }
    for (int i = 0; i < n; i++) {
        pthread_mutex_destroy(&floors[i].mutex);
        pthread_cond_destroy(&floors[i].cond_up);
        pthread_cond_destroy(&floors[i].cond_down);
    }
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < m; i++) {
        pthread_mutex_destroy(&mutex_elev[i]);
        pthread_cond_destroy(&cond_elev[i]);
    }
    return 0;
}