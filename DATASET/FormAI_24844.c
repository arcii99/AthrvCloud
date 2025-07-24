//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); //seed the random number generator
    int cycle = 1; //initialize cycle number to 1
    int green_time = 15; //in seconds
    int amber_time = 3; //in seconds
    int red_time = 30; //in seconds
    int north_south = 1; //1=North-South; 0=East-West
    int NS_waiting_cars = 0; //number of cars waiting at North-South
    int EW_waiting_cars = 0; //number of cars waiting at East-West
    int curr_light = 2; //1=Green, 2=Amber, 3=Red
    int timer = 0; //initialize timer to 0
    int i, j;
    while(cycle <= 5){ //run for 5 cycles
        printf("Cycle %d\n", cycle);
        //check for cars waiting
        if(north_south){
            NS_waiting_cars = rand() % 10;
            printf("Number of cars waiting at North-South: %d\n", NS_waiting_cars);
        } else {
            EW_waiting_cars = rand() % 7;
            printf("Number of cars waiting at East-West: %d\n", EW_waiting_cars);
        }
        //print current status
        printf("Current status: ");
        if(curr_light == 1){
            printf("Green\n");
            timer = green_time;
            if(north_south){
                printf("North-South road is green; East-West road is red\n");
            } else {
                printf("East-West road is green; North-South road is red\n");
            }
        } else if(curr_light == 2){
            printf("Amber\n");
            timer = amber_time;
        } else {
            printf("Red\n");
            timer = red_time;
            //switch lights
            if(north_south){
                north_south = 0;
            } else {
                north_south = 1;
            }
            curr_light = 1;
            printf("Switching lights\n");
        }
        //count down timer
        for(i=timer; i>=0; i--){
            printf("Time left: %d\n", i);
            //check for emergency vehicles
            if(i == 5){
                printf("Emergency vehicle approaching, giving priority\n");
                //send current cars through and hold other lanes
                if(north_south){
                    printf("North-South road is now amber\n");
                    for(j=0; j<NS_waiting_cars; j++){
                        printf("Car %d from North-South road has crossed\n", j+1);
                    }
                } else {
                    printf("East-West road is now amber\n");
                    for(j=0; j<EW_waiting_cars; j++){
                        printf("Car %d from East-West road has crossed\n", j+1);
                    }
                }
                break;
            }
            //check if timer is up
            if(i == 0){
                //switch lights and reset timer
                curr_light++;
                if(curr_light > 3){
                    curr_light = 1;
                    if(north_south){
                        north_south = 0;
                    } else {
                        north_south = 1;
                    }
                    printf("Switching lights\n");
                }
            }
            //check for pedestrian crossing
            if(i == 10){
                printf("Pedestrian crossing\n");
            }
            //let cars through
            if(curr_light == 1 && i < 5){
                if(north_south){
                    for(j=0; j<NS_waiting_cars; j++){
                        printf("Car %d from North-South road has crossed\n", j+1);
                    }
                    NS_waiting_cars = 0;
                } else {
                    for(j=0; j<EW_waiting_cars; j++){
                        printf("Car %d from East-West road has crossed\n", j+1);
                    }
                    EW_waiting_cars = 0;
                }
                break;
            }
        }
        cycle++; //increment cycle number
        printf("\n");
    }
    printf("End of simulation\n");
    return 0;
}