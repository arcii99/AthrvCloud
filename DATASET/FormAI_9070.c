//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to calculate distance between two coordinates using Haversine formula
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371; // Earth's radius in km
    double dLat = (lat2 - lat1) * M_PI / 180;
    double dLon = (lon2 - lon1) * M_PI / 180;
    
    double a = sin(dLat/2) * sin(dLat/2) +
               cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) *
               sin(dLon/2) * sin(dLon/2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;
    
    return d;
}

// Function to generate random GPS coordinates
void generateCoordinates(double* lat, double* lon) {
    double minLat = 25.000000;
    double maxLat = 40.000000;
    double minLon = -120.000000;
    double maxLon = -80.000000;
    
    *lat = (double)(rand() % (int)((maxLat - minLat) * 1000000)) / 1000000.0 + minLat;
    *lon = (double)(rand() % (int)((maxLon - minLon) * 1000000)) / 1000000.0 + minLon;
}

int main() {
    srand(time(NULL)); // Initialize random seed
    
    double currentLat = 30.000000; // Starting latitude
    double currentLon = -90.000000; // Starting longitude
    
    double destLat, destLon;
    generateCoordinates(&destLat, &destLon); // Generate random destination coordinates
    
    printf("Destination coordinates: (%f,%f)\n", destLat, destLon);
    
    double distance = calculateDistance(currentLat, currentLon, destLat, destLon);
    printf("Distance to destination: %f km\n", distance);
    
    while (distance > 0.1) { // Keep moving until close enough to destination
        double angle = (double)(rand() % 360); // Choose a random direction
        
        double speed = (double)(rand() % 60) / 10.0 + 20.0; // Choose a random speed between 20 and 26 km/h
        
        double d = speed / 3600.0; // Calculate distance moved in seconds
        
        double lat = currentLat + d * cos(angle * M_PI / 180); // Calculate new latitude
        double lon = currentLon + d * sin(angle * M_PI / 180); // Calculate new longitude
        
        distance = calculateDistance(lat, lon, destLat, destLon); // Calculate distance to destination
        
        printf("Moved to coordinates: (%f,%f)\n", lat, lon);
        
        currentLat = lat; // Update current latitude
        currentLon = lon; // Update current longitude
        
        printf("Distance to destination: %f km\n", distance);
    }
    
    printf("Arrived at destination!\n");
    
    return 0;
}