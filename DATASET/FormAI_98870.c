//FormAI DATASET v1.0 Category: Robot movement control ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int main(){
    int x = 0, y = 0;
    srand(time(NULL)); //for random movement

    printf("Starting at position (%d,%d)\n", x, y);

    for(int i=0;i<10;i++){
        int move = rand()%4 + 1; //generating random number between 1 to 4

        switch(move){
            case FORWARD:
                y++; //incrementing y coordinate for moving forward
                printf("Moving forward to position (%d,%d)\n", x, y);
                break;
            case BACKWARD:
                y--; //decrementing y coordinate for moving backward
                printf("Moving backward to position (%d,%d)\n", x, y);
                break;
            case LEFT:
                x--; //decrementing x coordinate for moving left
                printf("Moving left to position (%d,%d)\n", x, y);
                break;
            case RIGHT:
                x++; //incrementing x coordinate for moving right
                printf("Moving right to position (%d,%d)\n", x, y);
                break;
            default:
                break;
        }
    }

    printf("Final position is (%d,%d)\n", x, y);
    return 0;
}