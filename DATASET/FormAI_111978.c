//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

// Define functions for the different vehicle movements
void move_forward(void);
void move_backward(void);
void turn_left(void);
void turn_right(void);

// Declare global variables for vehicle movements and thread synchronization
bool is_moving_forward = false;
bool is_moving_backward = false;
bool is_turning_left = false;
bool is_turning_right = false;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    // Display initial instructions for the user
    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Use the following commands to control the vehicle:\n");
    printf("w - move forward\n");
    printf("s - move backward\n");
    printf("a - turn left\n");
    printf("d - turn right\n");

    // Declare a character buffer to store user input
    char input_buffer[256];

    // Begin the main program loop to accept user input
    while (true) {
        // Get user input
        fgets(input_buffer, sizeof(input_buffer), stdin);

        // Check the input and execute the respective vehicle movement
        pthread_mutex_lock(&mutex);
        if (strcmp(input_buffer, "w\n") == 0) {
            is_moving_forward = true;
            move_forward();
            is_moving_forward = false;
        }
        else if (strcmp(input_buffer, "s\n") == 0) {
            is_moving_backward = true;
            move_backward();
            is_moving_backward = false;
        }
        else if (strcmp(input_buffer, "a\n") == 0) {
            is_turning_left = true;
            turn_left();
            is_turning_left = false;
        }
        else if (strcmp(input_buffer, "d\n") == 0) {
            
            is_turning_right = true;
            turn_right();
            is_turning_right = false;
        }
        pthread_mutex_unlock(&mutex);
    }

    // Exit the program
    return 0;
}

void move_forward(void)
{
    printf("Moving forward...\n");
    sleep(1);
    printf("Vehicle has stopped.\n");
    return;
}

void move_backward(void)
{
    printf("Moving backward...\n");
    sleep(1);
    printf("Vehicle has stopped.\n");
    return;
}

void turn_left(void)
{
    printf("Turning left...\n");
    sleep(1);
    printf("Vehicle has stopped.\n");
    return;
}

void turn_right(void)
{
    printf("Turning right...\n");
    sleep(1);
    printf("Vehicle has stopped.\n");
    return;
}