//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void changeLight(int light, int time);

int main()
{
    int green_time = 10, yellow_time = 5, red_time = 15;
    int loop_count = 0;
    
    printf("Traffic light controller starting...\n");
    
    while(loop_count < 5){
        printf("Loop %d: \n", loop_count+1);
        changeLight(1, green_time); //Green light
        changeLight(2, yellow_time); //Yellow light
        changeLight(3, red_time); //Red light
        loop_count++;
    }
    
    printf("Traffic light controller stopped.\n");
    
    return 0;
}

void changeLight(int light, int time){
    printf("Light [%d] is on for [%d] seconds.\n", light, time);
    if(light == 1){
        changeLight(2, time/3); //Change to yellow light
    }
    else if(light == 2){
        changeLight(3, time/2); //Change to red light
    }
    else{
        return; //Exit recursive function
    }
}