//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LATITUDE_MAX 90
#define LATITUDE_MIN -90
#define LONGITUDE_MAX 180
#define LONGITUDE_MIN -180

typedef struct {
    float latitude;
    float longitude;
} Coordinate;

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    Time departure;
    Time arrival;
    Coordinate origin;
    Coordinate destination;
} Flight;

float generateRandomFloat(float min, float max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}

Coordinate generateRandomCoordinate() {
    Coordinate c;
    c.latitude = generateRandomFloat(LATITUDE_MIN, LATITUDE_MAX);
    c.longitude = generateRandomFloat(LONGITUDE_MIN, LONGITUDE_MAX);
    return c;
}

Time generateRandomTime() {
    Time t;
    t.hour = rand() % 24;
    t.minute = rand() % 60;
    return t;
}

void printCoordinate(Coordinate c) {
    printf("Latitude: %f, Longitude: %f\n", c.latitude, c.longitude);
}

void printTime(Time t) {
    printf("%d:%d\n", t.hour, t.minute);
}

void printFlight(Flight f) {
    printf("Departure Time: ");
    printTime(f.departure);
    printf("Arrival Time: ");
    printTime(f.arrival);
    printf("Origin: ");
    printCoordinate(f.origin);
    printf("Destination: ");
    printCoordinate(f.destination);
}

void simulateNavigation(Coordinate origin, Coordinate destination) {
    printf("Simulating navigation from ");
    printCoordinate(origin);
    printf("to ");
    printCoordinate(destination);
    printf("\n");
}

Flight createRandomFlight() {
    Flight f;
    f.departure = generateRandomTime();
    f.arrival = generateRandomTime();
    f.origin = generateRandomCoordinate();
    f.destination = generateRandomCoordinate();
    return f;
}

int main() {
    srand(time(NULL));

    Flight f1 = createRandomFlight();
    Flight f2 = createRandomFlight();
    Flight f3 = createRandomFlight();

    printf("Generated Flights:\n");
    printFlight(f1);
    printFlight(f2);
    printFlight(f3);

    printf("\n");

    printf("Simulating Navigation:\n");
    simulateNavigation(f1.origin, f1.destination);
    simulateNavigation(f2.origin, f2.destination);
    simulateNavigation(f3.origin, f3.destination);

    return 0;
}