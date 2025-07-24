//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double latitude1, longitude1, latitude2, longitude2;
    double distance, bearing;
    char direction[4];

    printf("Welcome to our romantic GPS Navigation Simulation\n");
    printf("Let's begin with the first location: \n");
    printf("\nEnter the latitude of your current location: ");
    scanf("%lf", &latitude1);
    printf("Enter the longitude of your current location: ");
    scanf("%lf", &longitude1);

    printf("\nNow let's move on to your loved one's location:\n");
    printf("Enter the latitude of their location: ");
    scanf("%lf", &latitude2);
    printf("Enter the longitude of their location: ");
    scanf("%lf", &longitude2);

    distance = sqrt(pow(latitude2 - latitude1, 2) + pow(longitude2 - longitude1, 2));
    bearing = atan2((longitude2 - longitude1), (latitude2 - latitude1)) * 180 / M_PI;

    if (bearing >= 0 && bearing < 22.5) {
        sprintf(direction, "North");
    } else if (bearing >= 22.5 && bearing < 67.5) {
        sprintf(direction, "Northeast");
    } else if (bearing >= 67.5 && bearing < 112.5) {
        sprintf(direction, "East");
    } else if (bearing >= 112.5 && bearing < 157.5) {
        sprintf(direction, "Southeast");
    } else if (bearing >= 157.5 && bearing < 202.5) {
        sprintf(direction, "South");
    } else if (bearing >= 202.5 && bearing < 247.5) {
        sprintf(direction, "Southwest");
    } else if (bearing >= 247.5 && bearing < 292.5) {
        sprintf(direction, "West");
    } else if (bearing >= 292.5 && bearing < 337.5) {
        sprintf(direction, "Northwest");
    } else {
        sprintf(direction, "North");
    }

    printf("\n\nWe have successfully calculated the distance and bearing to their location!\n");

    printf("\n\nThe distance between us and our special someone is: %lf km", distance);
    printf("\n\nThe direction to them is: %s\n\n", direction);

    printf("I hope this romantic GPS Navigation Simulation was helpful...\n\n");
    printf("Happy travels!\n");
    return 0;
}