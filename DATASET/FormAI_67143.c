//FormAI DATASET v1.0 Category: Robot movement control ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0)); // initializing random seed

    printf("Welcome to Robot Movement Simulator!\n");

    int x = 0, y = 0; // initial position
    printf("Robot is currently at (%d,%d)\n", x, y);

    int steps; // number of steps to be taken
    printf("Enter the number of steps you want the Robot to take: ");
    scanf("%d", &steps);

    printf("Robot is moving...\n");

    for(int i = 0; i < steps; i++){
        int move = rand() % 4; // generating random number between 0 and 3 for movement direction
        switch(move){
            case 0: // move up
                y++;
                printf("Robot moves up. Current position: (%d,%d)\n", x, y);
                break;
            case 1: // move down
                y--;
                printf("Robot moves down. Current position: (%d,%d)\n", x, y);
                break;
            case 2: // move left
                x--;
                printf("Robot moves left. Current position: (%d,%d)\n", x, y);
                break;
            case 3: // move right
                x++;
                printf("Robot moves right. Current position: (%d,%d)\n", x, y);
                break;
            default:
                printf("Oops! Something went wrong.\n");
                exit(0);
        }
    }

    printf("Robot stopped. Final position: (%d,%d)\n", x, y);
    return 0;
}