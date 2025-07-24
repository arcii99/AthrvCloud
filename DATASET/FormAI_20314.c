//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multivariable
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double calcDistance(double lat1, double long1, double lat2, double long2) {
    double r = 6371; // Earth's radius in km
    double latDiff = (lat2 - lat1) * M_PI / 180.0;
    double longDiff = (long2 - long1) * M_PI / 180.0;
    double a = sin(latDiff / 2) * sin(latDiff / 2) +
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
               sin(longDiff / 2) * sin(longDiff / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = r * c;
    return d;
}

int main() {
    double startLat, startLong, destLat, destLong;
    printf("Enter the starting latitude and longitude in degrees:\n");
    scanf("%lf%lf", &startLat, &startLong);
    printf("Enter the destination latitude and longitude in degrees:\n");
    scanf("%lf%lf", &destLat, &destLong);
    
    // Calculate the distance between the starting and destination points
    double distance = calcDistance(startLat, startLong, destLat, destLong);
    printf("The distance between the two points is %.2lf km.\n", distance);

    // Generate a random speed between 50 and 100 km/h
    double speed = (rand() % 51) + 50;
    printf("Your vehicle is moving at %.2lf km/h.\n\n", speed);

    // Calculate the estimated time of arrival
    double time = distance / speed;
    int hours = (int) time;
    int minutes = (int) ((time - hours) * 60);
    printf("Your estimated time of arrival is in %d hours and %d minutes.\n", hours, minutes);
    
    return 0;
}