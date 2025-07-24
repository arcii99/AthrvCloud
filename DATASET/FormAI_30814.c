//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPEED_MULTIPLIER 10.0 // speed multiplier for simulated vehicle
#define DEFAULT_SPEED 0 // default speed for simulated vehicle
#define DEFAULT_DIRECTION "north" // default direction for simulated vehicle
#define MAX_SPEED 100 // maximum speed for simulated vehicle
#define MAX_DIRECTION_LENGTH 10 // maximum length of direction string

int main() {
    // initialize variables for vehicle speed and direction
    float speed = DEFAULT_SPEED;
    char direction[MAX_DIRECTION_LENGTH + 1]; // add 1 for null-terminating character
    strncpy(direction, DEFAULT_DIRECTION, MAX_DIRECTION_LENGTH); // initialize direction to default value
    direction[MAX_DIRECTION_LENGTH] = '\0'; // make sure direction string is null-terminated
    
    // seed random number generator
    srand(time(NULL));
    
    // simulate remote control vehicle maneuvers based on user input
    while (1) { // terminate program with Ctrl+C
        printf("Enter a command (a for accelerate, d for decelerate, l for turn left, r for turn right): ");
        char command = getchar();
        getchar(); // discard newline character
        
        switch (command) {
            case 'a':
                // simulate acceleration based on random factor
                float acceleration = (rand() % 5 + 1) / SPEED_MULTIPLIER;
                printf("Accelerating by %.2f units...\n", acceleration);
                
                // increase speed, but cap at maximum speed
                speed += acceleration;
                if (speed > MAX_SPEED) {
                    speed = MAX_SPEED;
                }
                
                // display updated speed and direction
                printf("Speed: %.1f units, Direction: %s\n", speed, direction);
                break;
            case 'd':
                // simulate deceleration based on random factor
                float deceleration = (rand() % 5 + 1) / SPEED_MULTIPLIER;
                printf("Decelerating by %.2f units...\n", deceleration);
                
                // decrease speed, but cap at zero
                speed -= deceleration;
                if (speed < 0) {
                    speed = 0;
                }
                
                // display updated speed and direction
                printf("Speed: %.1f units, Direction: %s\n", speed, direction);
                break;
            case 'l':
                // simulate turning left
                printf("Turning left...\n");
                strncpy(direction, "west", MAX_DIRECTION_LENGTH);
                printf("Speed: %.1f units, Direction: %s\n", speed, direction);
                break;
            case 'r':
                // simulate turning right
                printf("Turning right...\n");
                strncpy(direction, "east", MAX_DIRECTION_LENGTH);
                printf("Speed: %.1f units, Direction: %s\n", speed, direction);
                break;
            default:
                // ignore invalid commands
                printf("Invalid command.\n");
        }
    }
    
    return 0;
}