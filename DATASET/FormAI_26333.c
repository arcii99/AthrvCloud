//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

// Function to calculate distance between two GPS coordinates
double distance(double lat1, double lon1, double lat2, double lon2) {
    double a, c, dLat, dLon, d;
    
    dLat = (lat2-lat1) * PI/180.0;
    dLon = (lon2-lon1) * PI/180.0;
    lat1 = lat1 * PI/180.0;
    lat2 = lat2 * PI/180.0;
    
    a = sin(dLat/2) * sin(dLat/2) + sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = 6371 * c;
    
    return d;
}

// Function to simulate GPS navigation
void gpsNavigation(double startLat, double startLon, double endLat, double endLon) {
    double currentLat = startLat;
    double currentLon = startLon;
    double bearing, distanceToGo;
    int numTurns = 0;
    
    printf("Starting GPS navigation from (%lf, %lf) to (%lf, %lf)\n", startLat, startLon, endLat, endLon);
    
    while(distance(currentLat, currentLon, endLat, endLon) > 0.01) {  // Keep navigating until distance is less than 10m
        
        bearing = atan2(sin(endLon-currentLon)*cos(endLat),
                        cos(currentLat)*sin(endLat)-sin(currentLat)*cos(endLat)*cos(endLon-currentLon));
        
        distanceToGo = distance(currentLat, currentLon, endLat, endLon);
        currentLat += 0.0001 * cos(bearing);
        currentLon += 0.0001 * sin(bearing) / cos(currentLat);
        
        if(distanceToGo < 1000 && numTurns == 0) {
            printf("Take a right turn ahead.\n");
            numTurns++;
        }
        if(distanceToGo < 500 && numTurns == 1) {
            printf("Take a left turn ahead.\n");
            numTurns++;
        }
        if(distanceToGo < 200 && numTurns == 2) {
            printf("Destination is just ahead. You have arrived.\n");
            break;
        }
    }
}

int main() {
    gpsNavigation(37.7750, -122.4183, 37.7833, -122.4167);
    return 0;
}