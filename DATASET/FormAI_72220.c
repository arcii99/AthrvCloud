//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void start_game();
void initialize_items();
void select_planet();
void explore_planet();
void examine_item();
int generate_random(int max);
void display_inventory();
void end_game();

// Define global variables
int num_items = 6;
int current_planet = 0;
char planet_names[4][20] = {"Mercury", "Venus", "Earth", "Mars"};
char item_names[6][20] = {"Laser Gun", "Space Suit", "Oxygen Tank", "Energy Drink", "Gravity Boots", "Alien Artifact"};
int inventory[6] = {0, 0, 0, 0, 0, 0};
char player_name[20];

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Welcome the player and start the game
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%19s", player_name);
    start_game();

    return 0;
}

void start_game() {
    // Initialize items and select starting planet
    initialize_items();
    select_planet();

    // Start game loop
    while (1) {
        char input[20];
        printf("\nWhat would you like to do?\n");
        printf("(E)xplore planet, (I)nventory, (Q)uit\n");
        scanf("%19s", input);

        if (strcmp(input, "E") == 0 || strcmp(input, "e") == 0) {
            explore_planet();
        } else if (strcmp(input, "I") == 0 || strcmp(input, "i") == 0) {
            display_inventory();
        } else if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0) {
            end_game();
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

void initialize_items() {
    // Set random inventory items
    for (int i = 0; i < num_items; i++) {
        if (generate_random(2) == 0) {
            inventory[i] = 1;
        }
    }
}

void select_planet() {
    // Choose starting planet
    current_planet = generate_random(4);
    printf("\nWelcome to %s, %s!\n", planet_names[current_planet], player_name);
}

void explore_planet() {
    // Generate random item
    int item_found = generate_random(num_items);

    printf("You found a %s!\n", item_names[item_found]);

    // Add item to inventory
    inventory[item_found] = 1;

    // Examine item
    printf("Do you want to examine the item? (Y/N)\n");
    char input[20];
    scanf("%19s", input);

    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
        examine_item(item_found);
    }
}

void examine_item(int item_index) {
    switch (item_index) {
        case 0:
            printf("The Laser Gun looks impressive. It should help you protect yourself against any hostile alien life forms.\n");
            break;
        case 1:
            printf("The Space Suit is fully equipped for extravehicular activities. With it, you can explore any planet safely without any worry about vacuum environments.\n");
            break;
        case 2:
            printf("The Oxygen Tank is lightweight and will provide a steady supply of oxygen for your exploration of any hostile environment.\n");
            break;
        case 3:
            printf("The Energy Drink is a popular beverage among space explorers. It will give you enough energy for hours of exploration.\n");
            break;
        case 4:
            printf("The Gravity Boots might look cumbersome, but they will allow you to walk on planets with high gravitational forces.\n");
            break;
        case 5:
            printf("The Alien Artifact is of unknown origin. You might need to consult someone knowledgeable in alien technologies to examine it further.\n");
            break;
        default:
            printf("Invalid item index.\n");
    }
}

int generate_random(int max) {
    return rand() % max;
}

void display_inventory() {
    printf("\nInventory:\n");
    for (int i = 0; i < num_items; i++) {
        if (inventory[i]) {
            printf("- %s\n", item_names[i]);
        }
    }
}

void end_game() {
    printf("\nThank you for playing the Procedural Space Adventure, %s!\n", player_name);
    exit(0);
}