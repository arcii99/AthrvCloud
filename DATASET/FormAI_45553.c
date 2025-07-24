//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Location{
    double lat;
    double lon;
};

double toRadians(double degrees){
    return degrees * (M_PI / 180);
}

double calcDistance(struct Location a, struct Location b){
    double dlat = toRadians(b.lat-a.lat);
    double dlon = toRadians(b.lon-a.lon);
    double R = 6371e3; // Earth's mean radius in meters
    double lat1 = toRadians(a.lat);
    double lat2 = toRadians(b.lat);
    double deltaLat = toRadians(b.lat-a.lat);
    double deltaLon = toRadians(b.lon-a.lon);
    
    double y = sin(deltaLon) * cos(lat2);
    double x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(deltaLon);
    double bearing = atan2(y, x);
    
    double a1 = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c1 = 2 * atan2(sqrt(a1), sqrt(1-a1));
    
    double distance = R * c1;
    
    return distance;
}

void navigate(struct Location start, struct Location end){
    double distance = calcDistance(start, end);
    printf("Distance: %.2lf meters\n", distance);
    double speed = 20.0; // in meters per second
    double travelTime = distance / speed;
    printf("Travel time: %.2lf seconds\n", travelTime);
}

int main(){
    struct Location start, end;
    start.lat = 40.748817;
    start.lon = -73.985428;
    end.lat = 37.774929;
    end.lon = -122.419416;
    navigate(start, end);
    return 0;
}