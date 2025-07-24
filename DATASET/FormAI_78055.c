//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 100
#define MAX_PLANETS 10
#define MAX_SHIPS 5

typedef struct {
    char name[BUF_SIZE];
    int x, y;
} Planet;

typedef struct {
    char name[BUF_SIZE];
    int x, y, speed, cargo_capacity;
    Planet home_planet;
} Ship;

void print_planets(Planet planets[], int planet_count);
void print_ships(Ship ships[], int ship_count);
void move_ship(Ship *ship, Planet target_planet);
void print_planet_info(Planet planet);
void print_ship_info(Ship ship);
int calculate_distance(int x1, int y1, int x2, int y2);
int get_random(int min, int max);

int main() {
    // initialize planets
    Planet planets[MAX_PLANETS];
    int planet_count = 0;

    strcpy(planets[planet_count].name, "Earth");
    planets[planet_count].x = 0;
    planets[planet_count].y = 0;
    planet_count++;

    strcpy(planets[planet_count].name, "Mars");
    planets[planet_count].x = get_random(-100, 100);
    planets[planet_count].y = get_random(-100, 100);
    planet_count++;

    // initialize ships
    Ship ships[MAX_SHIPS];
    int ship_count = 0;

    strcpy(ships[ship_count].name, "Enterprise");
    ships[ship_count].x = planets[0].x;
    ships[ship_count].y = planets[0].y;
    ships[ship_count].speed = 10;
    ships[ship_count].cargo_capacity = 100;
    ships[ship_count].home_planet = planets[0];
    ship_count++;

    strcpy(ships[ship_count].name, "Voyager");
    ships[ship_count].x = planets[1].x;
    ships[ship_count].y = planets[1].y;
    ships[ship_count].speed = 15;
    ships[ship_count].cargo_capacity = 50;
    ships[ship_count].home_planet = planets[1];
    ship_count++;

    srand(time(NULL)); // seed RNG with current time

    // main game loop
    while (1) {
        printf("Select a ship:\n");
        print_ships(ships, ship_count);
        int choice;
        scanf("%d", &choice);

        printf("Select a planet to move to:\n");
        print_planets(planets, planet_count);
        scanf("%d", &choice);
        Planet target_planet = planets[choice];

        move_ship(&ships[choice], target_planet);
        print_ship_info(ships[choice]);
    }

    return 0;
}

void print_planets(Planet planets[], int planet_count) {
    for (int i = 0; i < planet_count; i++) {
        printf("%d. %s (%d, %d)\n", i, planets[i].name, planets[i].x, planets[i].y);
    }
}

void print_ships(Ship ships[], int ship_count) {
    for (int i = 0; i < ship_count; i++) {
        printf("%d. %s\n", i, ships[i].name);
    }
}

void move_ship(Ship *ship, Planet target_planet) {
    int distance = calculate_distance(ship->x, ship->y, target_planet.x, target_planet.y);
    int time = distance / ship->speed;

    printf("%s is travelling to %s...\n", ship->name, target_planet.name);
    printf("ETA: %d hours\n", time);

    ship->x = target_planet.x;
    ship->y = target_planet.y;

    printf("%s has arrived at %s\n", ship->name, target_planet.name);
}

void print_planet_info(Planet planet) {
    printf("Name: %s\n", planet.name);
    printf("Position: (%d, %d)\n", planet.x, planet.y);
}

void print_ship_info(Ship ship) {
    printf("Name: %s\n", ship.name);
    printf("Position: (%d, %d)\n", ship.x, ship.y);
    printf("Speed: %d\n", ship.speed);
    printf("Cargo Capacity: %d\n", ship.cargo_capacity);
    printf("Home Planet: %s\n", ship.home_planet.name);
}

int calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int get_random(int min, int max) {
    return min + rand() % (max - min + 1);
}