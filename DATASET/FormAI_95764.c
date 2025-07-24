//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SPEED 100
#define MAX_ANGLE 90

// Global variables for the vehicle's speed and angle
int speed = 0;
int angle = 0;

// Function to simulate the vehicle's movements based on the speed and angle
void* simulate_movement(void* arg) {
    while(1) {
        printf("Vehicle is moving at %d km/hr and at %d degree angle.\n", speed, angle);
        usleep(1000000);
    }
}

// Function to control the speed of the vehicle
void* control_speed(void* arg) {
    int increase = *((int*) arg);
    while(1) {
        if(increase && speed < MAX_SPEED) {
            speed++;
        } else if(!increase && speed > 0) {
            speed--;
        }
        usleep(100000);
    }
}

// Function to control the angle of the vehicle
void* control_angle(void* arg) {
    int increase = *((int*) arg);
    while(1) {
        if(increase && angle < MAX_ANGLE) {
            angle++;
        } else if(!increase && angle > -MAX_ANGLE) {
            angle--;
        }
        usleep(200000);
    }
}

// Main function to start the program
int main() {
    // Set up the threads for each control function
    pthread_t speed_thread, angle_thread, movement_thread;
    
    // Create arguments for controlling speed and angle
    int increase_speed = 1;
    int decrease_speed = 0;
    int increase_angle = 1;
    int decrease_angle = 0;
    
    // Start the threads for each control function
    pthread_create(&speed_thread, NULL, control_speed, &increase_speed);
    pthread_create(&angle_thread, NULL, control_angle, &increase_angle);
    pthread_create(&movement_thread, NULL, simulate_movement, NULL);
    
    // Wait for input from user to change speed and angle
    char input;
    while(1) {
        printf("Enter '+' to increase speed, '-' to decrease speed, 'a' to turn left, or 'd' to turn right. Press 'q' to quit.\n");
        input = getchar();
        getchar(); // Clear the newline character from input stream
        
        // Change speed or angle based on user input
        switch(input) {
            case '+':
                increase_speed = 1;
                decrease_speed = 0;
                break;
            case '-':
                increase_speed = 0;
                decrease_speed = 1;
                break;
            case 'a':
                increase_angle = 0;
                decrease_angle = 1;
                break;
            case 'd':
                increase_angle = 1;
                decrease_angle = 0;
                break;
            case 'q':
                // End all threads and exit the program
                pthread_cancel(speed_thread);
                pthread_cancel(angle_thread);
                pthread_cancel(movement_thread);
                printf("Terminating program.\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    }
    
    return 0;
}