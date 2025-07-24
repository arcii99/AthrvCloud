//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10 /* number of floors */
#define ELEVATORS 2 /* number of elevators */

/* define the direction of elevator movement */
#define UP 1
#define DOWN -1

/* define the status of elevator */
#define IDLE 1
#define BUSY 0

/* function prototypes */
int get_random(int min, int max);
void move_elevator(int id);
void print_floors(void);
void operate_elevator(void);

/* global variables */
int elevator_status[ELEVATORS];
int elevator_floor[ELEVATORS];
int elevator_direction[ELEVATORS];
int passenger_dest[FLOORS];
int passenger_waiting[FLOORS] = {0};

/* main function */
int main(void)
{
    int i;

    srand(time(NULL));

    /* randomly set passenger destinations */
    for (i = 0; i < FLOORS; i++) {
        passenger_dest[i] = get_random(0, FLOORS);
    }

    /* initialize elevator statuses and floors */
    for (i = 0; i < ELEVATORS; i++) {
        elevator_status[i] = IDLE;
        elevator_floor[i] = 0;
        elevator_direction[i] = UP;
    }

    /* main loop */
    while (1) {
        printf("\n");
        print_floors(); /* display the status of floors */

        operate_elevator(); /* operate elevators */

        /* wait for some time before processing next iteration */
        usleep(500000);
    }

    return 0;
}

/* function to get a random number between min and max */
int get_random(int min, int max)
{
    return (rand() % (max - min)) + min;
}

/* function to move the elevator with the specified id */
void move_elevator(int id)
{
    int i, j;

    /* first check if the elevator is at the top or bottom floor */
    if (elevator_floor[id] == 0) {
        elevator_direction[id] = UP;
    } else if (elevator_floor[id] == FLOORS - 1) {
        elevator_direction[id] = DOWN;
    }

    /* move the elevator */
    elevator_floor[id] += elevator_direction[id];

    /* check if there are any passengers in the elevator */
    for (i = 0; i < FLOORS; i++) {
        if (passenger_waiting[i] == 0) continue; /* no passengers waiting on this floor */
        if (elevator_floor[id] != i) continue; /* elevator is not at this floor */
        elevator_status[id] = BUSY; /* change elevator status to BUSY */
        elevator_direction[id] = passenger_dest[i] > i ? UP : DOWN; /* set elevator direction to passenger destination */
        passenger_waiting[i] = 0; /* clear the waiting flag */
        /* search for another passenger in the same direction */
        for (j = 0; j < FLOORS; j++) {
            if (elevator_direction[id] == UP && passenger_waiting[j] && j > i) {
                passenger_waiting[j] = 0; /* clear the waiting flag */
                passenger_dest[j] = get_random(j, FLOORS); /* randomly set passenger destination for the next destination */
                break;
            } else if (elevator_direction[id] == DOWN && passenger_waiting[j] && j < i) {
                passenger_waiting[j] = 0; /* clear the waiting flag */
                passenger_dest[j] = get_random(0, j + 1); /* randomly set passenger destination for the next destination */
                break;
            }
        }
        break;
    }

    /* change elevator status to IDLE if there are no passengers */
    if (elevator_status[id] == BUSY && !passenger_waiting[elevator_floor[id]]) {
        elevator_status[id] = IDLE;
    }
}

/* function to display the status of floors */
void print_floors(void)
{
    int i, j;

    printf(" Passengers |");

    for (i = 0; i < FLOORS; i++) {
        printf(" %d |", passenger_waiting[i]);
    }

    printf("\n");

    printf(" Destinations |");

    for (i = 0; i < FLOORS; i++) {
        printf(" %d |", passenger_dest[i]);
    }

    printf("\n");

    printf(" Elevator status |");

    for (i = 0; i < ELEVATORS; i++) {
        printf(" %s |", elevator_status[i] == IDLE ? "IDLE" : "BUSY");
    }

    printf("\n");

    printf(" Elevator position |");

    for (i = 0; i < ELEVATORS; i++) {
        printf(" %d |", elevator_floor[i]);
    }

    printf("\n");
}

/* function to operate elevators */
void operate_elevator(void)
{
    int i;

    for (i = 0; i < ELEVATORS; i++) {
        if (elevator_status[i] == IDLE) {
            /* move the elevator in the opposite direction if there are no passengers */
            elevator_direction[i] = elevator_direction[i] == UP ? DOWN : UP;
            move_elevator(i);
        } else {
            move_elevator(i);
        }
    }
}