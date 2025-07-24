//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structures */

typedef struct {
    double lat;
    double lon;
} point_t;

typedef struct {
    point_t p1;
    point_t p2;
    double distance;
    double bearing;
} route_t;

/* Define constants */

#define PI 3.14159265358979323846
#define EARTH_RADIUS_KM 6371.0

/* Define functions */

double to_radians(double degrees) {
    return degrees * PI / 180.0;
}

double to_degrees(double radians) {
    return radians * 180.0 / PI;
}

double great_circle_distance(point_t p1, point_t p2) {
    double lat1 = to_radians(p1.lat);
    double lon1 = to_radians(p1.lon);
    double lat2 = to_radians(p2.lat);
    double lon2 = to_radians(p2.lon);
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat/2.0)*sin(dlat/2.0) + cos(lat1)*cos(lat2)*sin(dlon/2.0)*sin(dlon/2.0);
    double c = 2.0*atan2(sqrt(a), sqrt(1.0 - a));
    return EARTH_RADIUS_KM*c;
}

double bearing(point_t p1, point_t p2) {
    double lat1 = to_radians(p1.lat);
    double lon1 = to_radians(p1.lon);
    double lat2 = to_radians(p2.lat);
    double lon2 = to_radians(p2.lon);
    double dlon = lon2 - lon1;
    double x = cos(lat2) * sin(dlon);
    double y = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon);
    double b = atan2(x, y);
    return b < 0.0 ? b + 2.0*PI : b;
}

point_t project(point_t p, double b, double d) {
    double lat = to_radians(p.lat);
    double lon = to_radians(p.lon);
    double dr = d / EARTH_RADIUS_KM;
    double lat1 = asin(sin(lat)*cos(dr) + cos(lat)*sin(dr)*cos(b));
    double lon1 = lon + atan2(sin(b)*sin(dr)*cos(lat), cos(dr)-sin(lat)*sin(lat1));
    return (point_t){to_degrees(lat1), to_degrees(lon1)};
}

/* Define the main function */

int main() {
    /* Define two points to calculate route */
    point_t p1 = (point_t){-22.9035, -43.2096};
    point_t p2 = (point_t){-23.5491, -46.9334};

    /* Calculate the route */
    double distance = great_circle_distance(p1, p2);
    double b = bearing(p1, p2);
    point_t p3 = project(p1, b, distance/2.0);
    route_t route = (route_t){p1, p2, distance, b};

    /* Output the calculated route */
    printf("Start Point: (%lf, %lf)\n", p1.lat, p1.lon);
    printf("End Point: (%lf, %lf)\n", p2.lat, p2.lon);
    printf("Distance: %lf km\n", distance);
    printf("Bearing: %lf degrees\n", to_degrees(b));
    printf("Mid-point: (%lf, %lf)\n", p3.lat, p3.lon);

    return 0;
}