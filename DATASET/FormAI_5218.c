//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

double calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371.0; // Earth's radius in km
    double dlat = (lat2 - lat1) * M_PI / 180.0;
    double dlon = (lon2 - lon1) * M_PI / 180.0;
    double a = pow(sin(dlat / 2), 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

int main() {
    // GPS coordinates of starting and ending point
    double start_lat = 37.7749;
    double start_lon = -122.4194;
    double end_lat = 40.7128;
    double end_lon = -74.0060;

    double distance = calculate_distance(start_lat, start_lon, end_lat, end_lon);

    printf("Distance between San Francisco and New York City is %.2lf km.\n", distance);

    return 0;
}