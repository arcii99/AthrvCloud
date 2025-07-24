//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define the struct for GPS location
struct gpsLocation {
    double latitude;
    double longitude;
};

//define the function for generating random GPS location
struct gpsLocation generateRandomLocation() {
    struct gpsLocation location;
    location.latitude = ((double)rand()/(double)RAND_MAX) * 180 - 90;    //generate a random latitude between -90 to 90 degrees
    location.longitude = ((double)rand()/(double)RAND_MAX) * 360 - 180;  //generate a random longitude between -180 to 180 degrees
    return location;
}

//define the function for printing GPS location
void printLocation(struct gpsLocation location) {
    printf("(%.2f, %.2f)\n", location.latitude, location.longitude);
}

int main() {
    srand(time(NULL));      //set the seed for random number generation
    struct gpsLocation currentLocation = generateRandomLocation();   //initialize current location with a random GPS location
    struct gpsLocation destination = generateRandomLocation();      //initialize destination with a random GPS location
    printf("Starting navigation from ");
    printLocation(currentLocation);
    printf("to ");
    printLocation(destination);
    printf("\n");
    //start navigation loop
    while(currentLocation.latitude != destination.latitude || currentLocation.longitude != destination.longitude) {
        //calculate the distance and direction to the destination
        double dLatitude = destination.latitude - currentLocation.latitude;
        double dLongitude = destination.longitude - currentLocation.longitude;
        double distance = sqrt(dLatitude * dLatitude + dLongitude * dLongitude);
        double direction = atan2(dLongitude, dLatitude);
        //generate a random variation in direction with max 45 degrees
        direction += ((double)rand()/(double)RAND_MAX) * 45 - 22.5;
        //move towards the destination with a random speed between 0 and 10 m/s
        double speed = ((double)rand()/(double)RAND_MAX) * 10;
        currentLocation.latitude += distance * cos(direction) * speed;
        currentLocation.longitude += distance * sin(direction) * speed;
        //print the current location
        printf("Current location: ");
        printLocation(currentLocation);
    }
    printf("Destination reached!\n");
    return 0;
}