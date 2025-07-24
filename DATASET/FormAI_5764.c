//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define MAX_NAME_LENGTH 20
#define MAX_PLANETS 10
#define MAX_HEALTH 100

// Structs
typedef struct {
    char name[MAX_NAME_LENGTH];
    int population;
    int resources;
    int distance;
} Planet;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int credits;
    Planet current_planet;
} Player;

// Functions
void generate_planets(Planet planets[]) {
    // Generate random planets
    char names[MAX_PLANETS][MAX_NAME_LENGTH] = {"Terra", "Aurora", "Nova", "Elysium", "Nirvana",
                                                "Valhalla", "Atlantis", "Olympus", "Avalon", "Zion"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        Planet planet;
        strcpy(planet.name, names[i]);
        planet.population =  (rand() % (3000000 - 1000000 + 1)) + 1000000; // Random population between 1M and 3M
        planet.resources = (rand() % (2000 - 500 + 1)) + 500; // Random resources between 500 and 2000
        planet.distance = (rand() % (10 - 1 + 1)) + 1; // Random distance between 1 and 10
        planets[i] = planet;
    }
}

void print_planets(Planet planets[]) {
    printf("Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("- %s | Population: %d | Resources: %d | Distance: %d lightyears\n", planets[i].name, planets[i].population, planets[i].resources, planets[i].distance);
    }
}

void travel(Player *player, Planet planets[]) {
    int selection;
    printf("Select a planet to travel to:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s\n", i+1, planets[i].name);
    }
    scanf("%d", &selection);
    if (selection < 1 || selection > MAX_PLANETS) {
        printf("Invalid selection.\n");
        return;
    }
    
    Planet destination = planets[selection-1];
    if (player->credits < destination.resources) {
        printf("Not enough resources to travel to %s.\n", destination.name);
        return;
    }
    
    player->current_planet = destination;
    player->credits -= destination.resources;
    printf("Successfully travelled to %s.\n", destination.name);
}

void buy_resources(Player *player) {
    int quantity, cost;
    printf("How much resources would you like to buy? ");
    scanf("%d", &quantity);
    cost = quantity * 10;
    if (player->credits < cost) {
        printf("Not enough credits to buy %d resources.\n", quantity);
        return;
    }
    
    player->current_planet.resources += quantity;
    player->credits -= cost;
    printf("Successfully bought %d resources.\n", quantity);
}

void sell_resources(Player *player) {
    int quantity, profit;
    printf("How much resources would you like to sell? ");
    scanf("%d", &quantity);
    if (player->current_planet.resources < quantity) {
        printf("Not enough resources to sell %d.\n", quantity);
        return;
    }
    
    profit = quantity * 5;
    player->current_planet.resources -= quantity;
    player->credits += profit;
    printf("Successfully sold %d resources for %d credits.\n", quantity, profit);
}

void print_player(Player player) {
    printf("%s:\n", player.name);
    printf("- Health: %d\n", player.health);
    printf("- Credits: %d\n", player.credits);
    printf("- Current planet: %s\n", player.current_planet.name);
}

int main() {
    // Set random seed
    srand(time(NULL));
    
    // Generate random planets
    Planet planets[MAX_PLANETS];
    generate_planets(planets);
    
    // Create player
    Player player;
    printf("Enter your name: ");
    scanf("%s", player.name);
    player.health = MAX_HEALTH;
    player.credits = 100;
    player.current_planet = planets[0];
    
    // Game loop
    while (player.health > 0) {
        printf("\n");
        print_player(player);
        print_planets(planets);
        
        int action;
        printf("Select an action:\n");
        printf("1. Travel to another planet\n");
        printf("2. Buy resources\n");
        printf("3. Sell resources\n");
        printf("4. Quit game\n");
        scanf("%d", &action);
        
        switch(action) {
            case 1:
                travel(&player, planets);
                break;
            case 2:
                buy_resources(&player);
                break;
            case 3:
                sell_resources(&player);
                break;
            case 4:
                printf("Quitting game...\n");
                return 0;
            default:
                printf("Invalid selection.\n");
                break;
        }
    }
    
    printf("Game over. You died.\n");
    return 0;
}