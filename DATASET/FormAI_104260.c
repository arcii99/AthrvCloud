//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

struct location {
    double latitude;
    double longitude;
};

struct location convert_to_radians(struct location loc) {
    struct location convertedLoc;

    convertedLoc.latitude = loc.latitude * PI / 180;
    convertedLoc.longitude = loc.longitude * PI / 180;

    return convertedLoc;
}

double calculate_distance(struct location loc1, struct location loc2) {
    struct location loc1Rad = convert_to_radians(loc1);
    struct location loc2Rad = convert_to_radians(loc2);

    double latDiff = loc2Rad.latitude - loc1Rad.latitude;
    double lonDiff = loc2Rad.longitude - loc1Rad.longitude;

    double a = pow(sin(latDiff / 2), 2) + cos(loc1Rad.latitude) * cos(loc2Rad.latitude) * pow(sin(lonDiff / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c; // 6371 is the radius of the Earth in kilometers

    return distance;
}

int main() {
    struct location start;
    struct location end;

    printf("Enter the latitude and longitude of the starting point:\n");
    scanf("%lf %lf", &start.latitude, &start.longitude);

    printf("Enter the latitude and longitude of the ending point:\n");
    scanf("%lf %lf", &end.latitude, &end.longitude);

    double distance = calculate_distance(start, end);

    printf("The distance between the two points is %.2lf km.\n", distance);

    return 0;
}