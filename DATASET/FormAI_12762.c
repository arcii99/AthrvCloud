//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

int main(){
    int x = 0, y = 0, direction = FORWARD;
    int num_moves = 10;

    srand(time(NULL));

    printf("Starting position: x=%d, y=%d\n", x, y);

    for(int i = 0; i < num_moves; i++){
        int rand_num = rand() % 4;

        switch(rand_num){
            case LEFT:
                printf("Moving Left\n");
                if(direction == FORWARD){
                    direction = LEFT;
                }
                else if(direction == BACKWARD){
                    direction = RIGHT;
                }
                else if(direction == LEFT){
                    direction = BACKWARD;
                }
                else{
                    direction = FORWARD;
                }
                break;
            case RIGHT:
                printf("Moving Right\n");
                if(direction == FORWARD){
                    direction = RIGHT;
                }
                else if(direction == BACKWARD){
                    direction = LEFT;
                }
                else if(direction == LEFT){
                    direction = FORWARD;
                }
                else{
                    direction = BACKWARD;
                }
                break;
            case FORWARD:
                printf("Moving Forward\n");
                if(direction == FORWARD){
                    y++;
                }
                else if(direction == BACKWARD){
                    y--;
                }
                else if(direction == LEFT){
                    x--;
                }
                else{
                    x++;
                }
                break;
            case BACKWARD:
                printf("Moving Backward\n");
                if(direction == FORWARD){
                    y--;
                }
                else if(direction == BACKWARD){
                    y++;
                }
                else if(direction == LEFT){
                    x++;
                }
                else{
                    x--;
                }
                break;
        }
    }

    printf("Final position: x=%d, y=%d\n", x, y);

    return 0;
}