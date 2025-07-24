//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS       10
#define MAX_JUNCTIONS   5
#define MAX_VEHICLES    50
#define MAX_NO_OF_MILES 100
#define MAX_NO_OF_TURN  2

#define NORTH           0
#define EAST            1
#define SOUTH           2
#define WEST            3

typedef struct {

    int vehicleId;
    int junctionId;
    int milesLeft;
    int turnDirection;

} Vehicle;

typedef struct {

    int junctionId;
    int northSouthRoad;
    int eastWestRoad;

} Junction;

typedef struct {

    int junctionOneId;
    int junctionTwoId;
    int distance;

} Road;

Vehicle vehicles[MAX_VEHICLES];
Junction junctions[MAX_JUNCTIONS];
Road roads[MAX_ROADS];
int junctionCount = 0;
int roadCount = 0;
int vehicleCount = 0;

int getNextJunction(int currentJunctionId, int roadId) {
    Road currentRoad = roads[roadId];
    if (currentRoad.junctionOneId == currentJunctionId)
        return currentRoad.junctionTwoId;
    else
        return currentRoad.junctionOneId;
}

void moveVehicle(int vehicleId) {
    Vehicle currentVehicle = vehicles[vehicleId];
    int currentJunctionId = currentVehicle.junctionId;
    int currentRoadId = 0, nextJunctionId = 0, nextRoadId = 0;

    // Pick a random road
    do {
        currentRoadId = rand() % roadCount;
    } while (roads[currentRoadId].junctionOneId != currentJunctionId
             && roads[currentRoadId].junctionTwoId != currentJunctionId);

    // Get the next junction and road
    nextJunctionId = getNextJunction(currentJunctionId, currentRoadId);

    // Check for the turn signal
    if (currentVehicle.milesLeft == 0) {
        currentVehicle.turnDirection = rand() % MAX_NO_OF_TURN;
        currentVehicle.milesLeft = rand() % MAX_NO_OF_MILES;
    }

    // Get the next road based on the turn signal
    if (junctions[nextJunctionId].northSouthRoad == currentRoadId) {
        if (currentVehicle.turnDirection == NORTH)
            nextRoadId = junctions[nextJunctionId].eastWestRoad;
        else
            nextRoadId = junctions[nextJunctionId].northSouthRoad;
    } else {
        if (currentVehicle.turnDirection == EAST)
            nextRoadId = junctions[nextJunctionId].northSouthRoad;
        else
            nextRoadId = junctions[nextJunctionId].eastWestRoad;
    }

    // Move the vehicle
    vehicles[vehicleId].milesLeft--;
    vehicles[vehicleId].junctionId = nextJunctionId;

    printf("Vehicle %d moving from junction %d to junction %d on road %d\n",
           currentVehicle.vehicleId, currentJunctionId, nextJunctionId, currentRoadId);

    // Check if the vehicle has completed its route
    if (currentVehicle.junctionId == junctions[1].junctionId
        && currentVehicle.milesLeft == 0) {
        printf("Vehicle %d has reached its destination.\n", currentVehicle.vehicleId);
        vehicles[vehicleId].junctionId = -1;
        vehicles[vehicleId].vehicleId = -1;
    }
    else {
        moveVehicle(vehicleId);
    }
}

int main() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAX_VEHICLES; i++) {
        vehicles[i].vehicleId = -1;
        vehicles[i].junctionId = -1;
        vehicles[i].milesLeft = 0;
        vehicles[i].turnDirection = -1;
    }

    junctions[0].junctionId = 0;
    junctions[0].northSouthRoad = 0;
    junctions[0].eastWestRoad = 1;

    junctions[1].junctionId = 1;
    junctions[1].northSouthRoad = 2;
    junctions[1].eastWestRoad = 3;

    roads[0].junctionOneId = 0;
    roads[0].junctionTwoId = 1;
    roads[0].distance = 2;

    roads[1].junctionOneId = 0;
    roads[1].junctionTwoId = 2;
    roads[1].distance = 1;

    roads[2].junctionOneId = 1;
    roads[2].junctionTwoId = 3;
    roads[2].distance = 3;

    roads[3].junctionOneId = 2;
    roads[3].junctionTwoId = 3;
    roads[3].distance = 2;

    junctionCount = 4;
    roadCount = 4;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < MAX_VEHICLES; j++) {
            if (vehicles[j].vehicleId == -1 && vehicles[j].junctionId == -1) {
                vehicles[j].vehicleId = j;
                vehicles[j].junctionId = 0;
                vehicles[j].milesLeft = 0;
                vehicles[j].turnDirection = -1;
                break;
            }
        }
    }

    for (i = 0; i < MAX_VEHICLES; i++) {
        if (vehicles[i].vehicleId != -1 && vehicles[i].junctionId != -1) {
            moveVehicle(vehicles[i].vehicleId);
        }
    }

    return 0;
}