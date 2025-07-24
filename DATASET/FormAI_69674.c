//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int carCount = 0;
int truckCount = 0;
int carVelocity = 60; // km/hr
int truckVelocity = 40; // km/hr

void *generateVehicle(void *vehicleType) {
    int type = *(int *)vehicleType;
    
    // Vehicle speed calculation based on type
    int velocity = (type == 1) ? carVelocity : truckVelocity;
    
    while (1) {
        // Randomly generate number between 0 and 4 for delay
        int delay = rand() % 5;
        printf("\nVehicle Type %d arriving in %d seconds\n", type, delay);
        
        // Simulating vehicle movement through delay
        sleep(delay);
        printf("Vehicle Type %d has arrived\n", type);
        
        if (type == 1) carCount++;
        else truckCount++;
        
        // Calculate distance to next vehicle
        int distanceToNext = rand() % 100;
        printf("Vehicle Type %d is %d m away from next vehicle\n", type, distanceToNext);
        
        // Calculate time to reach next vehicle
        float timeToReachNext = ((float)distanceToNext / 1000) * (60 / velocity) * 60;
        printf("Vehicle Type %d will reach next vehicle in %.2f seconds\n", type, timeToReachNext);
        
        // Wait till vehicle reaches next vehicle
        sleep((int)timeToReachNext);
        printf("Vehicle Type %d reached next vehicle\n", type);
    }
}

int main() {
    pthread_t carThread, truckThread;
    int car = 1, truck = 2;
    
    // Create threads for car and truck
    pthread_create(&carThread, NULL, generateVehicle, &car);
    pthread_create(&truckThread, NULL, generateVehicle, &truck);
    
    // Wait for threads to exit
    pthread_join(carThread, NULL);
    pthread_join(truckThread, NULL);
    
    return 0;
}