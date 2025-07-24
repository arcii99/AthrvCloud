//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// structure to represent a vehicle
struct vehicle{
    int id;         // vehicle id
    int speed;      // vehicle speed
    int lane;       // vehicle lane
    int distance;   // distance covered by vehicle
};

// function to initialize a vehicle
void init_vehicle(struct vehicle *v, int id, int lane){
    v->id = id;
    v->speed = (rand() % 80) + 20;   //random speed between 20 and 100
    v->lane = lane;
    v->distance = 0;
}

// function to simulate traffic flow for a lane
void simulate_lane(int lane, int num_vehicles){
    struct vehicle vehicles[num_vehicles];
    int i,j;

    // initialize vehicles in the lane
    for(i=0;i<num_vehicles;i++){
        init_vehicle(&vehicles[i], i+1, lane);
    }

    // simulate traffic flow for the lane
    while(1){
        // print current state of lane
        printf("\nLane %d:\n", lane);
        for(i=0;i<num_vehicles;i++){
            printf("Vehicle %d, Speed: %d, Distance Covered: %d\n", vehicles[i].id, vehicles[i].speed, vehicles[i].distance);
        }

        // check for collisions
        for(i=0;i<num_vehicles;i++){
            for(j=0;j<num_vehicles;j++){
                if(i!=j && vehicles[i].lane == vehicles[j].lane && abs(vehicles[i].distance - vehicles[j].distance) < 20){
                    printf("Collision between Vehicle %d and Vehicle %d on Lane %d!\n", vehicles[i].id, vehicles[j].id, lane);
                    exit(0);
                }
            }
        }

        // update distance covered by each vehicle
        for(i=0;i<num_vehicles;i++){
            vehicles[i].distance += vehicles[i].speed;
        }

        // introduce random slow down or lane change
        for(i=0;i<num_vehicles;i++){
            if(rand() % 10 == 0){
                vehicles[i].speed -= 10;   // slow down
                if(vehicles[i].speed < 20){
                    vehicles[i].speed = 20;
                }
            }

            if(rand() % 10 == 0){
                int new_lane = (rand() % 3) + 1;   // lane change
                if(new_lane != vehicles[i].lane){
                    vehicles[i].lane = new_lane;
                    printf("Vehicle %d shifted to Lane %d.\n", vehicles[i].id, new_lane);
                }
            }
        }

        // introduce delay
        usleep(500000);     // delay of 0.5 seconds
    }
}

// main function
int main(){
    srand(time(NULL));     // seed random number generator
    simulate_lane(1, 10);  // simulate traffic flow for lane 1
    return 0;
}