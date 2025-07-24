//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0)); //initialize random seed
    int current_light = 1; //initialize current light to Green
    int time_left = rand() % 20 + 1; //initialize time_left to a random number between 1 and 20

    printf("Traffic Light Controller\n");

    while(1){
        printf("Time left for current light: %d\n", time_left);

        if(time_left == 0){ //time for current light is over, switch to next light
            if(current_light == 1){
                printf("Green Light -> Yellow Light\n");
                current_light = 2; //switch to Yellow Light
                time_left = 3; //set time for Yellow Light to 3 seconds
            }
            else if(current_light == 2){
                printf("Yellow Light -> Red Light\n");
                current_light = 3; //switch to Red Light
                time_left = 10; //set time for Red Light to 10 seconds
            }
            else if(current_light == 3){
                printf("Red Light -> Green Light\n");
                current_light = 1; //switch to Green Light
                time_left = rand() % 20 + 1; //set time for Green Light to a random number between 1 and 20
            }
        }

        time_left--; //decrement time left by 1 second
        sleep(1); //wait for 1 second
    }

    return 0;
}