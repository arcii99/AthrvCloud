//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOCATIONS 100

// define a structure for holding the location details
struct location {
    char name[20];
    double latitude;
    double longitude;
};

// define a structure for holding the route
struct route {
    struct location locations[MAX_LOCATIONS];
    int num_locations;
    double total_distance;
};

// function to calculate distance between two locations using Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2) {
    double rad = 6371; // radius of Earth in km
    double dlat = (lat2 - lat1) * (3.14159265359 / 180); // convert to radians
    double dlon = (lon2 - lon1) * (3.14159265359 / 180);
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1 * (3.14159265359 / 180)) * cos(lat2 * (3.14159265359 / 180)) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double dist = rad * c; // distance in km
    return dist;
}

// function to add a location to the route
void add_location(struct route *r, char *name, double lat, double lon) {
    strcpy(r->locations[r->num_locations].name, name);
    r->locations[r->num_locations].latitude = lat;
    r->locations[r->num_locations].longitude = lon;
    r->num_locations++;
}

// function to calculate the total distance of the route
void calculate_distance(struct route *r) {
    double total_distance = 0;
    for(int i = 0; i < r->num_locations - 1; i++) {
        double dist = distance(r->locations[i].latitude, r->locations[i].longitude, r->locations[i+1].latitude, r->locations[i+1].longitude);
        total_distance += dist;
    }
    r->total_distance = total_distance;
}

int main() {
    struct route r;
    r.num_locations = 0;
    add_location(&r, "New York City", 40.712776, -74.005974);
    add_location(&r, "Washington DC", 38.907192, -77.036871);
    add_location(&r, "Chicago", 41.878114, -87.629798);
    add_location(&r, "San Francisco", 37.774929, -122.419416);
    calculate_distance(&r);
    printf("Route:\n");
    for(int i = 0; i < r.num_locations; i++) {
        printf("%s\n", r.locations[i].name);
    }
    printf("Total distance: %0.2f km\n", r.total_distance);
    return 0;
}