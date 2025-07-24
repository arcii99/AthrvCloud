//FormAI DATASET v1.0 Category: Robot movement control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main(){

    //Robot movement variables
    int x_pos = 0;
    int y_pos = 0;
    int x_target = 6;
    int y_target = 8;

    //Robot speed
    int speed = 2;

    //Distance between the robot and target
    int distance = 0;

    //Loop variables
    int i;
    int j;

    //Calculate initial distance to target
    distance = abs(x_target - x_pos) + abs(y_target - y_pos);

    //Move robot until reaches target
    while(distance > 0){

        //Robot moves in x axis
        if(x_target > x_pos){
            x_pos += speed;
        }
        else{
            x_pos -= speed;
        }

        //Robot moves in y axis
        if(y_target > y_pos){
            y_pos += speed;
        }
        else{
            y_pos -= speed;
        }

        //Calculate new distance to target
        distance = abs(x_target - x_pos) + abs(y_target - y_pos);

        //Print robot position
        printf("Robot position: (%d,%d)\n",x_pos,y_pos);

        //Pause for a moment
        for(i=0;i<10000000;i++){
            for(j=0;j<1000;j++){
                //Waste some processing time
            }
        }
    }

    //Target reached
    printf("Target reached!\n");

    return 0;
}