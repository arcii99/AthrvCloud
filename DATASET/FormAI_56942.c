//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROUTES 10
#define MAX_COORDS 100
#define MAX_GPS_ERROR 5

// Structure for GPS coordinates
typedef struct {
    float latitude;
    float longitude;
} Coordinate;

// Structure for a GPS route
typedef struct {
    int num_coords;
    Coordinate coords[MAX_COORDS];
} Route;

// Prints the current GPS coordinates
void print_current_coords(Coordinate current_coords) {
    printf("\nCurrent GPS Coordinates:\n");
    printf("\tLatitude: %.6f\n", current_coords.latitude);
    printf("\tLongitude: %.6f\n", current_coords.longitude);
}

// Calculates the distance between two GPS coordinates
float calculate_distance(Coordinate coord1, Coordinate coord2) {
    float lat1 = coord1.latitude;
    float lat2 = coord2.latitude;
    float lon1 = coord1.longitude;
    float lon2 = coord2.longitude;
    float dlat = (lat2-lat1) * (3.14159265/180);
    float dlon = (lon2-lon1) * (3.14159265/180);
    float a = sin(dlat/2) * sin(dlat/2) + cos(lat1*(3.14159265/180)) * cos(lat2*(3.14159265/180)) * sin(dlon/2) * sin(dlon/2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float distance = 6371 * c;
    return distance;
}

// Generates a random GPS error for simulation purposes
float generate_gps_error() {
    float error = ((float)(rand() % (2*MAX_GPS_ERROR))-MAX_GPS_ERROR) / 1000;
    return error;
}

// Simulates GPS navigation along a route
void navigate(Route route) {
    Coordinate current_coords = route.coords[0];
    print_current_coords(current_coords);
    int i;
    for (i=1; i<route.num_coords; i++) {
        Coordinate target_coords = route.coords[i];
        float distance = calculate_distance(current_coords, target_coords);
        printf("\nTravelling from (%.6f, %.6f) to (%.6f, %.6f)\n", current_coords.latitude, current_coords.longitude, target_coords.latitude, target_coords.longitude);
        printf("Distance to next waypoint: %.2f km\n", distance);
        while (distance > 0.01) {
            float error = generate_gps_error();
            float lat_error = error * cos(target_coords.latitude * (3.14159265/180));
            float lon_error = error * sin(target_coords.longitude * (3.14159265/180));
            current_coords.latitude += (target_coords.latitude - current_coords.latitude + lat_error) / 100;
            current_coords.longitude += (target_coords.longitude - current_coords.longitude + lon_error) / 100;
            distance = calculate_distance(current_coords, target_coords);
            print_current_coords(current_coords);
            printf("Distance to next waypoint: %.2f km\n", distance);
        }
        current_coords = target_coords;
    }
    printf("\nArrived at final destination!\n");
}

// Main function
int main() {
    srand(time(NULL));
    // Define some GPS routes for simulation
    Route all_routes[MAX_ROUTES];
    all_routes[0].num_coords = 4;
    all_routes[0].coords[0].latitude = 43.6532;
    all_routes[0].coords[0].longitude = -79.3832;
    all_routes[0].coords[1].latitude = 43.6534;
    all_routes[0].coords[1].longitude = -79.3829;
    all_routes[0].coords[2].latitude = 43.6543;
    all_routes[0].coords[2].longitude = -79.3805;
    all_routes[0].coords[3].latitude = 43.6542;
    all_routes[0].coords[3].longitude = -79.3778;
    all_routes[1].num_coords = 5;
    all_routes[1].coords[0].latitude = 51.5074;
    all_routes[1].coords[0].longitude = -0.1278;
    all_routes[1].coords[1].latitude = 51.5094;
    all_routes[1].coords[1].longitude = -0.1284;
    all_routes[1].coords[2].latitude = 51.5109;
    all_routes[1].coords[2].longitude = -0.1346;
    all_routes[1].coords[3].latitude = 51.5113;
    all_routes[1].coords[3].longitude = -0.1358;
    all_routes[1].coords[4].latitude = 51.5143;
    all_routes[1].coords[4].longitude = -0.1312;
    all_routes[2].num_coords = 3;
    all_routes[2].coords[0].latitude = 48.8584;
    all_routes[2].coords[0].longitude = 2.2945;
    all_routes[2].coords[1].latitude = 48.8598;
    all_routes[2].coords[1].longitude = 2.2949;
    all_routes[2].coords[2].latitude = 48.8606;
    all_routes[2].coords[2].longitude = 2.2958;
    // Choose a random route to simulate navigation on
    int random_route_num = rand() % 3;
    printf("Simulating GPS navigation...\n");
    printf("Route details:\n");
    printf("Number of waypoints: %d\n", all_routes[random_route_num].num_coords);
    int j;
    for (j=0; j<all_routes[random_route_num].num_coords; j++) {
        printf("\tWaypoint %d: (%.6f, %.6f)\n", j+1, all_routes[random_route_num].coords[j].latitude, all_routes[random_route_num].coords[j].longitude);
    }
    navigate(all_routes[random_route_num]);
    return 0;
}