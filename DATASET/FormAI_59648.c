//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

//Struct for storing coordinates
struct Coordinate {
    double latitude;
    double longitude;
};

//Function to simulate GPS navigation
void simulateGPSNavigation(struct Coordinate start, struct Coordinate end, double distanceInterval) {
    double headingInDegree; //Heading in degree
    double headingInRadian; //Heading in radian
    double distance; //Distance between start and end location
    double currentDistance = 0; //Current distance travelled
    double currentLatitude = start.latitude; //Current latitude position
    double currentLongitude = start.longitude; //Current longitude position
    
    //Calculate heading from start to end location
    if (end.latitude == start.latitude) {
        headingInDegree = (end.longitude > start.longitude) ? 90.0 : 270.0;
    } else if (end.longitude == start.longitude) {
        headingInDegree = (end.latitude > start.latitude) ? 0.0 : 180.0;
    } else {
        double x1 = start.longitude * cos(end.latitude);
        double x2 = end.longitude * cos(start.latitude);
        double y1 = start.latitude;
        double y2 = end.latitude;
        double angle = atan2(y2 - y1, x2 - x1) * 180 / PI;
        if (angle < 0) {
            headingInDegree = 360 + angle;
        } else {
            headingInDegree = angle;
        }
    }
    
    //Convert heading to radian
    headingInRadian = headingInDegree * PI / 180.0;
    
    //Calculate distance between start and end location
    double lat1 = start.latitude * PI / 180.0;
    double lon1 = start.longitude * PI / 180.0;
    double lat2 = end.latitude * PI / 180.0;
    double lon2 = end.longitude * PI / 180.0;
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = 6371 * c;
    
    //Keep moving until reaching the end location
    while (currentDistance < distance) {
        currentLatitude += distanceInterval * cos(headingInRadian) / 111.319;
        currentLongitude += distanceInterval * sin(headingInRadian) / (111.319 * cos(start.latitude * PI / 180.0));
        currentDistance = sqrt(pow(currentLatitude - start.latitude, 2) + pow(currentLongitude - start.longitude, 2)) * 111.319;
        
        //Print current location
        printf("Current location: (%lf, %lf)\n", currentLatitude, currentLongitude);
    }
}

int main() {
    struct Coordinate start = {47.620506, -122.349277};
    struct Coordinate end = {47.661405, -122.342125};
    double distanceInterval = 0.1;
    
    printf("Start location: (%lf, %lf)\n", start.latitude, start.longitude);
    printf("End location: (%lf, %lf)\n", end.latitude, end.longitude);
    printf("Distance interval: %lf km\n", distanceInterval);
    
    simulateGPSNavigation(start, end, distanceInterval);
    
    return 0;
}