//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* The following defines the number of available movement commands */
#define NUM_COMMANDS 4

/* Enumeration for all available movement commands */
enum movement_command { FORWARD, BACKWARD, LEFT, RIGHT };

/* Enumeration for all available vehicle types */
enum vehicle_type { CAR, TRUCK, TANK };

/* Structure for a single remote control vehicle */
struct rc_vehicle {
    enum vehicle_type type;
    int x_pos;
    int y_pos;
    int health;
};

/* Function to randomly generate a movement command */
enum movement_command generate_command() {
    int random_num = rand() % NUM_COMMANDS;
    return (enum movement_command) random_num;
}

/* Function to update the position of a given vehicle based on a movement command */
void update_position(struct rc_vehicle *vehicle, enum movement_command command) {
    switch(command) {
        case FORWARD:
            vehicle->y_pos++;
            break;
        case BACKWARD:
            vehicle->y_pos--;
            break;
        case LEFT:
            vehicle->x_pos--;
            break;
        case RIGHT:
            vehicle->x_pos++;
            break;
    }
}

/* Function to initialize a single remote control vehicle */
void initialize_vehicle(struct rc_vehicle *vehicle) {
    /* Randomly choose vehicle type */
    int random_num = rand() % 3;
    vehicle->type = (enum vehicle_type) random_num;
    
    /* Set starting position */
    vehicle->x_pos = 0;
    vehicle->y_pos = 0;
    
    /* Set starting health */
    vehicle->health = 100;
}

/* Main function to run the simulation */
int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Initialize a new vehicle */
    struct rc_vehicle vehicle;
    initialize_vehicle(&vehicle);
    
    /* Print starting information */
    printf("Starting position: (%d, %d)\n", vehicle.x_pos, vehicle.y_pos);
    printf("Starting health: %d\n", vehicle.health);
    printf("Vehicle type: %d\n", vehicle.type);
    
    /* Run simulation loop */
    for(int i = 1; i <= 10; i++) {
        /* Generate a random movement command */
        enum movement_command command = generate_command();
        
        /* Update position based on the movement command */
        update_position(&vehicle, command);
        
        /* Print updated information */
        printf("Movement command #%d: %d\n", i, command);
        printf("Updated position: (%d, %d)\n", vehicle.x_pos, vehicle.y_pos);
    }
    
    /* Exit the program */
    return 0;
}