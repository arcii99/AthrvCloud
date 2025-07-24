//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_FUEL 100
#define MAX_ENEMY_HEALTH 50
#define MAX_DISTANCE 200
#define MAX_PLANETS 5

typedef struct {
    int health;
    int fuel;
    int distance;
    int planet_index;
} Spacecraft;

typedef struct {
    int health;
} Enemy;

typedef struct {
    char name[20];
    int distance;
    int has_merchant;
} Planet;

void initialize_spacecraft(Spacecraft* spacecraft) {
    spacecraft->health = MAX_HEALTH;
    spacecraft->fuel = MAX_FUEL;
    spacecraft->distance = 0;
    spacecraft->planet_index = 0;
}

void initialize_enemy(Enemy* enemy) {
    enemy->health = MAX_ENEMY_HEALTH;
}

void initialize_planets(Planet planets[]) {
    strcpy(planets[0].name, "Earth");
    planets[0].distance = 0;
    planets[0].has_merchant = 1;

    strcpy(planets[1].name, "Mars");
    planets[1].distance = 60;
    planets[1].has_merchant = 0;

    strcpy(planets[2].name, "Jupiter");
    planets[2].distance = 120;
    planets[2].has_merchant = 0;

    strcpy(planets[3].name, "Saturn");
    planets[3].distance = 160;
    planets[3].has_merchant = 1;

    strcpy(planets[4].name, "Pluto");
    planets[4].distance = 200;
    planets[4].has_merchant = 0;
}

void print_status(Spacecraft* spacecraft, Enemy* enemy) {
    printf("Health: %d\n", spacecraft->health);
    printf("Fuel: %d\n", spacecraft->fuel);
    printf("Distance: %d\n", spacecraft->distance);
    printf("Enemy Health: %d\n", enemy->health);
}

void travel(Spacecraft* spacecraft, int distance_to_travel) {
    if (spacecraft->fuel >= distance_to_travel) {
        spacecraft->fuel -= distance_to_travel;
        spacecraft->distance += distance_to_travel;
    } else {
        printf("Not enough fuel!\n");
    }
}

void battle(Spacecraft* spacecraft, Enemy* enemy) {
    while (spacecraft->health > 0 && enemy->health > 0) {
        int spacecraft_damage = rand() % 20 + 10;
        int enemy_damage = rand() % 15 + 5;

        enemy->health -= spacecraft_damage;
        spacecraft->health -= enemy_damage;
    }

    if (spacecraft->health <= 0) {
        printf("Spacecraft destroyed!\n");
        exit(0);
    }

    printf("Enemy defeated!\n");
}

void visit_merchant(Spacecraft* spacecraft) {
    spacecraft->health = MAX_HEALTH;
    spacecraft->fuel = MAX_FUEL;
}

int main() {
    srand(time(NULL));

    Spacecraft spacecraft;
    Enemy enemy;
    Planet planets[MAX_PLANETS];

    initialize_spacecraft(&spacecraft);
    initialize_enemy(&enemy);
    initialize_planets(planets);

    while (spacecraft.distance < MAX_DISTANCE) {
        printf("\nCurrent Planet: %s\n", planets[spacecraft.planet_index].name);
        printf("------------------------\n");

        print_status(&spacecraft, &enemy);

        if (planets[spacecraft.planet_index].has_merchant) {
            visit_merchant(&spacecraft);
            printf("Visited the merchant, health and fuel replenished!\n");
        }

        int distance_to_travel = rand() % 10 + 1;
        travel(&spacecraft, distance_to_travel);

        if (spacecraft.distance >= planets[spacecraft.planet_index].distance) {
            printf("Arrived at %s!\n", planets[spacecraft.planet_index].name);
            battle(&spacecraft, &enemy);
            spacecraft.planet_index++;
        }
    }

    printf("You win!\n");

    return 0;
}