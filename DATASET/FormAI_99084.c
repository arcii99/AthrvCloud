//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define the max number of planets in our galaxy
#define MAX_PLANETS 10

// Define the names of planets in our galaxy
const char* PLANET_NAMES[] = {"Alderaan", "Bespin", "Coruscant", "Dagobah", "Endor",
                              "Felucia", "Geonosis", "Hoth", "Iridonia", "Jabiim"};

// Define the maximum distance between two planets
#define MAX_DISTANCE 10000

// Define the maximum number of attempts to create a random distance
#define MAX_ATTEMPTS 1000

// Define the player's spaceship
typedef struct spaceship {
    char* name;
    int shield;
    int speed;
    int fuel;
    int x_coordinate;
    int y_coordinate;
} spaceship;

// Define a planet in our galaxy
typedef struct planet {
    char* name;
    int x_coordinate;
    int y_coordinate;
} planet;

// Create an instance of our player's spaceship
spaceship player_ship = {"Millennium Falcon", 100, 750, 1000, 0, 0};

// Create an array to hold the planets in our galaxy
planet galaxy[MAX_PLANETS];

// Initialize the planets in our galaxy
void init_planets() {
    for(int i=0; i<MAX_PLANETS; i++) {
        planet p;
        p.name = strdup(PLANET_NAMES[i]);
        p.x_coordinate = rand() % MAX_DISTANCE;
        p.y_coordinate = rand() % MAX_DISTANCE;
        galaxy[i] = p;
    }
}

// Get the distance between two points
int get_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

// Ask the player to input a number
int get_input() {
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    return input;
}

// Update the player's ship coordinates
void update_ship_coordinates(int x, int y) {
    player_ship.x_coordinate = x;
    player_ship.y_coordinate = y;
}

// Find the nearest planet to the player's ship
planet* get_nearest_planet() {
    planet* nearest_planet = &galaxy[0];
    int nearest_distance = get_distance(player_ship.x_coordinate, player_ship.y_coordinate,
                                         nearest_planet->x_coordinate, nearest_planet->y_coordinate);
    for(int i=1; i<MAX_PLANETS; i++) {
        planet* p = &galaxy[i];
        int distance = get_distance(player_ship.x_coordinate, player_ship.y_coordinate,
                                    p->x_coordinate, p->y_coordinate);
        if(distance < nearest_distance) {
            nearest_planet = p;
            nearest_distance = distance;
        }
    }
    return nearest_planet;
}

// Refuel the player's spaceship
void refuel() {
    int cost = (1000 - player_ship.fuel) * 2;
    if(player_ship.shield >= cost) {
        player_ship.fuel = 1000;
        player_ship.shield -= cost;
        printf("Refueled your spaceship. Shield decreased by %d points.\n", cost);
    }
    else {
        printf("You don't have enough shield to refuel your spaceship.\n");
    }
}

// Upgrade the player's spaceship
void upgrade() {
    int cost = 1000;
    if(player_ship.shield >= cost) {
        player_ship.shield -= cost;
        player_ship.speed += 100;
        printf("Upgraded your spaceship. Speed increased by 100. Shield decreased by %d points.\n", cost);
    }
    else {
        printf("You don't have enough shield to upgrade your spaceship.\n");
    }
}

// Attack a nearby planet
void attack_planet() {
    planet* nearest_planet = get_nearest_planet();
    int distance = get_distance(player_ship.x_coordinate, player_ship.y_coordinate,
                                 nearest_planet->x_coordinate, nearest_planet->y_coordinate);
    int damage = (rand() % 1000) / (double) player_ship.shield * distance;
    if(damage >= nearest_planet->x_coordinate / 2) {
        printf("You destroyed %s!\n", nearest_planet->name);
        nearest_planet->name = strdup("Destroyed planet");
        nearest_planet->x_coordinate = -1;
        nearest_planet->y_coordinate = -1;
    }
    else {
        player_ship.shield -= damage;
        printf("You attacked %s and received %d damage. Your shield is now %d.\n",
               nearest_planet->name, damage, player_ship.shield);
    }
}

// Warp to a random location in the galaxy
void warp() {
    int x = rand() % MAX_DISTANCE;
    int y = rand() % MAX_DISTANCE;
    int distance = get_distance(player_ship.x_coordinate, player_ship.y_coordinate, x, y);
    if(distance > player_ship.fuel / 2) {
        printf("You don't have enough fuel to warp that far.\n");
    }
    else {
        update_ship_coordinates(x, y);
        player_ship.fuel -= distance * 2;
        printf("You warped to a new location. Your fuel is now %d.\n", player_ship.fuel);
    }
}

// Menu function to display options to the player
void display_menu() {
    printf("Options:\n");
    printf("1. Refuel\n");
    printf("2. Upgrade\n");
    printf("3. Attack\n");
    printf("4. Warp\n");
    printf("5. Quit\n");
}

// Main function to run the game
int main() {
    srand(time(NULL));
    init_planets();
    while(true) {
        printf("Current location: (%d,%d)\n", player_ship.x_coordinate, player_ship.y_coordinate);
        printf("Current fuel: %d\n", player_ship.fuel);
        printf("Current shield: %d\n", player_ship.shield);
        display_menu();
        int input = get_input();
        switch(input) {
            case 1:
                refuel();
                break;
            case 2:
                upgrade();
                break;
            case 3:
                attack_planet();
                break;
            case 4:
                warp();
                break;
            case 5:
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid input.\n");
        }
    }
    return 0;
}