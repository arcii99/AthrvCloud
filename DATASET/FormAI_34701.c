//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLANETS 20
#define MAX_NAME_LEN 20

struct planet {
    char name[MAX_NAME_LEN];
    int x, y; // coordinates of the planet
    float resources;
    bool explored;
};
typedef struct planet planet_t;

void generate_random_planets(planet_t planets[], int num_planets);
void print_planet_info(planet_t planet);
void scan_for_new_planets(planet_t planets[], int num_planets, int x, int y);
void explore_planet(planet_t *planet);
int get_input();
void travel_to_planet(planet_t planets[], int num_planets, int *x, int *y);

int main()
{
    srand(time(NULL)); // seed random number generator with current time

    // generate random planets
    planet_t planets[MAX_PLANETS];
    generate_random_planets(planets, MAX_PLANETS);

    // initialize starting position
    int x = 0, y = 0;
    bool quit = false;

    // main game loop
    while (!quit) {
        printf("Your ship is currently located at (%d, %d)\n", x, y);
        printf("Enter 1 to travel to another planet, 2 to scan for new planets, or 3 to quit: ");
        int choice = get_input();

        if (choice == 1) {
            travel_to_planet(planets, MAX_PLANETS, &x, &y);
        } else if (choice == 2) {
            scan_for_new_planets(planets, MAX_PLANETS, x, y);
        } else if (choice == 3) {
            quit = true;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}

void generate_random_planets(planet_t planets[], int num_planets)
{
    char names[][MAX_NAME_LEN] = {"Terra", "Neo-Terra", "Auriga", "Orion", "Nebula", "Polaris", "Alderan", "Bajor", "Caprica", "Coruscant", "Endor", "Hoth"};

    for (int i = 0; i < num_planets; i++) {
        // assign random name
        int rand_index = rand() % 12; // 12 is the number of planet names in the names array
        for (int j = 0; j < MAX_NAME_LEN; j++) {
            planets[i].name[j] = names[rand_index][j];
        }

        // assign random coordinates within a range of -100 to 100
        planets[i].x = rand() % 201 - 100;
        planets[i].y = rand() % 201 - 100;

        // assign random resources
        planets[i].resources = (float) (rand() % 100) / 10.0;

        // set as unexplored
        planets[i].explored = false;
    }
}

void print_planet_info(planet_t planet)
{
    printf("Planet name: %s\n", planet.name);
    printf("Coordinates: (%d, %d)\n", planet.x, planet.y);
    printf("Resources available: %0.1f\n", planet.resources);
    printf("Explored: %s\n", planet.explored ? "true" : "false");
}

void scan_for_new_planets(planet_t planets[], int num_planets, int x, int y)
{
    printf("Searching nearby systems...\n");

    for (int i = 0; i < num_planets; i++) {
        if (!planets[i].explored) {
            int distance = abs(planets[i].x - x) + abs(planets[i].y - y);
            if (distance <= 50) {
                printf("New planet found within range!\n");
                print_planet_info(planets[i]);
                printf("Would you like to explore this planet? Enter 1 for yes, or any other number for no: ");
                int choice = get_input();
                if (choice == 1) {
                    explore_planet(&planets[i]);
                }
            }
        }
    }
}

void explore_planet(planet_t *planet)
{
    printf("Starting exploration of %s...\n", planet->name);
    printf("Gathering resources...\n");
    planet->resources -= 1.0; // costs 1 resource unit to explore
    printf("Explored %s! Resources available: %0.1f\n", planet->name, planet->resources);
    planet->explored = true;
}

int get_input()
{
    int input;

    scanf("%d", &input);
    while (getchar() != '\n'); // flush input buffer

    return input;
}

void travel_to_planet(planet_t planets[], int num_planets, int *x, int *y)
{
    printf("Available destinations:\n");
    for (int i = 0; i < num_planets; i++) {
        if (planets[i].explored) {
            printf("%d. %s (%d, %d)\n", i + 1, planets[i].name, planets[i].x, planets[i].y);
        }
    }

    printf("Enter the number of the planet you'd like to travel to: ");
    int choice = get_input() - 1;

    if (choice >= 0 && choice < num_planets && planets[choice].explored) {
        int dist_x = planets[choice].x - *x;
        int dist_y = planets[choice].y - *y;
        printf("Travelling to %s...\n", planets[choice].name);
        if (dist_x > 0) {
            printf("Moving east by %d units...\n", dist_x);
            *x += dist_x;
        } else if (dist_x < 0) {
            printf("Moving west by %d units...\n", abs(dist_x));
            *x -= abs(dist_x);
        }

        if (dist_y > 0) {
            printf("Moving south by %d units...\n", dist_y);
            *y += dist_y;
        } else if (dist_y < 0) {
            printf("Moving north by %d units...\n", abs(dist_y));
            *y -= abs(dist_y);
        }

        printf("You have arrived at %s.\n", planets[choice].name);
    } else {
        printf("Invalid choice, please try again.\n");
    }
}