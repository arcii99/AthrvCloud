//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define R 6371000 // Earth's radius in meters

double deg2rad(double deg) {
    return (deg * M_PI / 180);
}

double rad2deg(double rad) {
    return (rad * 180 / M_PI);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = deg2rad(lat2-lat1);
    double dlon = deg2rad(lon2-lon1);

    double a = pow(sin(dlat/2),2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * pow(sin(dlon/2),2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;

    return d;
}

void navigate(double start_lat, double start_lon, double end_lat, double end_lon) {
    double d = distance(start_lat, start_lon, end_lat, end_lon);
    double heading = atan2(sin(deg2rad(end_lon-start_lon)) * cos(deg2rad(end_lat)), cos(deg2rad(start_lat))*sin(deg2rad(end_lat))-sin(deg2rad(start_lat))*cos(deg2rad(end_lat))*cos(deg2rad(end_lon-start_lon)));
    printf("Distance: %f meters\n", d);
    printf("Heading: %f degrees\n", rad2deg(heading));
}

int main() {
    double start_lat = 37.7749;
    double start_lon = -122.4194;

    double end_lat = 40.7128;
    double end_lon = -74.0060;

    navigate(start_lat, start_lon, end_lat, end_lon);

    return 0;
}