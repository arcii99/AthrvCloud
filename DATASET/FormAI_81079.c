//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_SPEED 100
#define MIN_SPEED 0
#define TURN_LEFT 'l'
#define TURN_RIGHT 'r'
#define MOVE_FORWARD 'f'
#define MOVE_BACKWARD 'b'

// Function prototypes
void test_flight_controller();
void send_command(char command, int speed);
int validate_speed(int speed);

int main()
{
    // Test the drone flight controller
    test_flight_controller();
    return 0;
}

void test_flight_controller()
{
    // Send some commands to the drone
    send_command(MOVE_FORWARD, 50);
    send_command(TURN_LEFT, 75);
    send_command(MOVE_BACKWARD, 25);
    send_command(TURN_RIGHT, 100);
}

void send_command(char command, int speed)
{
    // Validate the speed input
    speed = validate_speed(speed);
    
    // Print the command and speed
    printf("Command: %c, Speed: %d\n", command, speed);
}

int validate_speed(int speed)
{
    // Ensure speed is within the acceptable range
    if (speed > MAX_SPEED)
    {
        printf("Speed (%d) is too high. Setting speed to maximum (%d).\n", speed, MAX_SPEED);
        speed = MAX_SPEED;
    }
    else if (speed < MIN_SPEED)
    {
        printf("Speed (%d) is too low. Setting speed to minimum (%d).\n", speed, MIN_SPEED);
        speed = MIN_SPEED;
    }
    
    return speed;
}