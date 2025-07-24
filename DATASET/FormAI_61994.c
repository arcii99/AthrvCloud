//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structures to store GPS coordinates
typedef struct gps_coord {
    double lat; // Latitude
    double lon; // Longitude
} GPS_Coord;

typedef struct gps_node {
    char name[100]; // Location name
    GPS_Coord coord; // GPS coordinates
} GPS_Node;

// Data structure to represent the map
typedef struct gps_map {
    GPS_Node *nodes; // Array of nodes (locations)
    int num_nodes; // Number of nodes in the map
} GPS_Map;

// Calculate the distance between two GPS coordinates (in kilometers)
double gps_distance(GPS_Coord coord1, GPS_Coord coord2) {
    double R = 6371; // Earth's radius (in kilometers)
    double lat1 = coord1.lat * M_PI / 180; // Convert to radians
    double lat2 = coord2.lat * M_PI / 180;
    double dlat = (lat2 - lat1) * M_PI / 180;
    double dlon = (coord2.lon - coord1.lon) * M_PI / 180;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

// Find the nearest node to a given GPS coordinate
int gps_find_nearest_node(GPS_Map map, GPS_Coord coord) {
    int nearest_node = 0;
    double nearest_distance = INFINITY;
    for (int i = 0; i < map.num_nodes; i++) {
        double distance = gps_distance(coord, map.nodes[i].coord);
        if (distance < nearest_distance) {
            nearest_distance = distance;
            nearest_node = i;
        }
    }
    return nearest_node;
}

// Navigate from one node to another (outputting directions)
void gps_navigate(GPS_Map map, int start_node, int end_node) {
    printf("Starting from %s (%lf, %lf).\n", map.nodes[start_node].name, map.nodes[start_node].coord.lat, map.nodes[start_node].coord.lon);
    printf("Heading towards %s (%lf, %lf).\n", map.nodes[end_node].name, map.nodes[end_node].coord.lat, map.nodes[end_node].coord.lon);
    printf("Distance: %lf kilometers.\n", gps_distance(map.nodes[start_node].coord, map.nodes[end_node].coord));
}

int main() {
    // Create a sample map
    GPS_Node nodes[] = {
        {"New York", {40.713054, -74.007228}},
        {"London", {51.507351, -0.127758}},
        {"Paris", {48.856613, 2.352222}},
        {"Tokyo", {35.689487, 139.691706}},
        {"Sydney", {-33.865143, 151.209900}}
    };
    GPS_Map map = {nodes, 5};
    
    // Find the nearest node to a given location
    GPS_Coord my_location = {40.735657, -73.991832};
    int nearest_node = gps_find_nearest_node(map, my_location);
    printf("Nearest node to my location is %s.\n", map.nodes[nearest_node].name);
    
    // Navigate from one node to another
    int start_node = 0; // New York
    int end_node = 3; // Tokyo
    gps_navigate(map, start_node, end_node);
    
    return 0;
}