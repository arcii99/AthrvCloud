//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20   // Road length
#define V_MAX 5   // Maximum velocity
#define SIM_TIME 50   // Simulation time in seconds
#define DELTA_T 1   // Time step
#define PROB_OBSTACLE 0.3   // Probability of an obstacle on the road
#define PROB_SLOW_DOWN 0.5   // Probability of slowing down

// Function to display the road
void display_road(int road[], int time_step) {
    printf("Time Step: %d\n", time_step);
    for(int i=0; i<ROAD_LENGTH; i++) {
        if(road[i] == -1) {
            printf("O ");
        } else if(road[i] == 0) {
            printf("- ");
        } else {
            printf("%d ", road[i]);
        }
    }
    printf("\n\n");
}

int main() {
    srand(time(0));   // Seed the random number generator
    int road[ROAD_LENGTH];   // Road array
    int time = 0;   // Simulation time
    int num_vehicles = 0;   // Number of vehicles on the road
    int obstacles = 0;   // Number of obstacles on the road
    int vehicle_id = 1;   // Vehicle ID
    int v[ROAD_LENGTH];   // Vehicle velocities
    
    // Initialize the road
    for(int i=0; i<ROAD_LENGTH; i++) {
        if((float)rand()/RAND_MAX <= PROB_OBSTACLE) {
            road[i] = -1;   // Obstacle
            obstacles++;
        } else {
            road[i] = 0;   // Empty space
        }
    }
    
    // Initialize the velocities to 0
    for(int i=0; i<ROAD_LENGTH; i++) {
        v[i] = 0;
    }
    
    // Start the simulation
    while(time < SIM_TIME) {
        // Add a vehicle to the road with probability 1/3
        if((float)rand()/RAND_MAX <= 1.0/3.0 && num_vehicles < ROAD_LENGTH - obstacles) {
            int pos = rand() % ROAD_LENGTH;
            while(road[pos] != 0) {
                pos = rand() % ROAD_LENGTH;
            }
            road[pos] = vehicle_id;
            v[pos] = 1;
            num_vehicles++;
            vehicle_id++;
        }
        
        // Update vehicle velocities and positions
        for(int i=0; i<ROAD_LENGTH; i++) {
            if(road[i] > 0) {
                int id = road[i];   // ID of the current vehicle
                int d_min = ROAD_LENGTH;   // Minimum distance between the current vehicle and the next one
                int v_new = v[i];   // New velocity of the current vehicle
                
                // Calculate the minimum distance to the next vehicle
                // and the new velocity of the current vehicle
                for(int j=i+1; j<ROAD_LENGTH; j++) {
                    if(road[j] > 0) {
                        d_min = j - i - 1;
                        break;
                    }
                }
                
                if(d_min == ROAD_LENGTH) {
                    // No vehicle ahead, accelerate up to the maximum velocity
                    if(v[i] < V_MAX) {
                        v_new++;
                    }
                } else if(d_min <= v[i]) {
                    // Vehicle ahead is too close, slow down
                    v_new = d_min - 1;
                } else {
                    // Vehicle ahead is far enough, speed up if possible
                    if(v[i] < V_MAX) {
                        v_new++;
                    }
                }
                
                // Add some randomness to the velocity changes
                if((float)rand()/RAND_MAX <= PROB_SLOW_DOWN && v_new > 0) {
                    v_new--;
                }
                
                v[i] = v_new;
                
                // Update the position of the vehicle
                road[i] = 0;
                int pos = i + v[i];
                if(pos >= ROAD_LENGTH) {
                    pos -= ROAD_LENGTH;
                }
                road[pos] = id;
            }
        }
        
        // Display the road
        display_road(road, time);
        
        // Wait for some time before the next update
        printf("Press Enter to continue...\n");
        getchar();
        
        time += DELTA_T;
    }
    
    return 0;
}