//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4 // Maximum number of threads that can be created
#define WAYPOINT_COUNT 10 // Number of waypoints to navigate

// Struct to store coordinates of waypoints
typedef struct {
    double latitude;
    double longitude;
} Waypoint;

// Waypoint coordinates for simulation
Waypoint waypoints[WAYPOINT_COUNT] = {
    {40.748817, -73.985428},
    {40.758896, -73.985130},
    {40.768644, -73.983290},
    {40.773914, -73.966326},
    {40.764599, -73.962873},
    {40.754352, -73.971629},
    {40.747474, -73.989086},
    {40.733279, -73.990016},
    {40.729834, -73.974081},
    {40.738262, -73.962686}
};

// Struct to store GPS data
typedef struct {
    double latitude;
    double longitude;
    double speed;
    double heading;
} GPSData;

// Function to simulate GPS data
void* gpsSimulator(void* arg) {
    GPSData* gpsData = (GPSData*) arg;
    int currentWaypointIndex = 0;

    // Loop through waypoints and update GPS data
    while (currentWaypointIndex < WAYPOINT_COUNT) {
        Waypoint currentWaypoint = waypoints[currentWaypointIndex];

        // Calculate distance and heading to current waypoint
        double latDiff = currentWaypoint.latitude - gpsData->latitude;
        double longDiff = currentWaypoint.longitude - gpsData->longitude;
        double distance = sqrt(latDiff*latDiff + longDiff*longDiff);
        double heading = atan2(latDiff, longDiff);

        // Update GPS data
        gpsData->latitude = currentWaypoint.latitude;
        gpsData->longitude = currentWaypoint.longitude;
        gpsData->speed = distance / 5;
        gpsData->heading = heading;

        currentWaypointIndex++;
        sleep(2);
    }

    // This is a dummy return value as pthreads require a void*
    return NULL;
}

int main() {
    GPSData gpsData = {40.748817, -73.985428, 0, 0};

    // Create GPS simulator thread
    pthread_t simThread;
    pthread_create(&simThread, NULL, gpsSimulator, &gpsData);

    // Loop until GPS simulation is complete
    while (gpsData.heading != 0) {
        // Print GPS data
        printf("Latitude: %f\n", gpsData.latitude);
        printf("Longitude: %f\n", gpsData.longitude);
        printf("Speed: %f\n", gpsData.speed);
        printf("Heading: %f\n", gpsData.heading);
        printf("\n");

        // Sleep for 1 second
        sleep(1);
    }

    // Join GPS simulator thread
    pthread_join(simThread, NULL);

    return 0;
}