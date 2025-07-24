//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constants
#define NUM_LANES 3
#define LANE_CAPACITY 100
#define MAX_VEHICLES 1000

//Function prototypes
void generate_traffic(int traffic[][NUM_LANES], int num_vehicles);
void update_traffic(int traffic[][NUM_LANES]);
void print_traffic(int traffic[][NUM_LANES]);

int main()
{
    int traffic[MAX_VEHICLES][NUM_LANES] = {0};
    int num_vehicles = 500;
    
    //Seed the random number generator
    srand(time(NULL));
    
    //Generate initial traffic
    generate_traffic(traffic, num_vehicles);
    
    //Loop through simulation steps
    for(int i=0; i<10; i++)
    {
        //Print traffic state
        printf("Step %d:\n", i+1);
        print_traffic(traffic);
        
        //Update traffic state
        update_traffic(traffic);
    }
    
    return 0;
}

//Function to randomly generate traffic
void generate_traffic(int traffic[][NUM_LANES], int num_vehicles)
{
    //Generate random vehicles for each lane
    for(int i=0; i<NUM_LANES; i++)
    {
        int lane_vehicles = 0;
        while(lane_vehicles < num_vehicles)
        {
            int vehicle = rand() % LANE_CAPACITY + 1;
            if(lane_vehicles + vehicle > num_vehicles)
            {
                vehicle = num_vehicles - lane_vehicles;
            }
            traffic[lane_vehicles][i] = vehicle;
            lane_vehicles += vehicle;
        }
    }
}

//Function to update traffic state
void update_traffic(int traffic[][NUM_LANES])
{
    //Loop through each lane
    for(int i=0; i<NUM_LANES; i++)
    {
        //Loop through each vehicle in the lane
        for(int j=0; j<LANE_CAPACITY; j++)
        {
            //Check if the vehicle has moved
            if(traffic[j][i] > 0 && (j == 0 || traffic[j-1][i] == 0))
            {
                int new_pos = j-1;
                //Move the vehicle to the new position
                traffic[new_pos][i] = traffic[j][i];
                traffic[j][i] = 0;
            }
        }
    }
}

//Function to print the traffic state
void print_traffic(int traffic[][NUM_LANES])
{
    //Print each lane
    for(int i=0; i<NUM_LANES; i++)
    {
        printf("Lane %d:", i+1);
        for(int j=0; j<LANE_CAPACITY; j++)
        {
            printf("%c ", traffic[j][i] > 0 ? 'X' : '_');
        }
        printf("\n");
    }
    printf("\n");
}