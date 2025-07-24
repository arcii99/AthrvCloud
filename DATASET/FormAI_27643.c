//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include<stdio.h>
#include<math.h>

//Radius of Earth in km
#define R 6371

//Structure to hold latitude and longitude coordinates
struct Coord{
    double lat;
    double lon;
};

double degToRad(double deg) {
    return deg * (M_PI/180);
}

double getDistance(struct Coord coord1, struct Coord coord2) {
    double dLat = degToRad(coord2.lat - coord1.lat);
    double dLon = degToRad(coord2.lon - coord1.lon);

    double a = sin(dLat/2) * sin(dLat/2) +
                cos(degToRad(coord1.lat)) * cos(degToRad(coord2.lat)) *
                sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c;

    return distance;
}

void navigate(struct Coord coords[], int limit, struct Coord target) {
    double minDistance = 999999999;
    int closestIndex;

    //Find the closest coordinate to the target
    for(int i=0; i<limit; i++) {
        double distance = getDistance(coords[i], target);
        if(distance < minDistance) {
            minDistance = distance;
            closestIndex = i;
        }
    }

    printf("Current Location: %.2f,%.2f\n", coords[closestIndex].lat, coords[closestIndex].lon);

    //Navigate to the target by finding the closest coordinate to target from current position
    while(getDistance(coords[closestIndex], target) > 0.1) {
        double minDistance2 = 999999999;
        int closestIndex2 = closestIndex;

        for(int i=0; i<limit; i++) {
            double distance = getDistance(coords[i], target);
            if(distance < minDistance2) {
                minDistance2 = distance;
                closestIndex2 = i;
            }
        }

        if(closestIndex == closestIndex2) {
            printf("You have reached a dead end!\n");
            break;
        }

        closestIndex = closestIndex2;
        printf("Navigate to: %.2f,%.2f\n", coords[closestIndex].lat, coords[closestIndex].lon);
    }

    if(getDistance(coords[closestIndex], target) <= 0.1) {
        printf("You have reached your destination! %.2f,%.2f", target.lat, target.lon);
    }
}

int main() {
    struct Coord coords[] = {
        {37.7749, -122.4194}, //San Francisco
        {34.0522, -118.2437}, //Los Angeles
        {40.7128, -74.0060}, //New York
        {51.5074, -0.1278}, //London
        {-33.8688, 151.2093} //Sydney
    };

    struct Coord target = {
        37.7909, -122.3925 //Pier 39, San Francisco
    };

    int limit = sizeof(coords) / sizeof(coords[0]);

    navigate(coords, limit, target);

    return 0;
}