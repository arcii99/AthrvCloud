//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEFT 1
#define RIGHT 2
#define FORWARD 3
#define BACKWARD 4

int main(){

    int posX=0,posY=0,direction=FORWARD;//initial position and direction
    int distance,maxDist,remainingDist,turns,count=0;

    srand(time(0));//seed the random generator with the current time
    maxDist=rand()%50+1;//set maximum distance with a random number between 1-50
    remainingDist=maxDist;

    while(1){
        printf("\nVehicle Position: (%d,%d) - ",posX,posY);

        if(direction==LEFT){
            printf("LEFT DIRECTION\n");
        }
        else if(direction==RIGHT){
            printf("RIGHT DIRECTION\n");
        }
        else if(direction==FORWARD){
            printf("FORWARD DIRECTION\n");
        }
        else{
            printf("BACKWARD DIRECTION\n");
        }

        if(remainingDist<=0){
            printf("\nMaximum distance reached, simulation complete.\n");
            break;
        }

        //generate a random number to determine the direction
        turns=rand()%4+1;

        switch (turns)
        {
        case LEFT:
            direction=LEFT;
            printf("\nTurning Left...");
            break;
        case RIGHT:
            direction=RIGHT;
            printf("\nTurning Right...");
            break;
        case FORWARD:
            direction=FORWARD;
            printf("\nMoving Forward...");
            break;
        case BACKWARD:
            direction=BACKWARD;
            printf("\nMoving Backward...");
            break;
        }

        //generate a random number to determine the distance travelled
        distance=rand()%10+1;

        if(distance>remainingDist){//if distance exceed the remaining distance, adjust the distance accordingly
            distance=remainingDist;
        }
        remainingDist-=distance;//update remaining distance after moving

        //update x and y position based on direction and distance travelled
        if(direction==LEFT){
            posX-=distance;
        }
        else if(direction==RIGHT){
            posX+=distance;
        }
        else if(direction==FORWARD){
            posY+=distance;
        }
        else{
            posY-=distance;
        }

        printf("\nDistance Travelled: %d\n",distance);
    }

    return 0;
}