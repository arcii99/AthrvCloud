//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <math.h>

struct coordinates {
    double latitude;
    double longitude;
};

double distance(struct coordinates a, struct coordinates b) {
    double lat1 = a.latitude;
    double lon1 = a.longitude;
    double lat2 = b.latitude;
    double lon2 = b.longitude;
    double dLat = (lat2-lat1) * M_PI / 180.0;
    double dLon = (lon2-lon1) * M_PI / 180.0;
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    double a1 = sin(dLat/2) * sin(dLat/2) + 
                sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2); 
    double c = 2 * atan2(sqrt(a1), sqrt(1-a1)); 
    double R = 6371; // Earth's radius in km
    return R * c * 1000; // Distance in meters
}

int main() {
    struct coordinates home;
    home.latitude = 43.651070;
    home.longitude = -79.347015;

    struct coordinates work;
    work.latitude = 43.643515;
    work.longitude = -79.389264;

    struct coordinates school;
    school.latitude = 43.773056;
    school.longitude = -79.501389;

    double distance_to_work = distance(home, work);
    double distance_to_school = distance(home, school);

    printf("Distance from home to work: %.2lf meters\n", distance_to_work);
    printf("Distance from home to school: %.2lf meters\n", distance_to_school);

    return 0;
}