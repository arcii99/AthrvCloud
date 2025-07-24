//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUTES 10
#define MAX_WAYPOINTS 50

struct waypoint {
    double latitude;
    double longitude;
};

struct route {
    int num_waypoints;
    struct waypoint waypoints[MAX_WAYPOINTS];
};

struct navigator {
    struct route routes[MAX_ROUTES];
    int num_routes;
};

void add_waypoint(struct route *r, double lat, double lon) {
    if (r->num_waypoints >= MAX_WAYPOINTS) {
        printf("Error: Maximum number of waypoints exceeded.\n");
        return;
    }
    r->waypoints[r->num_waypoints].latitude = lat;
    r->waypoints[r->num_waypoints].longitude = lon;
    r->num_waypoints++;
}

void add_route(struct navigator *nav, struct route r) {
    if (nav->num_routes >= MAX_ROUTES) {
        printf("Error: Maximum number of routes exceeded.\n");
        return;
    }
    nav->routes[nav->num_routes] = r;
    nav->num_routes++;
}

void print_waypoint(struct waypoint wp) {
    printf("(%f,%f)", wp.latitude, wp.longitude);
}

void print_route(struct route r) {
    int i;
    for (i=0; i<r.num_waypoints; i++) {
        print_waypoint(r.waypoints[i]);
        if (i < r.num_waypoints-1)
            printf(" -> ");
    }
    printf("\n");
}

void print_navigator(struct navigator nav) {
    int i;
    for (i=0; i<nav.num_routes; i++) {
        print_route(nav.routes[i]);
    }
}

int main() {
    struct navigator nav;
    nav.num_routes = 0;

    // create a route with three waypoints
    struct route r1;
    r1.num_waypoints = 0;
    add_waypoint(&r1, 37.7749, -122.4194);
    add_waypoint(&r1, 37.8716, -122.2727);
    add_waypoint(&r1, 37.8050, -122.2730);
    add_route(&nav, r1);

    // create another route with four waypoints
    struct route r2;
    r2.num_waypoints = 0;
    add_waypoint(&r2, 37.3327, -122.0059);
    add_waypoint(&r2, 37.3809, -122.1158);
    add_waypoint(&r2, 37.4138, -121.8683);
    add_waypoint(&r2, 37.3337, -121.8903);
    add_route(&nav, r2);

    // print all routes
    print_navigator(nav);

    return 0;
}