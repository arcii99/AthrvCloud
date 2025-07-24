//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371 // Earth's radius in KM
#define MAX_DATAPOINTS 100000 // Maximum number of GPS data points to simulate

typedef struct {
    double latitude;
    double longitude;
} GPS_Coordinates;

typedef struct {
    double timestamp;
    GPS_Coordinates coordinates;
} GPS_DataPoint;

double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

double rad2deg(double rad) {
    return rad * 180.0 / M_PI;
}

double distance_between_coordinates(GPS_Coordinates coord1, GPS_Coordinates coord2) {
    double lat1 = deg2rad(coord1.latitude);
    double lon1 = deg2rad(coord1.longitude);
    double lat2 = deg2rad(coord2.latitude);
    double lon2 = deg2rad(coord2.longitude);
    
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    
    double a = pow(sin(dlat / 2.0), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return RADIUS * c;
}

int main() {
    GPS_DataPoint data[MAX_DATAPOINTS];
    int num_data_points = 0;
    
    // Simulate GPS data by randomly generating coordinates within a certain range.
    // We will simulate data for a car that is moving on a circular path of diameter 10KM.
    
    double center_lat = 37.7749;
    double center_lon = -122.4194;
    double radius = 5.0; // diameter is 10KM
    
    double rand_num;
    for (int i = 0; i < MAX_DATAPOINTS; i++) {
        rand_num = ((double) rand() / RAND_MAX) * 2 * M_PI; // angle between 0 and 2PI
        double lat = asin(sin(center_lat) * cos(radius / RADIUS) + cos(center_lat) * sin(radius / RADIUS) * cos(rand_num));
        double lon = center_lon + atan2(sin(rand_num) * sin(radius / RADIUS) * cos(center_lat), cos(radius / RADIUS) - sin(center_lat) * sin(lat));
        data[i].coordinates.latitude = rad2deg(lat);
        data[i].coordinates.longitude = rad2deg(lon);
        data[i].timestamp = i*0.2; // Time interval between two data points is 0.2 seconds
        num_data_points++;
    }
    
    // Calculate and print the total distance traveled by the car
    double total_distance = 0.0;
    for (int i = 0; i < num_data_points - 1; i++) {
        total_distance += distance_between_coordinates(data[i].coordinates, data[i+1].coordinates);
    }
    printf("Total distance traveled by the car: %.2f KM\n", total_distance);
    
    return 0;
}