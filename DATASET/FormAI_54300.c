//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUTES 100
#define MAX_WAYPOINTS 200

typedef struct {
    int id;
    char* name;
    float lat;
    float lon;
} Waypoint;

typedef struct {
    int id;
    char* name;
    Waypoint* waypoints[MAX_WAYPOINTS];
    int num_waypoints;
} Route;

Route routes[MAX_ROUTES];
int num_routes = 0;

void add_waypoint(Route* route, Waypoint* waypoint) {
    route->waypoints[route->num_waypoints] = waypoint;
    route->num_waypoints++;
}

void add_route(Route* route) {
    routes[num_routes] = *route;
    num_routes++;
}

void print_route(Route route) {
    printf("Route: %s\n", route.name);
    for (int i = 0; i < route.num_waypoints; i++) {
        printf("%d. %s (%f, %f)\n", i+1, route.waypoints[i]->name, route.waypoints[i]->lat, route.waypoints[i]->lon);
    }
}

int main() {
    // create some waypoints
    Waypoint wp1 = {1, "First waypoint", 1.0, 1.0};
    Waypoint wp2 = {2, "Second waypoint", 2.0, 2.0};
    Waypoint wp3 = {3, "Third waypoint", 3.0, 3.0};
    
    // create a route and add waypoints
    Route route = {1, "My first route"};
    add_waypoint(&route, &wp1);
    add_waypoint(&route, &wp2);
    add_waypoint(&route, &wp3);
    
    // add route to list
    add_route(&route);
    
    // print out route
    print_route(routes[0]);
    
    return 0;
}