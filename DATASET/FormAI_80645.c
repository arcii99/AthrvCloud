//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for latitude and longitude limits
#define LAT_MIN 5
#define LAT_MAX 15
#define LON_MIN 10
#define LON_MAX 20

// define a constant that determines the size of the grid in km
#define GRID_SIZE 10

// define a function that generates a random integer within a given range
int randInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

// define a struct to represent a location
typedef struct {
    double lat;
    double lon;
} Location;

// define a function that calculates the distance between two locations
double getDistance(Location loc1, Location loc2) {
    double latDiff = loc1.lat - loc2.lat;
    double lonDiff = loc1.lon - loc2.lon;
    double distance = sqrt(latDiff * latDiff + lonDiff * lonDiff);
    return distance;
}

// define a function that generates a random location within the given limits
Location generateLocation() {
    Location loc;
    loc.lat = randInRange(LAT_MIN, LAT_MAX) + (double)rand() / RAND_MAX;
    loc.lon = randInRange(LON_MIN, LON_MAX) + (double)rand() / RAND_MAX;
    return loc;
}

// define a function that generates a random destination that is not the current location
Location generateDestination(Location currentLoc) {
    Location dest = generateLocation();
    while (getDistance(currentLoc, dest) < 1) {
        dest = generateLocation();
    }
    return dest;
}

// define a function that converts latitude and longitude to grid coordinates
void getLocationInGrid(Location loc, int *x, int *y) {
    *x = (int)(loc.lon - LON_MIN) / GRID_SIZE;
    *y = (int)(loc.lat - LAT_MIN) / GRID_SIZE;
}

int main() {
    srand(time(NULL)); // initialize random seed based on current time

    // generate a current location and a destination
    Location currentLoc = generateLocation();
    Location destination = generateDestination(currentLoc);

    // print the current location and the destination
    printf("Current Location: (%lf, %lf)\n", currentLoc.lat, currentLoc.lon);
    printf("Destination: (%lf, %lf)\n", destination.lat, destination.lon);

    // convert both locations into grid coordinates
    int currentX, currentY, destX, destY;
    getLocationInGrid(currentLoc, &currentX, &currentY);
    getLocationInGrid(destination, &destX, &destY);

    // print the grid coordinates of the current location and the destination
    printf("Current Location in Grid: (%d, %d)\n", currentX, currentY);
    printf("Destination in Grid: (%d, %d)\n", destX, destY);

    // simulate the GPS navigation by moving towards the destination
    Location nextLoc = currentLoc;
    while (getDistance(nextLoc, destination) > 0.1) {
        // calculate the direction towards the destination
        double latDiff = destination.lat - nextLoc.lat;
        double lonDiff = destination.lon - nextLoc.lon;
        double heading = atan2(latDiff, lonDiff);

        // calculate the distance to travel
        double distance = fmin(getDistance(nextLoc, destination), 0.5);

        // calculate the next location
        nextLoc.lat += distance * cos(heading);
        nextLoc.lon += distance * sin(heading);

        // print the new location
        int newX, newY;
        getLocationInGrid(nextLoc, &newX, &newY);
        if (newX != currentX || newY != currentY) {
            printf("New Location in Grid: (%d, %d)\n", newX, newY);
            currentX = newX;
            currentY = newY;
        }
    }

    // print the final destination
    printf("You have arrived at the destination: (%lf, %lf)\n", destination.lat, destination.lon);

    return 0;
}