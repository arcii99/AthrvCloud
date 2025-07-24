//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ELEVATOR_MAX_FLOOR 10
#define ELEVATOR_NUM_BUTTONS 2

typedef struct {
    int current_floor;
    int destination_floor;
    bool is_moving;
} elevator_state_t;

typedef struct {
    int current_floor;
    bool is_pressed;
} button_state_t;

typedef struct {
    int floor;
    bool is_lit;
} floor_indicator_t;

int main(void) {
    elevator_state_t elevator_state = {0, 0, false};
    button_state_t button_states[ELEVATOR_NUM_BUTTONS] = {{1, false}, {ELEVATOR_MAX_FLOOR, false}};
    floor_indicator_t floor_indicators[ELEVATOR_MAX_FLOOR];
    int num_passengers = 0;
    
    // initialize floor indicators
    for (int i = 0; i < ELEVATOR_MAX_FLOOR; i++) {
        floor_indicators[i].floor = i + 1;
        floor_indicators[i].is_lit = false;
    }
    
    srand(time(NULL));
    
    while (true) {
        printf("Current floor: %d\n", elevator_state.current_floor);
        
        // check if any floor buttons have been pressed
        for (int i = 0; i < ELEVATOR_NUM_BUTTONS; i++) {
            if (button_states[i].is_pressed) {
                elevator_state.destination_floor = button_states[i].current_floor;
                break;
            }
        }
        
        // check if elevator has arrived at destination floor
        if (elevator_state.destination_floor != elevator_state.current_floor && !elevator_state.is_moving) {
            elevator_state.is_moving = true;
        } else if (elevator_state.destination_floor == elevator_state.current_floor && elevator_state.is_moving) {
            elevator_state.is_moving = false;
            num_passengers = 0;
            for (int i = 0; i < ELEVATOR_NUM_BUTTONS; i++) {
                button_states[i].is_pressed = false;
            }
        }
        
        // update elevator floor
        if (elevator_state.is_moving) {
            if (elevator_state.destination_floor > elevator_state.current_floor) {
                elevator_state.current_floor++;
            } else {
                elevator_state.current_floor--;
            }
            floor_indicators[elevator_state.current_floor-1].is_lit = true;
        }
        
        // update passenger count
        if (elevator_state.is_moving && rand() % 2 == 0) {
            num_passengers += rand() % 3;
        }
        
        // print floor indicators
        printf("Floor indicators: ");
        for (int i = 0; i < ELEVATOR_MAX_FLOOR; i++) {
            printf("%d[%c] ", floor_indicators[i].floor, floor_indicators[i].is_lit ? '*' : ' ');
        }
        printf("\n");
        
        // print elevator state and passenger count
        printf("Elevator state: %s, Destination floor: %d, Num passengers: %d\n", 
               elevator_state.is_moving ? "moving" : "stopped", elevator_state.destination_floor, num_passengers);
        
        // randomly press floor buttons
        if (!elevator_state.is_moving && rand() % 5 == 0) {
            int random_floor = 0;
            do {
                random_floor = rand() % ELEVATOR_MAX_FLOOR + 1;
            } while (random_floor == elevator_state.current_floor);
            button_states[rand() % ELEVATOR_NUM_BUTTONS].is_pressed = true;
            printf("Pressed button for floor %d\n", random_floor);
        }
        
        printf("\n");
    }
    
    return 0;
}