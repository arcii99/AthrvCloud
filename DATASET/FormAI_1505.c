//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    float lat;
    float lon;
} coordinate;

float distance(coordinate c1, coordinate c2) {
    float lat1 = c1.lat * M_PI / 180;
    float lat2 = c2.lat * M_PI / 180;
    float delta_lon = (c2.lon - c1.lon) * M_PI / 180;

    float R = 6371; // Earth's radius in km
    float d = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(delta_lon)) * R;

    return d;
}

coordinate random_coordinate(float min_lat, float max_lat, float min_lon, float max_lon) {
    coordinate c;
    c.lat = ((float) rand() / RAND_MAX) * (max_lat - min_lat) + min_lat;
    c.lon = ((float) rand() / RAND_MAX) * (max_lon - min_lon) + min_lon;
    return c;
}

int main() {
    srand(time(NULL));
    coordinate starting_point;
    starting_point.lat = 40.7128;
    starting_point.lon = -74.0060;

    float final_distance = 0;
    int count = 1;

    while (final_distance < 100) {
        coordinate next_point = random_coordinate(starting_point.lat - 0.5, starting_point.lat + 0.5, starting_point.lon - 0.5, starting_point.lon + 0.5);
        printf("Step %d: Go to (%f, %f)\n", count, next_point.lat, next_point.lon);
        float step_distance = distance(starting_point, next_point);
        final_distance += step_distance;
        starting_point = next_point;
        count++;
    }

    printf("Goal reached! You have travelled %.2f km\n", final_distance);
    return 0;
}