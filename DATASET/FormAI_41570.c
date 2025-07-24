//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>

//function to move forward
void moveForward(int distance){
    printf("moving forward %d cm\n",distance);
}

//function to turn left
void turnLeft(){
    printf("turning left\n");
}

//function to turn right
void turnRight(){
    printf("turning right\n");
}

//function to stop
void stop(){
    printf("stopping\n");
}

int main()
{
    char direction = 'f';
    int distance = 10;
    int i;
    for(i=0;i<5;i++){
        switch(direction){
            case 'f':
                moveForward(distance);
                direction = 'l';
                break;
            case 'l':
                turnLeft();
                direction = 'f';
                break;
            case 'r':
                turnRight();
                direction = 'f';
                break;
        }
    }
    stop();
    return 0;
}