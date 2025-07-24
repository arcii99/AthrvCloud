//FormAI DATASET v1.0 Category: Smart home automation ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define LIGHT_1 1
#define LIGHT_2 2
#define AC 3
#define SECURITY_SYSTEM 4

typedef enum {
    OFF,
    ON
} switch_state_t;

typedef struct {
    switch_state_t light_1;
    switch_state_t light_2;
    switch_state_t ac;
    switch_state_t security_system;
} house_state_t;

bool motion_detected() {
    // returns true if motion is detected, false otherwise
}

void change_light_state(switch_state_t* state) {
    *state = (*state == ON) ? OFF : ON;
}

void change_ac_state(switch_state_t* state) {
    *state = (*state == ON) ? OFF : ON;
}

void change_security_state(switch_state_t* state) {
    *state = (*state == ON) ? OFF : ON;
}

void update_house_state(house_state_t* state) {
    if (motion_detected()) {
        change_light_state(&(state->light_1));
        change_light_state(&(state->light_2));
        change_ac_state(&(state->ac));
        change_security_state(&(state->security_system));
    }
}

int main() {
    house_state_t state = {OFF, OFF, OFF, OFF};

    // simulate motion detection every 10 seconds
    while (true) {
        update_house_state(&state);
        printf("Light 1: %s\n", (state.light_1 == ON) ? "ON" : "OFF");
        printf("Light 2: %s\n", (state.light_2 == ON) ? "ON" : "OFF");
        printf("AC: %s\n", (state.ac == ON) ? "ON" : "OFF");
        printf("Security System: %s\n", (state.security_system == ON) ? "ARMED" : "DISARMED");
        sleep(10);
    }

    return 0;
}