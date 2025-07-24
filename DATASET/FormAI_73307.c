//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Donald Knuth
#include<stdio.h>
#include<math.h>

// Function to calculate distance between two points
double distance(double lat1, double long1, double lat2, double long2) {

    // Convert degrees to radians
    double rad_lat1 = M_PI/180.0 * lat1;
    double rad_long1 = M_PI/180.0 * long1;
    double rad_lat2 = M_PI/180.0 * lat2;
    double rad_long2 = M_PI/180.0 * long2;

    // Calculate difference in latitudes and longitudes
    double dlat = rad_lat2 - rad_lat1;
    double dlon = rad_long2 - rad_long1;

    // Apply haversine formula
    double a = sin(dlat/2) * sin(dlat/2) + cos(rad_lat1) * cos(rad_lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = 6371 * c;

    return distance;
}

int main() {
    double starting_lat, starting_long, ending_lat, ending_long;

    printf("Enter starting latitude: ");
    scanf("%lf", &starting_lat);

    printf("Enter starting longitude: ");
    scanf("%lf", &starting_long);

    printf("Enter ending latitude: ");
    scanf("%lf", &ending_lat);

    printf("Enter ending longitude: ");
    scanf("%lf", &ending_long);

    double distance_between = distance(starting_lat, starting_long, ending_lat, ending_long);

    printf("The distance between the two points is: %lf kilometers\n", distance_between);

    return 0;
}