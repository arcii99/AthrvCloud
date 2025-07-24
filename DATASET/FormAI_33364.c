//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize GPS coordinates
struct GPS {
    float x;
    float y;
};

// Simulate vehicle's current GPS coordinate
struct GPS simulateVehicleLocation() {
    struct GPS vehicleLocation;
    vehicleLocation.x = (float)(rand() % 100);
    vehicleLocation.y = (float)(rand() % 100);
    return vehicleLocation;
}

// Calculate distance between two GPS coordinates
float calculateDistance(struct GPS source, struct GPS destination) {
    float dx = source.x - destination.x;
    float dy = source.y - destination.y;
    float distance = sqrt(dx * dx + dy * dy);
    return distance;
}

int main() {
    // Seed random number generator
    srand(time(0));

    // Define source and destination GPS coordinates
    struct GPS source, destination;
    printf("Enter source GPS coordinate (x y): ");
    scanf("%f %f", &source.x, &source.y);
    printf("Enter destination GPS coordinate (x y): ");
    scanf("%f %f", &destination.x, &destination.y);

    // Simulate vehicle's current GPS location
    struct GPS vehicleLocation = simulateVehicleLocation();
    printf("Vehicle is at GPS coordinate (%.2f, %.2f)\n", vehicleLocation.x, vehicleLocation.y);

    // Calculate distance from vehicle to destination
    float distance = calculateDistance(vehicleLocation, destination);
    printf("Distance from vehicle to destination is %.2f\n", distance);

    // Simulate vehicle's movement towards destination
    while (distance > 0.0) {
        // Determine direction towards destination
        float dx = destination.x - vehicleLocation.x;
        float dy = destination.y - vehicleLocation.y;
        float direction = atan2(dy, dx);

        // Move vehicle a random distance in that direction
        float movement = (float)(rand() % 10);
        vehicleLocation.x += movement * cos(direction);
        vehicleLocation.y += movement * sin(direction);

        // Calculate new distance from vehicle to destination
        distance = calculateDistance(vehicleLocation, destination);
        printf("Vehicle is now at GPS coordinate (%.2f, %.2f).\nDistance to destination is %.2f\n", 
                        vehicleLocation.x, vehicleLocation.y, distance);
    }

    printf("Vehicle has reached destination at GPS coordinate (%.2f, %.2f)!\n", 
                    vehicleLocation.x, vehicleLocation.y);

    return 0;
}