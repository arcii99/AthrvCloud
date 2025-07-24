//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the constants
#define MAX_NAME_LEN 25
#define MAX_PLANET_LEN 50
#define MAX_SHIP_LEN 50
#define MAX_WEAPONS 5
#define MAX_ENEMIES 3
#define MAX_ENEMY_LVL 5

// Define the structures
struct player {
    char name[MAX_NAME_LEN];
    char ship[MAX_SHIP_LEN];
    char planet[MAX_PLANET_LEN];
    int health;
    int max_health;
    int power;
    int credits;
    int num_weapons;
    char weapons[MAX_WEAPONS][MAX_NAME_LEN];
};

struct enemy {
    char name[MAX_NAME_LEN];
    int health;
    int power;
    int credits;
    int level;
};

// Function prototypes
int menu();
struct player create_player();
void display_player(struct player p);
struct enemy create_enemy(int level);
void attack(struct player *p, struct enemy *e);
void buy_weapons(struct player *p);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the player
    struct player p = create_player();

    // Loop through the game until the player quits or dies
    int game_over = 0;
    while (!game_over) {
        // Display the main menu
        int choice = menu();

        switch (choice) {
            case 1:
                // Continue the adventure on a planet
                printf("You land on a planet called %s.\n", p.planet);
                // TODO: Add code for the planet adventure
                break;
            case 2:
                // Upgrade the ship
                printf("You enter the space station and find a shipyard.\n");
                // TODO: Add code for the ship upgrade
                break;
            case 3:
                // Buy weapons
                printf("You enter the space station and find a weapon shop.\n");
                buy_weapons(&p);
                break;
            case 4:
                // Exit the game
                printf("Quitting the game.\n");
                game_over = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Check if the player is dead
        if (p.health <= 0) {
            printf("You died. Game over.\n");
            game_over = 1;
        }
    }

    return 0;
}

int menu() {
    int choice;
    printf("\nWhat do you want to do next?\n");
    printf("1. Continue the adventure on a planet\n");
    printf("2. Upgrade the ship\n");
    printf("3. Buy weapons\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

struct player create_player() {
    struct player p;
    printf("Enter your name: ");
    fgets(p.name, MAX_NAME_LEN, stdin);
    printf("Enter your ship name: ");
    fgets(p.ship, MAX_SHIP_LEN, stdin);
    printf("Enter the name of the planet you were born on: ");
    fgets(p.planet, MAX_PLANET_LEN, stdin);
    p.health = 100;
    p.max_health = 100;
    p.power = 10;
    p.credits = 100;
    p.num_weapons = 1;
    strcpy(p.weapons[0], "Laser Gun");
    return p;
}

void display_player(struct player p) {
    printf("\n%s\n", p.name);
    printf("Ship: %s\n", p.ship);
    printf("Planet: %s\n", p.planet);
    printf("Health: %d / %d\n", p.health, p.max_health);
    printf("Power: %d\n", p.power);
    printf("Credits: %d\n", p.credits);
    printf("Weapons: ");
    for (int i = 0; i < p.num_weapons; i++) {
        printf("%s", p.weapons[i]);
        if (i != p.num_weapons - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

struct enemy create_enemy(int level) {
    struct enemy e;
    char *names[] = {"Drone", "Fighter", "Cruiser"};
    int healths[] = {50, 100, 150};
    int powers[] = {5, 10, 15};
    int credits[] = {50, 100, 150};
    e.level = level;
    strcpy(e.name, names[rand() % MAX_ENEMIES]);
    e.health = healths[rand() % MAX_ENEMIES] * level;
    e.power = powers[rand() % MAX_ENEMIES] * level;
    e.credits = credits[rand() % MAX_ENEMIES] * level;
    return e;
}

void attack(struct player *p, struct enemy *e) {
    // Player attacks the enemy
    printf("You attack the %s with your %s.\n", e->name, p->weapons[0]);
    int damage = p->power;
    printf("You deal %d damage.\n", damage);
    e->health -= damage;

    // Check if the enemy is dead
    if (e->health <= 0) {
        printf("You defeated the %s.\n", e->name);
        printf("You gained %d credits.\n", e->credits);
        p->credits += e->credits;
        return;
    }

    // Enemy counters with an attack
    printf("The %s counterattacks.\n", e->name);
    damage = e->power;
    printf("You take %d damage.\n", damage);
    p->health -= damage;
}

void buy_weapons(struct player *p) {
    // Weapons available to buy
    char *weapon_names[] = {"Plasma Rifle", "Ion Launcher", "Proton Cannon", "Neutron Blaster", "Tesseract Bomb"};
    int weapon_prices[] = {100, 200, 300, 400, 500};
    int num_weapons = sizeof(weapon_names) / sizeof(weapon_names[0]);

    // Display the available weapons
    printf("Available weapons:\n");
    for (int i = 0; i < num_weapons; i++) {
        printf("%d. %s - %d credits\n", i + 1, weapon_names[i], weapon_prices[i]);
    }

    // Ask the player which weapon they want to buy
    printf("Enter the number of the weapon you want to buy (0 to cancel): ");
    int choice;
    scanf("%d", &choice);
    if (choice < 0 || choice > num_weapons) {
        printf("Invalid choice.\n");
        return;
    }
    if (choice == 0) {
        printf("Transaction cancelled.\n");
        return;
    }

    // Check if the player has enough credits
    if (p->credits < weapon_prices[choice - 1]) {
        printf("You don't have enough credits.\n");
        return;
    }

    // Buy the weapon and deduct credits
    printf("You bought a %s.\n", weapon_names[choice - 1]);
    strcpy(p->weapons[p->num_weapons], weapon_names[choice - 1]);
    p->credits -= weapon_prices[choice - 1];
    p->num_weapons++;
}