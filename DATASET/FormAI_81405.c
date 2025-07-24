//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265359

struct location {
    int id;
    char name[50];
    double latitude;
    double longitude;
};

double toRadians(double degree) {
    return degree * PI / 180.0;
}

double getDistance(double latitude1, double longitude1, double latitude2, double longitude2) {
    double r = 6371;
    double lat1 = toRadians(latitude1);
    double lon1 = toRadians(longitude1);
    double lat2 = toRadians(latitude2);
    double lon2 = toRadians(longitude2);
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = r * c;
    return d;
}

int findNearestLocation(struct location locations[], int numLocations, double userLatitude, double userLongitude) {
    int nearestIndex = -1;
    double nearestDistance = INFINITY;
    for(int i=0; i<numLocations; i++) {
        double distance = getDistance(userLatitude, userLongitude, locations[i].latitude, locations[i].longitude);
        if(distance < nearestDistance) {
            nearestIndex = i;
            nearestDistance = distance;
        }
    }
    return nearestIndex;
}

int main() {
    // simulate user's current location
    double userLatitude = 23.8103;
    double userLongitude = 90.4125;

    // initialize locations
    struct location locations[5];
    locations[0].id = 1;
    strcpy(locations[0].name, "Dhaka University");
    locations[0].latitude = 23.7298;
    locations[0].longitude = 90.3944;

    locations[1].id = 2;
    strcpy(locations[1].name, "Jamuna Future Park");
    locations[1].latitude = 23.8153;
    locations[1].longitude = 90.4256;

    locations[2].id = 3;
    strcpy(locations[2].name, "National Parliament House");
    locations[2].latitude = 23.7772;
    locations[2].longitude = 90.3662;

    locations[3].id = 4;
    strcpy(locations[3].name, "Bangladesh Bank");
    locations[3].latitude = 23.732100;
    locations[3].longitude = 90.413370;

    locations[4].id = 5;
    strcpy(locations[4].name, "Hazrat Shahjalal International Airport");
    locations[4].latitude = 23.8428;
    locations[4].longitude = 90.4005;

    // find the nearest location
    int nearestIndex = findNearestLocation(locations, 5, userLatitude, userLongitude);
    struct location nearestLocation = locations[nearestIndex];

    // print the nearest location
    printf("Your current location is: (%lf, %lf)\n", userLatitude, userLongitude);
    printf("The nearest location is: %s (ID: %d)\n", nearestLocation.name, nearestLocation.id);

    return 0;
}