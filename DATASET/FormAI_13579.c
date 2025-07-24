//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 6
#define MAX_LANES 3

// Structure to hold the traffic lights
typedef struct {
    int green_time; // Time for green light
    int red_time; // Time for red light
    int remaining_time; // Remaining time for current light
    int current_color; // 0 for red, 1 for green
} traffic_light;

// Structure to hold the vehicle
typedef struct {
    int id; // Unique id of the vehicle
    int min_speed; // Minimum speed of the vehicle
    int max_speed; // Maximum speed of the vehicle
    int speed; // Current speed of the vehicle
    int lane; // Current lane of the vehicle
    int distance; // Distance of vehicle from traffic light
} vehicle;

// Structure to hold the lane
typedef struct {
    int max_cars; // Maximum number of cars the lane can store
    int num_cars; // Current number of cars in the lane
    vehicle* cars; // Array of cars in the lane
} lane;

// Structure to hold the road
typedef struct {
    int id; // Unique id of the road
    int length; // Length of the road
    traffic_light light; // Traffic light of the road
    lane lanes[MAX_LANES]; // Array of lanes on the road
} road;

// Define roads and their lengths
road roads[MAX_ROADS] = {
    { 1, 1000 },
    { 2, 800 },
    { 3, 1200 },
    { 4, 1500 },
    { 5, 600 },
    { 6, 1000 }
};

// Define traffic lights for each road
traffic_light lights[MAX_ROADS] = {
    { 20, 10, 10, 0 },
    { 30, 20, 20, 0 },
    { 40, 30, 30, 0 },
    { 50, 40, 40, 0 },
    { 20, 10, 10, 0 },
    { 30, 20, 20, 0 }
};

// Function to generate a random speed for a car
int get_random_speed(int min_speed, int max_speed) {
    return min_speed + rand() % (max_speed - min_speed + 1);
}

// Function to create a new vehicle and add it to a lane
void add_vehicle(int road_id, int lane_id, int dist) {
    int id = roads[road_id].lanes[lane_id].num_cars + 1;
    int min_speed = 10;
    int max_speed = 20;
    int speed = get_random_speed(min_speed, max_speed);
    vehicle v = { id, min_speed, max_speed, speed, lane_id, dist };
    roads[road_id].lanes[lane_id].cars[id-1] = v;
    roads[road_id].lanes[lane_id].num_cars++;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the lanes for each road
    for(int i=0; i<MAX_ROADS; i++) {
        for(int j=0; j<MAX_LANES; j++) {
            lane l = { 5, 0, malloc(sizeof(vehicle) * 5) };
            roads[i].lanes[j] = l;
        }
    }
    
    // Initialize the traffic lights
    for(int i=0; i<MAX_ROADS; i++) {
        roads[i].light = lights[i];
    }
    
    // Simulation loop
    int tick = 0;
    while(tick < 500) {
        // Update traffic lights
        for(int i=0; i<MAX_ROADS; i++) {
            traffic_light* tl = &roads[i].light;
            tl->remaining_time--;
            if(tl->remaining_time <= 0) {
                tl->current_color = !tl->current_color;
                tl->remaining_time = tl->current_color ? tl->green_time : tl->red_time;
            }
        }
        
        // Move cars
        for(int i=0; i<MAX_ROADS; i++) {
            road* r = &roads[i];
            for(int j=0; j<MAX_LANES; j++) {
                lane* l = &r->lanes[j];
                for(int k=0; k<l->num_cars; k++) {
                    vehicle* v = &l->cars[k];
                    v->distance -= v->speed;
                    if(v->distance <= 0) {
                        add_vehicle(i, j, r->length + v->distance);
                    }
                }
            }
        }
        
        // Print current state
        printf("Tick %d:\n", tick);
        for(int i=0; i<MAX_ROADS; i++) {
            road* r = &roads[i];
            printf("Road %d:\n", r->id);
            for(int j=0; j<MAX_LANES; j++) {
                lane* l = &r->lanes[j];
                printf("\tLane %d:\n", j+1);
                for(int k=0; k<l->num_cars; k++) {
                    vehicle* v = &l->cars[k];
                    printf("\t\tVehicle %d:\n", v->id);
                    printf("\t\t\tLane: %d\n", v->lane+1);
                    printf("\t\t\tSpeed: %d\n", v->speed);
                    printf("\t\t\tDistance: %d\n", v->distance);
                }
            }
        }
        
        tick++;
    }
    
    // Free memory
    for(int i=0; i<MAX_ROADS; i++) {
        for(int j=0; j<MAX_LANES; j++) {
            free(roads[i].lanes[j].cars);
        }
    }
    
    return 0;
}