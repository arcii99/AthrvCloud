//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct Location {
    double latitude;
    double longitude;
};

struct Navigation {
    struct Location currentLocation;
    struct Location destination;
    double distance;
    double bearing;
};

double degreeToRadian(double degree) {
    return degree * (3.14159265358979323846/180);
}

double getDistance(struct Location loc1, struct Location loc2) {
    double R = 6371; // Radius of Earth in km
    double lat1 = degreeToRadian(loc1.latitude);
    double lat2 = degreeToRadian(loc2.latitude);
    double deltaLat = degreeToRadian(loc2.latitude - loc1.latitude);
    double deltaLon = degreeToRadian(loc2.longitude - loc1.longitude);
    
    double a = sin(deltaLat/2) * sin(deltaLat/2) +
               cos(lat1) * cos(lat2) *
               sin(deltaLon/2) * sin(deltaLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;
    
    return d;
}

double getBearing(struct Location loc1, struct Location loc2) {
    double lat1 = degreeToRadian(loc1.latitude);
    double lat2 = degreeToRadian(loc2.latitude);
    double deltaLon = degreeToRadian(loc2.longitude - loc1.longitude);

    double y = sin(deltaLon) * cos(lat2);
    double x = cos(lat1) * sin(lat2) -
               sin(lat1) * cos(lat2) * cos(deltaLon);
    double brng = atan2(y, x);
    brng = brng * (180/3.14159265358979323846);
    brng = fmod((brng + 360), 360);

    return brng;
}

void printLocation(struct Location location) {
    printf("(%f, %f)", location.latitude, location.longitude);
}

void printNavigation(struct Navigation navigation) {
    printf("+----------------------------------------+\n");
    printf("|             GPS Navigation              |\n");
    printf("+----------------------------------------+\n");
    printf("| Current Location: ");
    printLocation(navigation.currentLocation);
    printf("                    |\n");
    printf("| Destination:      ");
    printLocation(navigation.destination);
    printf("                    |\n");
    printf("| Distance:         %f km               |\n", navigation.distance);
    printf("| Bearing:          %f deg             |\n", navigation.bearing);
    printf("+----------------------------------------+\n");
}

int main() {
    struct Navigation navigation;
    navigation.currentLocation.latitude = 40.7128;
    navigation.currentLocation.longitude = -74.0060;
    navigation.destination.latitude = 37.7749;
    navigation.destination.longitude = -122.4194;

    navigation.distance = getDistance(navigation.currentLocation, navigation.destination);
    navigation.bearing = getBearing(navigation.currentLocation, navigation.destination);

    printNavigation(navigation);

    return 0;
}