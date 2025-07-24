//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.00

struct Location {
    char name[50];
    double latitude;
    double longitude;
};

double toRadians(double degree) {
    return degree * PI / 180;
}

double calculateDistance(struct Location a, struct Location b) {
    double lat1 = toRadians(a.latitude);
    double lon1 = toRadians(a.longitude);
    double lat2 = toRadians(b.latitude);
    double lon2 = toRadians(b.longitude);

    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;

    double dist = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    dist = 2 * asin(sqrt(dist));

    dist = dist * EARTH_RADIUS;

    return dist;
}

void printRoute(int index, struct Location *route, int size) {
    if (index == 0) {
        printf("Starting Point: %s\n", route[index].name);
    } else {
        printf("From %s to %s. Distance: %.2f km\n", route[index - 1].name, route[index].name, calculateDistance(route[index - 1], route[index]));
    }

    if (index == size - 1) {
        printf("Destination: %s\n", route[index].name);
    }
}

int main() {
    struct Location cities[] = {
        {"San Francisco", 37.7749, -122.4194},
        {"Los Angeles", 34.0522, -118.2437},
        {"Chicago", 41.8781, -87.6298},
        {"New York", 40.7128, -74.0060},
        {"Boston", 42.3601, -71.0589},
        {"Atlanta", 33.7490, -84.3880},
        {"Miami", 25.7617, -80.1918},
        {"Washington DC", 38.9072, -77.0369},
        {"Houston", 29.7604, -95.3698},
        {"Seattle", 47.6062, -122.3321}
    };

    int numCities = sizeof(cities) / sizeof(cities[0]);

    printf("Welcome to GPS Navigation Simulation!\n");
    printf("We have %d cities in our database.\n", numCities);

    char source[50], destination[50];

    printf("Enter Starting Point: ");
    scanf("%[^\n]%*c", source);

    printf("Enter Destination: ");
    scanf("%[^\n]%*c", destination);

    int sourceIndex = -1;
    int destinationIndex = -1;

    for (int i = 0; i < numCities; i++) {
        if (strcmp(cities[i].name, source) == 0) {
            sourceIndex = i;
        }

        if (strcmp(cities[i].name, destination) == 0) {
            destinationIndex = i;
        }
    }

    if (sourceIndex == -1 || destinationIndex == -1) {
        printf("Invalid Source or Destination!\n");
        return 0;
    }

    printf("Calculating Route...\n");

    struct Location *route = (struct Location*) malloc(numCities * sizeof(struct Location));
    int routeIndex = -1;

    if (sourceIndex < destinationIndex) {
        for (int i = sourceIndex; i <= destinationIndex; i++) {
            routeIndex++;
            route[routeIndex] = cities[i];
        }
    } else {
        for (int i = sourceIndex; i >= destinationIndex; i--) {
            routeIndex++;
            route[routeIndex] = cities[i];
        }
    }

    int numStops = routeIndex + 1;

    printf("Your Route:\n");

    for (int i = 0; i < numStops; i++) {
        printRoute(i, route, numStops);
    }

    free(route);

    return 0;
}