//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random numbers between two given limits
int random_number(int min, int max){
    return rand()%(max-min+1)+min;
}

// Function to update the traffic flow based on the current densities
float update_traffic_flow(float density, float velocity){
    float flow = density*velocity;
    return flow;
}

// Main Function
int main(){
    int population = 100;   // Total population in the simulation
    float car_density = 0.4;  // Initial car density
    float truck_density = 0.2;  // Initial truck density
    float bus_density = 0.1;  // Initial bus density
    float velocity = 50;  // Velocity of vehicles
    float car_size = 2.5;  // Size of cars
    float truck_size = 4.5;  // Size of trucks
    float bus_size = 6.0;  // Size of buses
    float car_flow, truck_flow, bus_flow, total_flow;
    int tick_count = 0;  // Total time elapsed

    // Initializing Random Number Generator
    srand(time(NULL)); 

    // Simulation Loop
    while (tick_count < 100){
        printf("Time: %d\n", tick_count);

        car_flow = update_traffic_flow(car_density, velocity/car_size);
        truck_flow = update_traffic_flow(truck_density, velocity/truck_size);
        bus_flow = update_traffic_flow(bus_density, velocity/bus_size);

        total_flow = car_flow + truck_flow + bus_flow;

        // Calculating new densities based on the previous densities and total vehicle flow
        car_density += (random_number(0,2) - 1)*(car_density/10) + (random_number(0,2) - 1)*(total_flow/population);
        truck_density += (random_number(0,2) - 1)*(truck_density/10) + (random_number(0,2) - 1)*(total_flow/population);
        bus_density += (random_number(0,2) - 1)*(bus_density/10) + (random_number(0,2) - 1)*(total_flow/population);

        // Making sure densities do not exceed 100%
        if(car_density > 1.0){
            car_density = 1.0;
        }
        if(truck_density > 1.0){
            truck_density = 1.0;
        }
        if(bus_density > 1.0){
            bus_density = 1.0;
        }

        // Printing the traffic flow at the current tick
        printf("Car Flow: %f\n", car_flow);
        printf("Truck Flow: %f\n", truck_flow);
        printf("Bus Flow: %f\n", bus_flow);
        printf("Total Flow: %f\n", total_flow);

        tick_count++;
    }

    printf("Simulation Over.\n");

    return 0;
}