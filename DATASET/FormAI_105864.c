//FormAI DATASET v1.0 Category: Robot movement control ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void move_forward(int distance) {
    printf("Moving forward %d units.\n", distance);
}

void move_backward(int distance) {
    printf("Moving backward %d units.\n", distance);
}

void turn_left(int angle) {
    printf("Turning left %d degrees.\n", angle);
}

void turn_right(int angle) {
    printf("Turning right %d degrees.\n", angle);
}

void move_randomly(int distance) {
    int rand_num = rand() % 4;
    switch(rand_num) {
        case 0:
            move_forward(distance);
            break;
        case 1:
            move_backward(distance);
            break;
        case 2:
            turn_left(90);
            move_forward(distance);
            break;
        case 3:
            turn_right(90);
            move_forward(distance);
            break;
        default:
            printf("Error: Invalid random number generated.\n");
            break;
    }
}

int main() {
    srand(time(0));
    printf("Starting movement control program.\n");
    printf("Robot is currently facing forward.\n");
    int distance = 10;
    int num_moves = 10;
    for(int i = 0; i < num_moves; i++) {
        int rand_num = rand() % 2;
        switch(rand_num) {
            case 0:
                move_randomly(distance);
                break;
            case 1:
                move_forward(distance);
                break;
            default:
                printf("Error: Invalid random number generated.\n");
                break;
        }
    }
    printf("Program complete.\n");
    return 0;
}