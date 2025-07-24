//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define MAX_INPUT_LEN 50

struct Location {
    char name[MAX_INPUT_LEN];
    double latitude;
    double longitude;
};

struct Route {
    struct Location* start;
    struct Location* end;
    double distance;
};

struct Location* locations[MAX_LOCATIONS];
int idx_locations = 0;

int get_location_idx(char* name) {	// search index of location by name
    for (int i = 0; i < idx_locations; i++) {
        if (strcmp(locations[i]->name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void add_location(char* name, double lat, double lon) {	// add location
    struct Location* loc = malloc(sizeof(struct Location));
    strcpy(loc->name, name);
    loc->latitude = lat;
    loc->longitude = lon;

    locations[idx_locations++] = loc;
}

void add_route(char* start_name, char* end_name) {	// add route by two locations
    int start_idx = get_location_idx(start_name);
    int end_idx = get_location_idx(end_name);

    if ((start_idx != -1) && (end_idx != -1)) {
        struct Route* route = malloc(sizeof(struct Route));
        route->start = locations[start_idx];
        route->end = locations[end_idx];
        route->distance = sqrt(pow((route->start->latitude - route->end->latitude), 2) + pow((route->start->longitude - route->end->longitude), 2));

        printf("Route from %s to %s added successfully!\n", start_name, end_name);
    }
}

void shape_shift(double degrees) {	//run on shape shift command
    for (int i = 0; i < idx_locations; i++) {
        double temp_lat = locations[i]->latitude;
        double temp_lon = locations[i]->longitude;

        locations[i]->latitude = temp_lat * cos(degrees) - temp_lon * sin(degrees);
        locations[i]->longitude = temp_lat * sin(degrees) + temp_lon * cos(degrees);
    }
}

int main() {
    printf("Welcome to the GPS Navigation System.\n");

    printf("Adding locations...\n");
    add_location("London", 51.5072, -0.1276);
    add_location("Paris", 48.8566, 2.3522);
    add_location("Rome", 41.9028, 12.4964);
    add_location("Berlin", 52.5200, 13.4050);
    add_location("Amsterdam", 52.3676, 4.9041);
    printf("All locations added successfully.\n");

    char input[MAX_INPUT_LEN];
    bool terminate = false;

    while (!terminate) {
        printf("Enter command: ");
        fgets(input, MAX_INPUT_LEN, stdin);

        if (strncmp(input, "add route", 9) == 0) {	// add route command
            char start[MAX_INPUT_LEN], end[MAX_INPUT_LEN];
            sscanf(input, "add route %s %s", start, end);

            add_route(start, end);
        } else if (strncmp(input, "shape shift", 11) == 0) {	// shape shift command
            double degrees;
            sscanf(input, "shape shift %lf", &degrees);

            shape_shift(degrees);
        } else if (strncmp(input, "quit", 4) == 0) {	// quit command
            terminate = true;
            printf("Goodbye!\n");
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}