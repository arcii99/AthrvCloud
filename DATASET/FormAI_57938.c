//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROUTES 100
#define MAX_WAYPOINTS 100
#define DEG_TO_RAD (M_PI/180.0)
#define EARTH_RADIUS 6378.137 // in kilometers

typedef struct {
    double latitude;
    double longitude;
    double elevation; // in meters
} Waypoint;

typedef struct {
    char name[20];
    Waypoint waypoints[MAX_WAYPOINTS];
    int num_waypoints;
} Route;

Route routes[MAX_ROUTES];
int num_routes = 0;

void add_waypoint(Route *route, Waypoint wp) {
    if (route->num_waypoints == MAX_WAYPOINTS) {
        printf("Maximum number of waypoints (%d) reached\n", MAX_WAYPOINTS);
        return;
    }
    route->waypoints[route->num_waypoints++] = wp;
}

double distance_between_waypoints(Waypoint wp1, Waypoint wp2) {
    double lat1_rad = wp1.latitude * DEG_TO_RAD;
    double lon1_rad = wp1.longitude * DEG_TO_RAD;
    double lat2_rad = wp2.latitude * DEG_TO_RAD;
    double lon2_rad = wp2.longitude * DEG_TO_RAD;
    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;
    double a = sin(dlat/2.0) * sin(dlat/2.0) + 
               cos(lat1_rad) * cos(lat2_rad) * 
               sin(dlon/2.0) * sin(dlon/2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0-a));
    double dist = EARTH_RADIUS * c;
    return dist;
}

int main() {
    Waypoint wp1 = {.latitude = 50.0958, .longitude = 8.6490, .elevation = 112.4};
    Waypoint wp2 = {.latitude = 50.1234, .longitude = 8.6432, .elevation = 96.2};
    Waypoint wp3 = {.latitude = 50.0876, .longitude = 8.6712, .elevation = 85.3};
    Route route1 = {.name = "Frankfurt", .num_waypoints = 0};
    add_waypoint(&route1, wp1);
    add_waypoint(&route1, wp2);
    add_waypoint(&route1, wp3);
    routes[num_routes++] = route1;

    Waypoint wp4 = {.latitude = 51.5074, .longitude = -0.1278, .elevation = 11.1};
    Waypoint wp5 = {.latitude = 51.4550, .longitude = -0.0403, .elevation = 61.2};
    Waypoint wp6 = {.latitude = 51.5734, .longitude = -0.1128, .elevation = 23.7};
    Route route2 = {.name = "London", .num_waypoints = 0};
    add_waypoint(&route2, wp4);
    add_waypoint(&route2, wp5);
    add_waypoint(&route2, wp6);
    routes[num_routes++] = route2;

    int route_index = 0;
    double min_distance = distance_between_waypoints(route1.waypoints[0],
                                                      route2.waypoints[0]);
    for (int i = 0; i < route1.num_waypoints; ++i) {
        for (int j = 0; j < route2.num_waypoints; ++j) {
            double dist = distance_between_waypoints(route1.waypoints[i],
                                                     route2.waypoints[j]);
            if (dist < min_distance) {
                min_distance = dist;
                route_index = i;
            }
        }
    }
    printf("The minimum distance between routes is %.1f km, and the closest waypoint is %f lat, %f lon, %f elev\n",
           min_distance, routes[0].waypoints[route_index].latitude, 
           routes[0].waypoints[route_index].longitude,
           routes[0].waypoints[route_index].elevation);

    return 0;
}