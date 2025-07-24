//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_LOCATIONS 50

typedef struct {
    double lat;
    double lon;
} location_t;

location_t locations[MAX_LOCATIONS];

double calculate_distance(location_t loc1, location_t loc2) {
    double R = 6371e3; // Earth's radius in meters
    double lat1 = loc1.lat * M_PI / 180;
    double lat2 = loc2.lat * M_PI / 180;
    double delta_lat = (loc2.lat - loc1.lat) * M_PI / 180;
    double delta_lon = (loc2.lon - loc1.lon) * M_PI / 180;

    double a = sin(delta_lat / 2) * sin(delta_lat / 2)
                + cos(lat1) * cos(lat2) * sin(delta_lon / 2) * sin(delta_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = R * c;
    return d;
}

void generate_locations() {
    srand(time(NULL));
    for(int i = 0; i < MAX_LOCATIONS; i++) {
        locations[i].lat = (double)rand() / RAND_MAX * 180 - 90;  // Latitude ranges from -90 to 90 degrees
        locations[i].lon = (double)rand() / RAND_MAX * 360 - 180; // Longitude ranges from -180 to 180 degrees
    }
}

int main() {
    generate_locations();

    int start, end;
    printf("Enter a starting location (0-49): ");
    scanf("%d", &start);
    printf("Enter a destination location (0-49): ");
    scanf("%d", &end);

    if(start < 0 || start >= MAX_LOCATIONS || end < 0 || end >= MAX_LOCATIONS) {
        printf("Invalid location number\n");
        return 1;
    }

    printf("Starting location: %lf, %lf\n", locations[start].lat, locations[start].lon);
    printf("Destination location: %lf, %lf\n", locations[end].lat, locations[end].lon);
    printf("Distance between locations: %lf meters\n", calculate_distance(locations[start], locations[end]));

    return 0;
}