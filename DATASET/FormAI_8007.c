//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define EARTH_RADIUS 6371 // Earth radius in km

struct Location{
    double latitude;
    double longitude;
};

double toRadians(double degree) {
    return degree * (3.1415926536 / 180);
}

double distanceBetweenLocations(struct Location loc1, struct Location loc2) {
    double lat1 = toRadians(loc1.latitude);
    double lat2 = toRadians(loc2.latitude);
    double long1 = toRadians(loc1.longitude);
    double long2 = toRadians(loc2.longitude);

    double dlon = long2 - long1;
    double dlat = lat2 - lat1;

    double a = (sin(dlat / 2) * sin(dlat / 2)) + cos(lat1) * cos(lat2) * (sin(dlon / 2) * sin(dlon / 2));
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

void navigate(struct Location destination) {
    struct Location current = {40.7595, -73.9840}; // Start location (New York City)

    double distance = distanceBetweenLocations(current, destination);

    if (distance < 1) {
        printf("You have arrived at your destination.\n");
        return;
    }

    printf("Your current location: %f, %f\n", current.latitude, current.longitude);
    printf("Destination: %f, %f (%f km away)\n", destination.latitude, destination.longitude, distance);
    printf("Enter a direction (N, S, E, W): ");

    char dir;
    scanf(" %c", &dir);
    dir = toupper(dir);

    double latChange = 0, longChange = 0;

    switch (dir) {
        case 'N':
            latChange += 0.001;
            break;
        case 'S':
            latChange -= 0.001;
            break;
        case 'E':
            longChange += 0.001;
            break;
        case 'W':
            longChange -= 0.001;
            break;
        default:
            printf("Invalid direction.\n");
            navigate(destination);
            return;
    }

    struct Location newLocation = {current.latitude + latChange, current.longitude + longChange};

    navigate(destination);
}

int main() {
    struct Location destination = {41.8781, -87.6298}; // Destination location (Chicago)

    navigate(destination);

    return 0;
}