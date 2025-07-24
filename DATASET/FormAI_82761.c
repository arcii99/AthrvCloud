//FormAI DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPEED 0.5 // speed of the robot
#define TURN_SPEED 0.2 // speed of turning

// function definitions
void move_forward(void);
void move_backward(void);
void turn_left(void);
void turn_right(void);
void stop_robot(void);

int main(void) {
    srand(time(NULL)); // seed for random function

    while(1) { // loop forever
        int random_num = rand() % 4; // generate random number (0-3)
        switch(random_num) { // choose random movement
            case 0:
                move_forward();
                break;
            case 1:
                move_backward();
                break;
            case 2:
                turn_left();
                break;
            case 3:
                turn_right();
                break;
        }
        usleep(300000); // sleep for 300ms
    }
}

// function for moving robot forward
void move_forward(void) {
    printf("Moving forward\n");
    // code for moving forward
    usleep((int)(1000000*SPEED));
    stop_robot();
}

// function for moving robot backward
void move_backward(void) {
    printf("Moving backward\n");
    // code for moving backward
    usleep((int)(1000000*SPEED));
    stop_robot();
}

// function for turning robot left
void turn_left(void) {
    printf("Turning left\n");
    // code for turning left
    usleep((int)(1000000*TURN_SPEED));
    stop_robot();
}

// function for turning robot right
void turn_right(void) {
    printf("Turning right\n");
    // code for turning right
    usleep((int)(1000000*TURN_SPEED));
    stop_robot();
}

// function for stopping the robot
void stop_robot(void) {
    printf("Stopping\n");
    // code for stopping the robot
}