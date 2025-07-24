//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Define struct to hold GPS location information
typedef struct {
    double latitude;
    double longitude;
} GPSLocation;

// Define struct to hold map node information
typedef struct {
    GPSLocation location;
    char name[MAX_SIZE];
} MapNode;

// Define struct to hold navigation route information
typedef struct {
    char name[MAX_SIZE];
    GPSLocation start_location;
    GPSLocation end_location;
} NavigationRoute;

// Function to print GPS location information
void print_gps_location(GPSLocation location) {
    printf("Latitude: %lf, Longitude: %lf\n", location.latitude, location.longitude);
}

// Function to print map node information
void print_map_node(MapNode node) {
    printf("Name: %s, Location:\n", node.name);
    print_gps_location(node.location);
}

// Function to print navigation route information
void print_navigation_route(NavigationRoute route) {
    printf("Route name: %s\n", route.name);
    printf("Start location:\n");
    print_gps_location(route.start_location);
    printf("End location:\n");
    print_gps_location(route.end_location);
}

int main() {
    // Initialize map nodes
    MapNode node_a = {{47.6097, -122.3331}, "Node A"};
    MapNode node_b = {{47.6058, -122.3293}, "Node B"};
    MapNode node_c = {{47.6029, -122.3255}, "Node C"};
    MapNode node_d = {{47.6000, -122.3217}, "Node D"};
    MapNode node_e = {{47.5971, -122.3179}, "Node E"};
    
    // Initialize navigation routes
    NavigationRoute route_1 = {"Route 1", node_a.location, node_e.location};
    NavigationRoute route_2 = {"Route 2", node_e.location, node_c.location};
    NavigationRoute route_3 = {"Route 3", node_c.location, node_d.location};
    NavigationRoute route_4 = {"Route 4", node_d.location, node_b.location};
    NavigationRoute route_5 = {"Route 5", node_b.location, node_a.location};
    
    // Print map node information
    printf("Map nodes:\n");
    print_map_node(node_a);
    print_map_node(node_b);
    print_map_node(node_c);
    print_map_node(node_d);
    print_map_node(node_e);
    
    // Print navigation route information
    printf("\nNavigation routes:\n");
    print_navigation_route(route_1);
    print_navigation_route(route_2);
    print_navigation_route(route_3);
    print_navigation_route(route_4);
    print_navigation_route(route_5);
    
    return 0;
}