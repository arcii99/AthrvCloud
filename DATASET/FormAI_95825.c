//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Drone commands
enum Command {
    TAKE_OFF, LAND, FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN, ROTATE_LEFT, ROTATE_RIGHT
};

// Drone status
enum Status {
    IDLE, TAKING_OFF, FLYING, LANDING
};

// Drone state
struct State {
    enum Status status;
    int battery;
    int altitude;
    int x;
    int y;
};

// Drone state initialization
struct State init_state() {
    struct State state = { IDLE, 100, 0, 0, 0 };
    return state;
}

// Drone state update
void update_state(struct State* state, enum Command command) {
    switch (command) {
        case TAKE_OFF:
            if (state->status == IDLE) {
                state->status = TAKING_OFF;
                state->battery -= 10;
            }
            break;
        case LAND:
            if (state->status == FLYING) {
                state->status = LANDING;
                state->battery -= 10;
            }
            break;
        case FORWARD:
            if (state->status == FLYING) {
                state->y++;
                state->battery -= 5;
            }
            break;
        case BACKWARD:
            if (state->status == FLYING) {
                state->y--;
                state->battery -= 5;
            }
            break;
        case LEFT:
            if (state->status == FLYING) {
                state->x--;
                state->battery -= 5;
            }
            break;
        case RIGHT:
            if (state->status == FLYING) {
                state->x++;
                state->battery -= 5;
            }
            break;
        case UP:
            if (state->status == FLYING) {
                state->altitude++;
                state->battery -= 5;
            }
            break;
        case DOWN:
            if (state->status == FLYING) {
                state->altitude--;
                state->battery -= 5;
            }
            break;
        case ROTATE_LEFT:
            if (state->status == FLYING) {
                state->battery -= 5;
            }
            break;
        case ROTATE_RIGHT:
            if (state->status == FLYING) {
                state->battery -= 5;
            }
            break;
    }
    if (state->battery <= 0) {
        state->status = IDLE;
    }
}

int main() {
    struct State state = init_state();

    // Drone simulation loop
    while (true) {
        // Check for drone status
        switch (state.status) {
            case IDLE:
                printf("Battery is empty. Connect the charger.\n");
                return 0;
            case TAKING_OFF:
                printf("Drone is taking off...\n");
                state.status = FLYING;
                break;
            case FLYING:
                printf("Drone is at (%d, %d, %d).\n", state.x, state.y, state.altitude);
                break;
            case LANDING:
                printf("Drone is landing...\n");
                state.status = IDLE;
                break;
        }

        // Wait for user input
        printf("Enter a command: ");
        char input[10];
        scanf("%s", input);

        // Parse user input
        enum Command command;
        if (strcmp(input, "takeoff") == 0) {
            command = TAKE_OFF;
        } else if (strcmp(input, "land") == 0) {
            command = LAND;
        } else if (strcmp(input, "forward") == 0) {
            command = FORWARD;
        } else if (strcmp(input, "backward") == 0) {
            command = BACKWARD;
        } else if (strcmp(input, "left") == 0) {
            command = LEFT;
        } else if (strcmp(input, "right") == 0) {
            command = RIGHT;
        } else if (strcmp(input, "up") == 0) {
            command = UP;
        } else if (strcmp(input, "down") == 0) {
            command = DOWN;
        } else if (strcmp(input, "rotateleft") == 0) {
            command = ROTATE_LEFT;
        } else if (strcmp(input, "rotateright") == 0) {
            command = ROTATE_RIGHT;
        } else {
            printf("Invalid command.\n");
            continue;
        }

        // Update drone state
        update_state(&state, command);
    }

    return 0;
}