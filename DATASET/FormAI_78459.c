//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

#define R 6371000 // Earth radius in meters

struct position {
    double latitude;
    double longitude;
};

double rad(double degree) {
    return degree * (M_PI / 180);
}

double distance(struct position pos1, struct position pos2) {
    double lat1 = rad(pos1.latitude);
    double lon1 = rad(pos1.longitude);
    double lat2 = rad(pos2.latitude);
    double lon2 = rad(pos2.longitude);
    
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return R * c;
}

int main() {
    struct position current = {51.507222, -0.127647}; // London, UK
    struct position destination = {48.856614, 2.352222}; // Paris, France
    
    double distance_to_destination = distance(current, destination);
    
    printf("Distance to destination: %f meters\n", distance_to_destination);
    
    return 0;
}