//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371000 // Earth's radius in meters

double degreeToRadian(double degree) {
    return degree * M_PI / 180;
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = degreeToRadian(lat2 - lat1);
    double dLon = degreeToRadian(lon2 - lon1);
    
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(degreeToRadian(lat1)) * cos(degreeToRadian(lat2)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    double distance = EARTH_RADIUS * c;
    return distance;
}

typedef struct {
    double latitude;
    double longitude;
} Location;

int main() {
    Location currentLocation = {37.7749, -122.4194}; // San Francisco
    
    Location destination = {40.7128, -74.0060}; // New York City
    
    double distance = calculateDistance(currentLocation.latitude, currentLocation.longitude, destination.latitude, destination.longitude);
    
    printf("Distance between San Francisco and New York City is %1.0f meters\n", distance);
    
    // Now let's simulate GPS navigation
    
    double currentLatitude = currentLocation.latitude;
    double currentLongitude = currentLocation.longitude;
    
    int i = 1;
    while (distance > 1000) {
        double bearing = atan2(sin(degreeToRadian(destination.longitude - currentLongitude)) * cos(degreeToRadian(destination.latitude)),
                               cos(degreeToRadian(currentLatitude)) * sin(degreeToRadian(destination.latitude)) - sin(degreeToRadian(currentLatitude)) * cos(degreeToRadian(destination.latitude)) * cos(degreeToRadian(destination.longitude - currentLongitude)));
        
        double distanceToTravel = fmin(distance, 5000);
        
        double nextLatitude = asin(sin(degreeToRadian(currentLatitude)) * cos(distanceToTravel / EARTH_RADIUS) + cos(degreeToRadian(currentLatitude)) * sin(distanceToTravel / EARTH_RADIUS) * cos(bearing));
        double nextLongitude = degreeToRadian(currentLongitude) + atan2(sin(bearing) * sin(distanceToTravel / EARTH_RADIUS) * cos(degreeToRadian(currentLatitude)),
                                                                        cos(distanceToTravel / EARTH_RADIUS) - sin(degreeToRadian(currentLatitude)) * sin(nextLatitude));
        
        currentLatitude = nextLatitude * 180 / M_PI;
        currentLongitude = nextLongitude * 180 / M_PI;
        
        distance = calculateDistance(currentLatitude, currentLongitude, destination.latitude, destination.longitude);
        
        printf("Step %d: Travelled %1.0f meters. Current location: (%f, %f)\n", i++, distanceToTravel, currentLatitude, currentLongitude);
    }
    
    printf("Reached destination (%f, %f)\n", currentLatitude, currentLongitude);
    
    return 0;
}