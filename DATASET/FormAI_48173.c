//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <math.h>

// function to calculate distance between two points using haversine formula
double distance(double lat1, double long1, double lat2, double long2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLong = (long2 - long1) * M_PI / 180.0;
    double a = pow(sin(dLat / 2), 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * pow(sin(dLong / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = 6371 * c;
    return d;
}

int main() {
    double lat, longi;  // current latitude and longitude
    double dest_lat, dest_longi;  // destination latitude and longitude
    char label[10];  // label of the destination
    
    // ask for current location
    printf("Enter your current latitude: ");
    scanf("%lf", &lat);
    printf("Enter your current longitude: ");
    scanf("%lf", &longi);
    
    // ask for destination
    printf("\nEnter the label of your destination: ");
    scanf("%s", label);
    printf("Enter the latitude of your destination: ");
    scanf("%lf", &dest_lat);
    printf("Enter the longitude of your destination: ");
    scanf("%lf", &dest_longi);
    
    // calculate distance and direction
    double dist = distance(lat, longi, dest_lat, dest_longi);
    double bearing = atan2(sin(dest_longi - longi) * cos(dest_lat), cos(lat) * sin(dest_lat) - sin(lat) * cos(dest_lat) * cos(dest_longi - longi)) * 180 / M_PI;
    
    // print results
    printf("\nDistance to %s: %.2f km", label, dist);
    printf("\nBearing to %s: %.2f degrees", label, bearing);
     
    return 0;
}