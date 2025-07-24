//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 60
#define SPEED_LIMIT 60

int recursive_traffic_flow(int curr_time, int num_cars, int speed_limit){
    if(curr_time > MAX_TIME){ //base case
        return num_cars;
    }

    int random_cars = rand() % (speed_limit/2); //generate random number of cars
    int new_num_cars = num_cars + random_cars; //update total number of cars
    
    printf("After %d minutes, %d cars are on the road.\n", curr_time, new_num_cars);

    return recursive_traffic_flow(curr_time + 1, new_num_cars, speed_limit); //recursive call
}

int main(){
    srand(time(NULL)); //seed random number generator

    int num_cars = rand() % SPEED_LIMIT; //generate initial number of cars
    printf("At time 0, %d cars are on the road.\n", num_cars);

    int total_cars = recursive_traffic_flow(1, num_cars, SPEED_LIMIT); //start recursive simulation

    printf("%d cars traveled on the road in the past hour.\n", total_cars);

    return 0;
}