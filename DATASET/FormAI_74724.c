//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random number between min and max
int generateRandomNumber(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){

    //Setting seed for random number generator
    srand(time(NULL));

    //Variables to store traffic flow
    int northBound = 0, southBound = 0, eastBound = 0, westBound = 0;

    //Medieval style traffic simulation
    printf("\t\t\tWelcome to Medieval traffic flow simulation!\n\n");

    //Loop for simulating traffic flow for 10 rounds
    for(int i=1; i<=10; i++){

        //Random number generation to simulate vehicles coming from different directions
        int vehicleCount = generateRandomNumber(1, 7);
        int northVehicleCount = generateRandomNumber(0, vehicleCount);
        int southVehicleCount = generateRandomNumber(0, vehicleCount - northVehicleCount);
        int eastVehicleCount = generateRandomNumber(0, vehicleCount - northVehicleCount - southVehicleCount);
        int westVehicleCount = vehicleCount - northVehicleCount - southVehicleCount - eastVehicleCount;

        //Updating traffic flow variables for each direction
        northBound += northVehicleCount;
        southBound += southVehicleCount;
        eastBound += eastVehicleCount;
        westBound += westVehicleCount;

        //Displaying simulation round results
        printf("Simulation Round %d\n", i);
        printf("-----------------------------\n");
        printf("North Bound Vehicles: %d\n", northVehicleCount);
        printf("South Bound Vehicles: %d\n", southVehicleCount);
        printf("East Bound Vehicles: %d\n", eastVehicleCount);
        printf("West Bound Vehicles: %d\n\n", westVehicleCount);
    }

    //Displaying final traffic flow
    printf("Final Traffic Flow\n");
    printf("-----------------------------\n");
    printf("North Bound Vehicles: %d\n", northBound);
    printf("South Bound Vehicles: %d\n", southBound);
    printf("East Bound Vehicles: %d\n", eastBound);
    printf("West Bound Vehicles: %d\n", westBound);

    return 0;
}