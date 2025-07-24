//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //declaring variables
    int num_cars = 0;
    int num_lanes = 3;
    int max_speed = 60;
    float density = 0.5;
    float flow_rate;
    int i,j;
    srand(time(0));
    
    //initializing values for each vehicle on the road
    struct Car{
        int current_speed;
        int position;
    }cars[num_cars];

    //generating random speeds and positions for each vehicle
    for(i=0;i<num_cars;i++){
        cars[i].current_speed = rand()%(max_speed+1);
        cars[i].position = rand()%500;
    }

    //determining the flow rate of the traffic
    for(i=0;i<num_lanes;i++){
        int lane_count = 0;
        for(j=0;j<num_cars;j++){
            if(cars[j].position >= i*500/num_lanes && cars[j].position < (i+1)*500/num_lanes){
                lane_count++;
            }
        }
        flow_rate += (float)lane_count*max_speed/num_lanes/500; 
    }

    //displaying the traffic flow rate
    printf("Traffic flow rate is %.2f vehicles per second\n",flow_rate*density);

    return 0;
}