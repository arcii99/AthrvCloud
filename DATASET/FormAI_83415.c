//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h> // Standard Input/Output library
#include <stdlib.h> // Standard Library functions
#include <math.h> // Math functions

#define PI 3.14159265359 // Define the value of pi

struct Coordinate { // Create a structure to hold the coordinates
    double latitude;
    double longitude;
};

double distance(struct Coordinate source, struct Coordinate destination) { // Function to calculate the distance between two coordinates
    double lat1 = source.latitude * PI / 180.0; // Convert latitude to radians
    double lon1 = source.longitude * PI / 180.0; // Convert longitude to radians
    double lat2 = destination.latitude * PI / 180.0; // Convert latitude to radians
    double lon2 = destination.longitude * PI / 180.0; // Convert longitude to radians
    double dlat = lat2 - lat1; // Calculate the difference between latitudes
    double dlon = lon2 - lon1; // Calculate the difference between longitudes
    double a = pow(sin(dlat / 2.0), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2.0), 2); // Calculate the value of 'a'
    double c = 2 * atan2(sqrt(a), sqrt(1 - a)); // Calculate the value of 'c'
    double distance = c * 6371.0; // Calculate the distance in kilometers
    return distance;
}

int main() {
    struct Coordinate current_location = {39.7392, -104.9903}; // Set current location to Denver, Colorado
    struct Coordinate destination = {40.7128, -74.0059}; // Set destination to New York City, NY
    double total_distance = distance(current_location, destination); // Calculate total distance between the two points
    printf("Total distance from Denver, CO to New York City, NY: %.2f km\n", total_distance); // Print the total distance
    return 0; // Exit the program
}