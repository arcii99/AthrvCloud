//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MIN_LATITUDE -90.0
#define MAX_LATITUDE 90.0
#define MIN_LONGITUDE -180.0
#define MAX_LONGITUDE 180.0

#define GPS_PRECISION_DEGREES 6

double randomDoubleInRange(double min, double max);
double simulateGPS(double currentLatitude, double currentLongitude);

int main(void)
{
    double currentLatitude = 37.773972;
    double currentLongitude = -122.431297;

    printf("Starting GPS simulation\n");
    printf("Current Latitude: %.*f\n", GPS_PRECISION_DEGREES, currentLatitude);
    printf("Current Longitude: %.*f\n", GPS_PRECISION_DEGREES, currentLongitude);

    for (int i = 0; i < 10; i++) {
        double simulatedLatitude = simulateGPS(currentLatitude, currentLongitude);
        double simulatedLongitude = simulateGPS(currentLongitude, currentLatitude);

        printf("New Latitude: %.*f\n", GPS_PRECISION_DEGREES, simulatedLatitude);
        printf("New Longitude: %.*f\n", GPS_PRECISION_DEGREES, simulatedLongitude);

        currentLatitude = simulatedLatitude;
        currentLongitude = simulatedLongitude;
    }

    printf("GPS simulation complete\n");
    return EXIT_SUCCESS;
}

double simulateGPS(double currentValue, double currentOtherValue)
{
    double newValue = currentValue + randomDoubleInRange(-0.00025, 0.00025);
    if (newValue < MIN_LATITUDE || newValue > MAX_LATITUDE) {
        // If the new value is outside the valid range, wrap around to the other side of the globe.
        newValue = (currentValue < 0) ? MAX_LATITUDE : MIN_LATITUDE;
    }
    return newValue;
}

double randomDoubleInRange(double min, double max)
{
    double range = max - min;
    double randomValue = ((double) rand() / RAND_MAX) * range + min;
    return randomValue;
}