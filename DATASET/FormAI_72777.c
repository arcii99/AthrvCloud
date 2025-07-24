//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: future-proof
#include <stdio.h>

//defining constants
#define LATITUDE 10.3837
#define LONGITUDE 63.2375
#define PI 3.14159265358979323846

//function to calculate distance between two points
double distanceCalculation(double lat1, double long1, double lat2, double long2) {
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLong = (long2 - long1) * PI / 180.0; 
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) * sin(dLong / 2) * sin(dLong / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a)); 
    double distance = 6371 * c; //where 6371 is the radius of the Earth in km
    return distance;
}

int main() {
    double latitude, longitude;
    printf("Welcome to GPS Navigation Simulation!\n\n");
    printf("Enter your current Latitude: ");
    scanf("%lf", &latitude);
    printf("Enter your current Longitude: ");
    scanf("%lf", &longitude);
    printf("\n\nYour current location is: (%lf, %lf)\n\n", latitude, longitude);
    double distance = distanceCalculation(latitude, longitude, LATITUDE, LONGITUDE);
    printf("Distance between your current location and the destination:\n%lf km\n", distance);
    printf("\n\nThank you for using GPS Navigation Simulation!\n");
    return 0;
}