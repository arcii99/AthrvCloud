//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: systematic
#include<stdio.h>
#include<math.h>

#define RADIUS 6371 // Earth's Radius in km

struct coordinate{
    double lat; // Latitude
    double lon; // Longitude
};

double degrees_to_radians(double degrees){
    return degrees * M_PI / 180;
}

double get_distance(struct coordinate a, struct coordinate b){
    double lat_difference = degrees_to_radians(b.lat - a.lat);
    double lon_difference = degrees_to_radians(b.lon - a.lon);
    double lat_a = degrees_to_radians(a.lat);
    double lat_b = degrees_to_radians(b.lat);

    double a1 = pow(sin(lat_difference/2),2) + cos(lat_a) * cos(lat_b) * pow(sin(lon_difference/2),2);
    double c = 2 * atan2(sqrt(a1),sqrt(1-a1));

    return RADIUS * c;
}

int main(){

    struct coordinate current_pos = {23.687045, 90.360348}; // Starting Position
    struct coordinate destination = {22.5726, 88.3639}; // Destination Location

    double distance_to_destination = get_distance(current_pos, destination);

    printf("Distance to your destination: %.2f km\n", distance_to_destination);

    return 0;
}