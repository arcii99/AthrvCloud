//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate distance between two points using the distance formula
double find_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Main function
int main() {
    double signal_strength_1, signal_strength_2;
    double distance_1, distance_2;
    double x1 = 10.0, y1 = 5.0; // coordinates of first access point
    double x2 = 20.0, y2 = 10.0; // coordinates of second access point

    // Read in signal strengths from user for both access points
    printf("Enter signal strength for Access Point 1: ");
    scanf("%lf", &signal_strength_1);
    printf("Enter signal strength for Access Point 2: ");
    scanf("%lf", &signal_strength_2);

    // Calculate distances from each access point using signal strength and distance formula
    distance_1 = pow(10, (signal_strength_1 - 20) / 20); // formula from signal strength to distance in meters
    distance_2 = pow(10, (signal_strength_2 - 20) / 20);

    // Calculate user's location using trilateration
    double x = (pow(distance_1, 2) - pow(distance_2, 2) + pow(x2, 2) - pow(x1, 2)) / (2 * (x2 - x1));
    double y = (pow(distance_1, 2) - pow(distance_2, 2) + pow(y2, 2) - pow(y1, 2)) / (2 * (y2 - y1));

    // Print out user's location
    printf("User's location is (%.2lf, %.2lf)\n", x, y);

    return 0;
}