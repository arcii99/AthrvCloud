//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

int main() {
    int current_location; // initializing variable for current location
    int destination; // initializing variable for destination
    int distance; // initializing variable for distance
    int fuel_efficiency; // initializing variable for fuel efficiency
    int fuel_remaining; // initializing variable for fuel remaining

    printf("Welcome to GPS Navigation Simulation\n");

    // Taking input for current location, destination, fuel efficiency and fuel remaining from user
    printf("Enter the current location: ");
    scanf("%d", &current_location);

    printf("Enter the destination: ");
    scanf("%d", &destination);

    printf("Enter the fuel efficiency (in km/L): ");
    scanf("%d", &fuel_efficiency);

    printf("Enter the fuel remaining (in Litres): ");
    scanf("%d", &fuel_remaining);

    // Calculating the distance between source and destination
    distance = abs(destination - current_location);

    // Calculating the required fuel for the trip
    float required_fuel = (float)distance / fuel_efficiency;

    // Checking if the fuel is enough for the trip
    if (required_fuel <= fuel_remaining) {
        printf("You have enough fuel to make the trip\n");
        printf("Distance to be covered: %d km\n", distance);
        printf("Fuel required: %.2f L\n", required_fuel);
    }
    else {
        printf("You do not have enough fuel to make the trip\n");
        printf("You need to refuel before continuing\n");
    }

    return 0;
}