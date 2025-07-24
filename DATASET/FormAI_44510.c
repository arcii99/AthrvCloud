//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: configurable
/* Configurable Traffic Light Controller */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Preprocessor Constants */
#define MAX_STATES 5
#define MAX_TRANSITIONS 6

/* State Enum */
typedef enum {
    RED,
    YELLOW,
    GREEN,
    YELLOW_FLASH,
    OFF
} State;

/* Transition Enum */
typedef enum {
    TIMER_EXPIRE,
    BUTTON_PRESS,
    REMOTE_SIGNAL,
    POWER_FAILURE,
    SERVICE_CALL,
    NO_EVENT
} Transition;

/* State Machine Structure */
typedef struct {
    State current_state;
    Transition transitions[MAX_TRANSITIONS];
    State next_states[MAX_TRANSITIONS];
} StateMachine;

/* Function Declarations */
void run_traffic_light_controller(StateMachine* sm);

/* Main Function */
int main(void) {

    /* Configurable States */
    StateMachine traffic_light = {
        .current_state = RED,
        .transitions = {TIMER_EXPIRE, BUTTON_PRESS, REMOTE_SIGNAL, POWER_FAILURE, SERVICE_CALL, NO_EVENT},
        .next_states = {YELLOW, RED, GREEN, OFF, YELLOW_FLASH, RED}
    };

    /* Run the traffic light controller */
    run_traffic_light_controller(&traffic_light);

    return 0;
}

/* Function Definitions */

/* Simulate a timer and return true when it expires */
bool timer_expired(int time_left) {
    printf("Time Left: %d ", time_left);
    return (--time_left == 0);
}

/* Simulate a button press and return true or false depending on the state of the button */
bool button_pressed(bool button_state) {
    printf("Button State: %d ", button_state);
    return !button_state;
}

/* Simulate a remote signal and return true or false depending on the signal strength */
bool remote_signal_received(int signal_strength) {
    printf("Signal Strength: %d ", signal_strength);
    return (signal_strength >= 50);
}

/* Run the traffic light controller */
void run_traffic_light_controller(StateMachine* sm) {
    printf("\nStarting Traffic Light Controller...\n");

    while (sm->current_state != OFF) {

        /* Print Current State */
        char state_str[10];
        switch (sm->current_state) {
            case RED:
                strcpy(state_str, "Red");
                break;
            case YELLOW:
                strcpy(state_str, "Yellow");
                break;
            case GREEN:
                strcpy(state_str, "Green");
                break;
            case YELLOW_FLASH:
                strcpy(state_str, "Yellow Flash");
                break;
            case OFF:
                strcpy(state_str, "Off");
                break;
            default:
                break;
        }
        printf("Current State: %s\n", state_str);

        /* Check for Transitions */
        int i;
        for (i = 0; i < MAX_TRANSITIONS; ++i) {
            bool result = false;
            switch(sm->transitions[i]) {
                case TIMER_EXPIRE:
                    result = timer_expired(10);
                    break;
                case BUTTON_PRESS:
                    result = button_pressed(true);
                    break;
                case REMOTE_SIGNAL:
                    result = remote_signal_received(70);
                    break;
                case POWER_FAILURE:
                    result = true;
                    break;
                case SERVICE_CALL:
                    result = false;
                    break;
                default:
                    result = false;
                    break;
            }

            if (result) {
                printf("Transition: %d\n", sm->transitions[i]);
                sm->current_state = sm->next_states[i];
                break;
            }
        }

        /* Pause for 1 Second */
        printf("------------------------\n");
    }

    printf("Shutting Down Traffic Light Controller...\n");
}