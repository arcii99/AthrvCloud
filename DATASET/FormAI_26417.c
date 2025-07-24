//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TRAFFIC 100 // Maximum number of cars on the road
#define MAX_SPEED 60 // Maximum speed of cars in km/hr
#define MAX_LANES 3 // Maximum number of lanes on the road
#define ROAD_LENGTH 1000 // Length of the road in meters
#define UPDATE_INTERVAL 5 // Time interval between updates in seconds

typedef struct car{
    int speed; // Speed of the car in km/hr
    int lane; // Lane in which the car is traveling
    int distance_traveled; // Distance traveled by car in meters
} car;

int main(){
    srand(time(NULL)); // Seed the random number generator
    
    car road[MAX_LANES][MAX_TRAFFIC]; // Road with multiple lanes and cars
    
    int time_elapsed = 0; // Total time elapsed in simulation
    int cars_on_the_road = 0; // Number of cars on the road
    
    // Initialize the road with no cars
    for(int i=0; i<MAX_LANES; i++){
        for(int j=0; j<MAX_TRAFFIC; j++){
            road[i][j].speed = 0;
            road[i][j].lane = -1;
            road[i][j].distance_traveled = 0;
        }
    }
    
    // Start the simulation
    while(time_elapsed < 3600){ // Run the simulation for 1 hour
        printf("Time Elapsed: %d seconds\n", time_elapsed);
        
        // Add new cars to the road
        for(int i=0; i<MAX_LANES; i++){
            if(rand()%2 == 0){ // 50% chance of a new car entering the lane
                int car_speed = rand()%(MAX_SPEED+1); // Generate a random speed for the car
                car_speed++; // Ensure that the speed is greater than 0
                int free_slot = -1; // Initialize the index of the free slot
                for(int j=0; j<MAX_TRAFFIC; j++){
                    if(road[i][j].speed == 0){ // If the slot is free
                        free_slot = j; // Store the index of the free slot
                        break;
                    }
                }
                if(free_slot != -1){ // If a free slot was found
                    road[i][free_slot].speed = car_speed;
                    road[i][free_slot].lane = i;
                    road[i][free_slot].distance_traveled = 0;
                    cars_on_the_road++;
                    printf("New car entered Lane %d, with speed %d km/hr\n", (i+1), car_speed);
                }
            }
        }
        
        // Update the positions of the cars on the road
        for(int i=0; i<MAX_LANES; i++){
            for(int j=0; j<MAX_TRAFFIC; j++){
                if(road[i][j].speed != 0){ // If the slot is not free
                    int distance_to_travel = (road[i][j].speed * UPDATE_INTERVAL)/3.6; // Calculate the distance to be traveled
                    road[i][j].distance_traveled += distance_to_travel;
                    if(road[i][j].distance_traveled >= ROAD_LENGTH){ // If the car has reached the end of the road
                        printf("Car in Lane %d, Slot %d has reached the end of the road\n", (i+1), (j+1));
                        road[i][j].speed = 0;
                        road[i][j].lane = -1;
                        road[i][j].distance_traveled = 0;
                        cars_on_the_road--;
                    }
                    else{ // If the car has not reached the end of the road
                        int possible_lanes[MAX_LANES];
                        int num_possible_lanes = 0;
                        for(int k=0; k<MAX_LANES; k++){ // Populate the array of possible lanes
                            if(k != i && road[k][j].speed == 0 && road[k][j-1].speed == 0 && road[k][j+1].speed == 0){
                                possible_lanes[num_possible_lanes] = k;
                                num_possible_lanes++;
                            }
                        }
                        if(num_possible_lanes > 0){ // If there are possible lanes to switch to
                            int new_lane = possible_lanes[rand()%num_possible_lanes]; // Select a random possible lane
                            if(rand()%2 == 0){ // 50% chance to switch lanes
                                road[new_lane][j] = road[i][j]; // Move the car to the new lane
                                road[i][j].speed = 0;
                                road[i][j].lane = -1;
                                road[i][j].distance_traveled = 0;
                                printf("Car in Lane %d, Slot %d switched to Lane %d\n", (i+1), (j+1), (new_lane+1));
                            }
                        }
                    }
                }
            }
        }
        
        // Print the current state of the road
        printf("Cars on the Road: %d\n", cars_on_the_road);
        for(int i=0; i<MAX_LANES; i++){
            for(int j=0; j<MAX_TRAFFIC; j++){
                if(road[i][j].speed != 0){ // If the slot is not free
                    printf("Lane %d, Slot %d | Speed: %d km/hr | Distance Traveled: %d meters\n", (i+1), (j+1), road[i][j].speed, road[i][j].distance_traveled);
                }
            }
        }
        
        // Wait for the update interval
        printf("----------------------\n");
        time_elapsed += UPDATE_INTERVAL;
    }
    
    printf("Simulation Over!\n");
    
    return 0;
}