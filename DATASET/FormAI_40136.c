//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the struct for holding location information */
typedef struct {
    int x;
    int y;
} Location;

/* Declare the functions */
int getDistance(Location current, Location destination);
void navigate(Location current, Location destination);

/* The main function */
int main() {
    srand(time(NULL));

    /* Define the current location and the destination */
    Location current;
    current.x = rand() % 100;
    current.y = rand() % 100;

    Location destination;
    destination.x = rand() % 100;
    destination.y = rand() % 100;

    printf("Current location: (%d, %d)\n", current.x, current.y);
    printf("Destination: (%d, %d)\n", destination.x, destination.y);

    navigate(current, destination);

    return 0;
}

/* The function for getting the distance between two locations */
int getDistance(Location current, Location destination) {
    int xDiff = destination.x - current.x;
    int yDiff = destination.y - current.y;
    return abs(xDiff) + abs(yDiff);
}

/* The function for navigating from the current location to the destination */
void navigate(Location current, Location destination) {
    int distance = getDistance(current, destination);

    /* If the current location is the same as the destination, End of Navigation */
    if (distance == 0) {
        printf("You reached your destination!");
        return;
    }

    printf("Distance to destination: %d\n", distance);

    printf("Navigate to the ");

    /* Determine the direction based on the current and destination location */
    if (destination.y > current.y) {
        printf("North");
        current.y++;
    } else if (destination.y < current.y) {
        printf("South");
        current.y--;
    }

    if (destination.x > current.x) {
        printf("East");
        current.x++;
    } else if (destination.x < current.x) {
        printf("West");
        current.x--;
    }

    printf(".\n");

    /* Recurse until the destination is reached */
    navigate(current, destination);
}