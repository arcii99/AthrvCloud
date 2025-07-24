//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SPEED 120 // km/h
#define UPDATE_INTERVAL 5 // seconds
#define TURN_THRESHOLD 0.1 // km
#define ROUTE_FILE "route.txt"
#define DESTINATION_FILE "destination.txt"

typedef struct {
    float latitude;
    float longitude;
} coordinate_t;

typedef struct {
    coordinate_t origin;
    coordinate_t destination;
} route_t;

float calculate_distance(coordinate_t c1, coordinate_t c2) {
    float lat_diff = c2.latitude - c1.latitude;
    float lon_diff = c2.longitude - c1.longitude;
    float distance = sqrt(pow(lat_diff, 2) + pow(lon_diff, 2));
    return distance;
}

float calculate_time(float distance) {
    float time = distance / MAX_SPEED * 60; // convert to minutes
    return time;
}

void print_coordinate(coordinate_t c) {
    printf("%.5f,%.5f\n", c.latitude, c.longitude);
}

void load_route(route_t* route) {
    FILE* file = fopen(ROUTE_FILE, "r");
    if (file == NULL) {
        printf("Error: route file not found\n");
        exit(1);
    }
    fscanf(file, "%f,%f\n", &route->origin.latitude, &route->origin.longitude);
    fscanf(file, "%f,%f\n", &route->destination.latitude, &route->destination.longitude);
    fclose(file);
}

void save_destination(coordinate_t destination) {
    FILE* file = fopen(DESTINATION_FILE, "w");
    fprintf(file, "%.5f,%.5f\n", destination.latitude, destination.longitude);
    fclose(file);
}

void simulate_navigation() {
    route_t route;
    load_route(&route);
    print_coordinate(route.origin);
    coordinate_t current_location = route.origin;
    float total_distance = calculate_distance(route.origin, route.destination);
    float distance_left = total_distance;
    float time_elapsed = 0;
    printf("Navigating to destination...\n");
    while (distance_left > 0) {
        float distance_to_turn = distance_left * TURN_THRESHOLD;
        coordinate_t next_location = (distance_left <= distance_to_turn) ? route.destination : current_location;
        float distance_next = calculate_distance(current_location, next_location);
        float time_next = calculate_time(distance_next);
        distance_left -= distance_next;
        time_elapsed += time_next;
        current_location = next_location;
        print_coordinate(current_location);
        if (time_elapsed >= UPDATE_INTERVAL) {
            save_destination(current_location);
            printf("Updating destination...\n");
            time_elapsed = 0;
        }
    }
    printf("Destination reached!\n");
}

int main() {
    simulate_navigation();
    return 0;
}