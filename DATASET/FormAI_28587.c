//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void takeOff(){
    printf("Initiating engine sequence... \n");
    printf("3... 2... 1... Lift off! \n");
}

void explorePlanet(int planet){
    printf("Exploring planet %d... \n", planet);
    // simulate planet exploration time
    int time = rand() % 10 + 1;
    printf("Exploration time: %d seconds \n", time);
}

void landOnPlanet(int planet){
    printf("Landing on planet %d... \n", planet);
    // simulate landing time
    int time = rand() % 5 + 1;
    printf("Landing time: %d seconds \n", time);
}

void warpSpeed(){
    printf("Engaging warp speed... \n");
    // simulate warp speed time
    int time = rand() % 10 + 1;
    printf("Time elapsed: %d seconds \n", time);
}

int main(){
    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Procedural Space Adventure! \n");

    int planet1 = 2736;
    int planet2 = 1492;

    takeOff();

    printf("Approaching planet %d... \n", planet1);
    landOnPlanet(planet1);
    explorePlanet(planet1);

    warpSpeed();

    printf("Approaching planet %d... \n", planet2);
    landOnPlanet(planet2);
    explorePlanet(planet2);

    warpSpeed();

    printf("Returning to Earth... \n");
    landOnPlanet(0);

    printf("Thank you for participating in the Procedural Space Adventure! \n");

    return 0;
}