//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the states of the traffic light
typedef enum {GREEN, YELLOW, RED} TrafficLightState;

// Define the directions of the traffic light
typedef enum {NORTH_SOUTH, EAST_WEST} TrafficLightDirection;

// Define the traffic light controller struct
typedef struct {
    TrafficLightState north_south_state;
    TrafficLightState east_west_state;
    bool emergency_mode;
} TrafficLightController;

// Function to get random boolean value
bool get_random_bool() {
    return rand() % 2 == 0;
}

// Function to check emergency mode
bool is_emergency_mode(TrafficLightDirection direction) {
    if (direction == NORTH_SOUTH) {
        return get_random_bool();
    } else {
        return false;
    }
}

// Function to get the next state of the traffic light
TrafficLightState get_next_state(TrafficLightState current_state, bool emergency_mode) {
    if (emergency_mode) {
        return YELLOW;
    } else {
        switch (current_state) {
            case GREEN:
                return YELLOW;
            case YELLOW:
                return RED;
            case RED:
                return GREEN;
            default:
                return current_state;
        }
    }
}

// Function to update the traffic light
void update_traffic_light(TrafficLightController *controller) {
    // Update north-south traffic light
    controller->north_south_state = get_next_state(controller->north_south_state, controller->emergency_mode);
    
    // Update east-west traffic light
    controller->east_west_state = get_next_state(controller->east_west_state, controller->emergency_mode);
}

// Function to print the current state of the traffic light
void print_traffic_light_state(TrafficLightState state) {
    switch (state) {
        case GREEN:
            printf("Green\n");
            break;
        case YELLOW:
            printf("Yellow\n");
            break;
        case RED:
            printf("Red\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

// Function to print the current state of the traffic light controller
void print_traffic_light_controller_state(TrafficLightController controller) {
    printf("North-South: ");
    print_traffic_light_state(controller.north_south_state);
    
    printf("East-West: ");
    print_traffic_light_state(controller.east_west_state);
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize traffic light controller
    TrafficLightController controller = {
        .north_south_state = GREEN,
        .east_west_state = RED,
        .emergency_mode = false
    };
    
    // Main loop
    while (true) {
        // Check emergency mode
        controller.emergency_mode = is_emergency_mode(NORTH_SOUTH);
        
        // Update the traffic light
        update_traffic_light(&controller);
        
        // Print the current state of the traffic light controller
        printf("Traffic Light Controller State:\n");
        print_traffic_light_controller_state(controller);
        
        // Wait for 1 second
        printf("=================================\n");
        printf("Press Ctrl+C to terminate\n");
        sleep(1);
    }
    
    return 0;
}