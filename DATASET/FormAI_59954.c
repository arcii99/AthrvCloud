//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_DISTANCE 10000

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point start;
    point end;
} route;

int map[MAP_SIZE][MAP_SIZE] = {0};
point current_location;
route current_route;

void generate_map();
void print_map();
int get_distance(point p1, point p2);
void set_current_route();
void print_route();
void update_location();
void simulate_navigation();

int main() {
    current_location.x = rand() % MAP_SIZE;
    current_location.y = rand() % MAP_SIZE;
    generate_map();
    print_map();
    set_current_route();
    print_route();
    simulate_navigation();
    return 0;
}

void generate_map() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            map[i][j] = rand() % 2;  // Generate random obstacles
        }
    }
}

void print_map() {
    int i, j;
    printf("MAP:\n");
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == current_location.y && j == current_location.x) {
                printf("O ");
            } else if (map[i][j]) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int get_distance(point p1, point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void set_current_route() {
    do {
        current_route.start.x = rand() % MAP_SIZE;
        current_route.start.y = rand() % MAP_SIZE;
        current_route.end.x = rand() % MAP_SIZE;
        current_route.end.y = rand() % MAP_SIZE;
    } while (map[current_route.start.y][current_route.start.x] || map[current_route.end.y][current_route.end.x]);  // Make sure the start and end points are not obstacles
}

void print_route() {
    printf("ROUTE:\n");
    printf("(%d, %d) -> (%d, %d)", current_route.start.x, current_route.start.y, current_route.end.x, current_route.end.y);
}

void update_location() {
    int distance_to_start = get_distance(current_location, current_route.start);
    int distance_to_end = get_distance(current_location, current_route.end);
    if (distance_to_start < distance_to_end) {
        printf("Moving towards (%d, %d)\n", current_route.start.x, current_route.start.y);
        current_location.x += current_location.x < current_route.start.x ? 1 : (current_location.x > current_route.start.x ? -1 : 0);
        current_location.y += current_location.y < current_route.start.y ? 1 : (current_location.y > current_route.start.y ? -1 : 0);
    } else {
        printf("Moving towards (%d, %d)\n", current_route.end.x, current_route.end.y);
        current_location.x += current_location.x < current_route.end.x ? 1 : (current_location.x > current_route.end.x ? -1 : 0);
        current_location.y += current_location.y < current_route.end.y ? 1 : (current_location.y > current_route.end.y ? -1 : 0);
    }
}

void simulate_navigation() {
    int distance_to_start = MAX_DISTANCE;
    int distance_to_end;
    while (distance_to_start > get_distance(current_location, current_route.start) || distance_to_end > get_distance(current_location, current_route.end)) {
        distance_to_start = get_distance(current_location, current_route.start);
        distance_to_end = get_distance(current_location, current_route.end);
        update_location();
        print_map();
    }
    printf("You have reached your destination!\n");
}