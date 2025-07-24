//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random number for traffic flow rate in a range of min to max
int generateRandom(int min, int max){
    int range = max-min+1;
    return (rand() % range) + min;
}

int main(){
    srand(time(NULL)); // Seed for random number generation
    
    int i, j, t, seconds, trafficRate;
    int numLanes = 4;
    int maxCarsPerLane = 10;
    int maxSpeed = 50;
    int simulationTime = 3600; // time in seconds for simulation
    int trafficFlowRates[6] = {50, 100, 150, 200, 250, 300}; // flow rate for 6 time intervals
    int trafficDensity[numLanes][maxCarsPerLane]; // 2D array to store number of cars in each lane

    // Initialize traffic density to 0
    for(i=0; i<numLanes; i++){
        for(j=0; j<maxCarsPerLane; j++){
            trafficDensity[i][j] = 0;
        }
    }

    // Loop for each second of simulation
    for(seconds=0; seconds<simulationTime; seconds++){
        // Calculate current time interval
        t = seconds / 600; // 600 seconds = 10 minutes
        // Generate traffic rate for current time interval
        trafficRate = generateRandom(trafficFlowRates[t]-25, trafficFlowRates[t]+25); 
        // Loop for each lane to add new cars according to traffic rate
        for(i=0; i<numLanes; i++){
            for(j=maxCarsPerLane-1; j>=0; j--){
                if(trafficDensity[i][j] == 0){
                    if(rand()%100 < trafficRate/numLanes){
                        trafficDensity[i][j] = generateRandom(1, maxSpeed); // add new car with random speed
                        break;
                    }
                }
            }
        }
        // Loop for each lane to move cars
        for(i=0; i<numLanes; i++){
            for(j=maxCarsPerLane-1; j>=0; j--){
                if(trafficDensity[i][j] != 0){
                    if(j == maxCarsPerLane-1){
                        trafficDensity[i][j] = 0; // remove car from last position of lane
                    }
                    else{
                        trafficDensity[i][j+1] = trafficDensity[i][j]; // move car ahead
                        trafficDensity[i][j] = 0; // clear previous position
                    }
                }
            }
        }
        // Print traffic density for each second
        printf("Time: %d seconds\n", seconds);
        for(i=0; i<numLanes; i++){
            printf("Lane %d: ", i+1);
            for(j=0; j<maxCarsPerLane; j++){
                printf("%d ", trafficDensity[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}