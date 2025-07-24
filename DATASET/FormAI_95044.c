//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_DISTANCE 1000000
#define MAX_CITIES 1000

int distances[MAX_CITIES][MAX_CITIES];
int cities_count = 0;

typedef struct city {
    char name[50];
    int x;
    int y;
} City;

City cities[MAX_CITIES];

// Helper function to calculate distance between two cities
int get_distance(City city1, City city2) {
    int x_diff = city1.x - city2.x;
    int y_diff = city1.y - city2.y;
    return (int) sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

// Helper function to get city index by city name
int get_city_index(char *city_name) {
    for (int i = 0; i < cities_count; i++) {
        if (strcmp(cities[i].name, city_name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add a city to the cities array
void add_city(char *city_name, int x, int y) {
    City new_city = (City) {.x = x, .y = y};
    strcpy(new_city.name, city_name);
    cities[cities_count++] = new_city;
}

// Function to add a distance between two cities to the distances array
void add_distance(char *city1_name, char *city2_name) {
    int city1_index = get_city_index(city1_name);
    int city2_index = get_city_index(city2_name);
    int distance = get_distance(cities[city1_index], cities[city2_index]);
    distances[city1_index][city2_index] = distance;
    distances[city2_index][city1_index] = distance;
}

// Function to calculate the shortest path between two cities using Dijkstra's algorithm
int shortest_path(char *start_city_name, char *end_city_name) {
    int start_city_index = get_city_index(start_city_name);
    int end_city_index = get_city_index(end_city_name);

    int visited[cities_count];
    int distances_from_start[cities_count];

    for (int i = 0; i < cities_count; i++) {
        visited[i] = 0;
        distances_from_start[i] = MAX_DISTANCE;
    }

    distances_from_start[start_city_index] = 0;

    for (int i = 0; i < cities_count; i++) {
        int current_city = -1;
        for (int j = 0; j < cities_count; j++) {
            if (!visited[j] && (current_city == -1 || distances_from_start[j] < distances_from_start[current_city])) {
                current_city = j;
            }
        }

        if (distances_from_start[current_city] == MAX_DISTANCE) {
            break;
        }

        visited[current_city] = 1;

        for (int j = 0; j < cities_count; j++) {
            if (distances[current_city][j] != 0) {
                int distance = distances_from_start[current_city] + distances[current_city][j];
                if (distance < distances_from_start[j]) {
                    distances_from_start[j] = distance;
                }
            }
        }
    }

    return distances_from_start[end_city_index];
}

int main() {
    add_city("New York", 0, 0);
    add_city("Los Angeles", 2000, 0);
    add_city("Chicago", 1000, 1000);

    add_distance("New York", "Los Angeles");
    add_distance("New York", "Chicago");
    add_distance("Los Angeles", "Chicago");

    int distance = shortest_path("New York", "Los Angeles");

    printf("Distance between New York and Los Angeles: %d miles", distance);
    return 0;
}