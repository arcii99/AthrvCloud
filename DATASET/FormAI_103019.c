//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining constants
#define MAX_PLAYERS 4
#define MAX_PLANETS 10
#define MAX_RESOURCES 3
#define MAX_RESOURCE_THRESHOLD 100
#define MAX_TURNS 20

// Defining structs
typedef struct {
    char name[20];
    int resources[MAX_RESOURCES];
} player;

typedef struct {
    int id;
    int resources[MAX_RESOURCES];
    int threshold;
} planet;

// Defining global variables
player players[MAX_PLAYERS];
planet planets[MAX_PLANETS];
int num_players;
int num_planets;
int resources_collected;

// Function prototypes
void generate_planets();
void display_planets();
void initialize_players();
void display_players();
void get_player_turn(int player_num);
void collect_resources(int player_num, int planet_choice);
void display_resources_collected();
void determine_winner();

// Main function
int main() {
    srand(time(NULL));
    printf("Welcome to the Space Adventure game!\n\n");
    
    // Initializing game
    generate_planets();
    display_planets();
    initialize_players();

    // Game Loop
    for (int i = 0; i < MAX_TURNS; i++) {
        printf("\n\nTurn %d:\n\n", i + 1);
        display_players();
        for (int j = 0; j < num_players; j++) {
            get_player_turn(j);
        }
        display_resources_collected();
        resources_collected = 0;
    }

    determine_winner();

    return 0;
}

// Function to generate the planets for the game
void generate_planets() {
    num_planets = rand() % (MAX_PLANETS - 3) + 3; // Generating random number of planets between 3 and MAX_PLANETS
    printf("Generating %d planets...\n", num_planets);
    for (int i = 0; i < num_planets; i++) {
        planets[i].id = i + 1; // Assigning IDs to planets
        planets[i].threshold = rand() % MAX_RESOURCE_THRESHOLD + 1; // Assigning a random threshold for each planet
        for (int j = 0; j < MAX_RESOURCES; j++) {
            planets[i].resources[j] = rand() % (planets[i].threshold + 1); // Assigning random resource values
        }
    }
}

// Function to display the planets
void display_planets() {
    printf("\n------ Planets in the Universe ------\n\n");
    printf("ID\tResources\tThreshold\n");
    for (int i = 0; i < num_planets; i++) {
        printf("%d\t", planets[i].id);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d\t", planets[i].resources[j]);
        }
        printf("%d\n", planets[i].threshold);
    }
    printf("\n");
}

// Function to initialize the players
void initialize_players() {
    printf("Enter the number of players (1 - 4): ");
    scanf("%d", &num_players);

    while (num_players < 1 || num_players > MAX_PLAYERS) { // Validating player count
        printf("Invalid player count. Please enter a number between 1 and 4: ");
        scanf("%d", &num_players);
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            players[i].resources[j] = 0; // Initializing player's resources to 0
        }
    }
}

// Function to display the players
void display_players() {
    printf("\n------ Players in the Game ------\n\n");
    printf("Name\tResources\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s\t", players[i].name);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d\t", players[i].resources[j]);
        }
        printf("\n");
    }
}

// Function to get the turn for a player
void get_player_turn(int player_num) {
    int planet_choice;
    printf("\nIt's %s's turn.\n", players[player_num].name);
    printf("Choose a planet to collect resources from (1 - %d): ", num_planets);
    scanf("%d", &planet_choice);

    while (planet_choice < 1 || planet_choice > num_planets) { // Checking if planet choice is valid
        printf("Invalid planet choice. Please choose a planet from the list (1 - %d): ", num_planets);
        scanf("%d", &planet_choice);
    }

    collect_resources(player_num, planet_choice);
}

// Function to collect resources from a planet
void collect_resources(int player_num, int planet_choice) {
    int resource_choice;
    printf("\nResources available on planet %d:\n", planet_choice);
    printf("ID\tResource\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d\t%d\n", i + 1, planets[planet_choice - 1].resources[i]);
    }
    printf("Choose a resource to collect (1 - %d): ", MAX_RESOURCES);
    scanf("%d", &resource_choice);

    while (resource_choice < 1 || resource_choice > MAX_RESOURCES) { // Checking if resource choice is valid
        printf("Invalid resource choice. Please choose a resource from the list (1 - %d): ", MAX_RESOURCES);
        scanf("%d", &resource_choice);
    }

    int resources_to_collect;
    printf("Enter the number of resources to collect: ");
    scanf("%d", &resources_to_collect);

    while (resources_to_collect > planets[planet_choice - 1].resources[resource_choice - 1]) { // Checking if resources to collect is valid
        printf("Not enough resources available on the planet. Please choose a lower value: ");
        scanf("%d", &resources_to_collect);
    }

    planets[planet_choice - 1].resources[resource_choice - 1] -= resources_to_collect; // Decreasing planet's resources by collected amount
    players[player_num].resources[resource_choice - 1] += resources_to_collect; // Adding collected resources to player's resources
    resources_collected += resources_to_collect; // Tracking total resources collected
}

// Function to display the resources collected in a turn
void display_resources_collected() {
    printf("Total resources collected in this turn: %d\n", resources_collected);
}

// Function to determine the winner of the game
void determine_winner() {
    int max_resources = 0;
    int winner_indices[MAX_PLAYERS];
    int num_winners = 0;

    for (int i = 0; i < num_players; i++) {
        int resources = 0;
        for (int j = 0; j < MAX_RESOURCES; j++) {
            resources += players[i].resources[j];
        }
        if (resources > max_resources) {
            max_resources = resources; // Tracking highest resource count
            num_winners = 1;
            winner_indices[0] = i;
        } else if (resources == max_resources) {
            num_winners++; // Tracking number of players with highest resource count
            winner_indices[num_winners - 1] = i;
        }
    }

    if (num_winners > 1) { // Checking for tie
        printf("\n\nIt's a tie between the following players:\n\n");
        for (int i = 0; i < num_winners; i++) {
            printf("%s\n", players[winner_indices[i]].name);
        }
    } else {
        printf("\n\n%s is the winner of the Space Adventure game!\n", players[winner_indices[0]].name);
    }
}