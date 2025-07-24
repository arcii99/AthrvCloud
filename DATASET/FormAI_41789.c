//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTE_POINTS 20 // maximum number of route points
#define MAX_NAME_LENGTH 50 // maximum name length of a route point

// struct for a single route point
typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;
    double longitude;
} RoutePoint;

// struct for the GPS Navigation Simulation
typedef struct {
    RoutePoint route[MAX_ROUTE_POINTS]; // array of route points
    int num_route_points; // number of route points
    double current_lat; // current latitude
    double current_long; // current longitude
} GPSNavigationSim;

// function to add a route point to the simulation
void addRoutePoint(GPSNavigationSim* sim, char* name, double lat, double lon) {
    if (sim->num_route_points < MAX_ROUTE_POINTS) {
        RoutePoint new_point;
        strcpy(new_point.name, name);
        new_point.latitude = lat;
        new_point.longitude = lon;
        sim->route[sim->num_route_points++] = new_point;

        printf("Added route point: %s (%f, %f)\n", name, lat, lon);
    } else {
        printf("Cannot add any more route points!\n");
    }
}

// function to simulate moving to the next route point
void moveToNextRoutePoint(GPSNavigationSim* sim) {
    if (sim->num_route_points <= 1) {
        printf("Need at least two route points to navigate!\n");
        return;
    }

    double dist_to_next_point;
    double delta_lat, delta_long;
    double new_lat, new_long;

    // calculate distance to next route point
    delta_lat = sim->route[1].latitude - sim->current_lat;
    delta_long = sim->route[1].longitude - sim->current_long;
    dist_to_next_point = sqrt(delta_lat * delta_lat + delta_long * delta_long);

    if (dist_to_next_point < 0.0001) {
        printf("Arrived at %s!\n", sim->route[1].name);

        // remove the first route point and shift the array
        for (int i = 1; i < sim->num_route_points - 1; i++) {
            sim->route[i] = sim->route[i+1];
        }
        sim->num_route_points--;

        if (sim->num_route_points == 1) {
            printf("Reached final destination!\n");
            return;
        }
    } else {
        // calculate new latitude and longitude based on direction and speed
        delta_lat /= dist_to_next_point;
        delta_long /= dist_to_next_point;
        new_lat = sim->current_lat + delta_lat * 0.0001;
        new_long = sim->current_long + delta_long * 0.0001;

        printf("Moved to (%f, %f)\n", new_lat, new_long);

        // update current location
        sim->current_lat = new_lat;
        sim->current_long = new_long;
    }
}

int main() {
    GPSNavigationSim sim;
    sim.num_route_points = 0;
    sim.current_lat = 0.0;
    sim.current_long = 0.0;

    addRoutePoint(&sim, "Origin", 0.0, 0.0);
    addRoutePoint(&sim, "Waypoint 1", 0.001, 0.002);
    addRoutePoint(&sim, "Waypoint 2", 0.003, 0.004);
    addRoutePoint(&sim, "Destination", 0.005, 0.006);

    while (sim.num_route_points > 1) {
        moveToNextRoutePoint(&sim);
    }

    return 0;
}