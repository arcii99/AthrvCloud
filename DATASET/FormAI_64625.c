//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

void green_light();
void yellow_light();
void red_light();

int main(){

    srand(time(0)); //seeding the random number generator
    int timer = 0; //timer to keep track of time on each light

    while(true){

        int light = rand() % 3;//selecting random light
        switch(light){
            case 0: //green_light
                green_light();
                timer = 10;
                break;
            case 1: //yellow_light
                yellow_light();
                timer = 3;
                break;
            case 2: //red_light
                red_light();
                timer = 15;
                break;
            default:
                printf("Invalid case\n");
                exit(1);
        }

        while(timer > 0){//waiting for the timer to complete
            printf("Time remaining: %d\n", timer);
            sleep(1);
            timer--;
        }

    }

    return 0;

}

void green_light(){
    printf("Green light\n");
    //Code to turn on green light
    //Code to turn off red and yellow lights
}

void yellow_light(){
    printf("Yellow light\n");
    //Code to turn on yellow light
    //Code to turn off green and red lights
}

void red_light(){
    printf("Red light\n");
    //Code to turn on red light
    //Code to turn off green and yellow lights
}