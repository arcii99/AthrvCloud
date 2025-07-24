//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_X 20
#define MAX_Y 20
#define MAX_STEPS 50

// Define struct for Robot
typedef struct{
    int x;
    int y;
} Robot;

// Function to initialize Robot position randomly
void init_robot(Robot* r){
    srand(time(NULL)); // seed random number generator
    r->x = rand() % MAX_X;
    r->y = rand() % MAX_Y;
    printf("Robot initialized at position (%d, %d)\n\n", r->x, r->y);
}

// Function to move Robot in the specified direction
void move_robot(Robot* r, char direction){
    switch(direction){
        case 'U':
            if(r->y > 0) r->y--;
            break;
        case 'D':
            if(r->y < MAX_Y-1) r->y++;
            break;
        case 'L':
            if(r->x > 0) r->x--;
            break;
        case 'R':
            if(r->x < MAX_X-1) r->x++;
            break;
    }
}

// Function to print Robot position
void print_robot(Robot r){
    printf("Robot is at position (%d, %d)\n", r.x, r.y);
}

// Main function
int main(){
    Robot r;
    init_robot(&r);
    char directions[] = {'U', 'D', 'L', 'R'};
    int steps = 0;
    while(steps < MAX_STEPS){
        char direction = directions[rand() % 4];
        move_robot(&r, direction);
        print_robot(r);
        steps++;
    }
    printf("\nRobot has completed %d steps.\n", MAX_STEPS);
    return 0;
}