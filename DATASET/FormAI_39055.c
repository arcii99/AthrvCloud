//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10 // Maximum number of items in the game
#define MAX_LEVELS 3 // Maximum levels in the game
#define MAX_ENEMIES 5 // Maximum number of enemies per level

// Item structure
typedef struct {
    char name[20];
    int damage;
} Item;

// Enemy structure
typedef struct {
    char name[20];
    int health;
    int damage;
} Enemy;

// Level structure
typedef struct {
    int level_num;
    int num_enemies;
    Enemy enemies[MAX_ENEMIES];
} Level;

// Player structure
typedef struct {
    char name[20];
    int health;
    int damage;
    Item inventory[MAX_ITEMS];
} Player;

// Function declarations
void print_intro();
Item create_item(char name[], int damage);
Enemy create_enemy(char name[], int health, int damage);
Level create_level(int level_num, int num_enemies);
Player create_player(char name[], int health, int damage);
void display_inventory(Player p);
void start_battle(Player *p, Enemy *e);
void start_game(Player *p);

int main() {
    print_intro(); // Print the game introduction
    Player player = create_player("Hero", 100, 20); // Create the player
    start_game(&player); // Start the game
    return 0;
}

// Function to print the game introduction
void print_intro() {
    printf("Welcome to the Adventure Game!\n");
    printf("Your mission is to defeat all the enemies in each level and reach the end.\n");
    printf("Good luck and have fun!\n\n");
}

// Function to create an item
Item create_item(char name[], int damage) {
    Item i;
    strcpy(i.name, name);
    i.damage = damage;
    return i;
}

// Function to create an enemy
Enemy create_enemy(char name[], int health, int damage) {
    Enemy e;
    strcpy(e.name, name);
    e.health = health;
    e.damage = damage;
    return e;
}

// Function to create a level
Level create_level(int level_num, int num_enemies) {
    Level lvl;
    lvl.level_num = level_num;
    lvl.num_enemies = num_enemies;
    for(int i=0; i<num_enemies; i++) {
        int health = rand() % (level_num*50) + 50; // Random enemy health
        int damage = rand() % (level_num*10) + 10; // Random enemy damage
        char name[20];
        sprintf(name, "Enemy %d-%d", level_num, i+1); // Generate enemy name
        lvl.enemies[i] = create_enemy(name, health, damage); // Add enemy to level
    }
    return lvl;
}

// Function to create the player
Player create_player(char name[], int health, int damage) {
    Player p;
    strcpy(p.name, name);
    p.health = health;
    p.damage = damage;
    return p;
}

// Function to display the player inventory
void display_inventory(Player p) {
    printf("Inventory:\n");
    for(int i=0; i<MAX_ITEMS; i++) {
        if(strcmp(p.inventory[i].name, "") != 0) {
            printf(" - %s (Damage: %d)\n", p.inventory[i].name, p.inventory[i].damage);
        }
    }
    printf("\n");
}

// Function to start a battle between the player and an enemy
void start_battle(Player *p, Enemy *e) {
    printf("You have encountered %s (Health: %d, Damage: %d)\n", e->name, e->health, e->damage);
    while(1) {
        int player_damage = rand() % p->damage + 10; // Random player damage
        e->health -= player_damage;
        printf("You hit %s for %d damage!\n", e->name, player_damage);
        if(e->health <= 0) { // Enemy is defeated
            printf("%s is defeated!\n", e->name);
            int item_chance = rand() % 100 + 1; // Random chance to drop item
            if(item_chance <= 50) { // Enemy has dropped an item
                Item item = create_item("Sword", rand() % 10 + 10);
                printf("%s has dropped a %s (Damage: %d)!\n", e->name, item.name, item.damage);
                for(int i=0; i<MAX_ITEMS; i++) {
                    if(strcmp(p->inventory[i].name, "") == 0) { // Add item to inventory
                        p->inventory[i] = item;
                        break;
                    }
                }
            }
            break;
        }
        int enemy_damage = rand() % e->damage + 5; // Random enemy damage
        p->health -= enemy_damage;
        printf("%s hits you for %d damage! (Health: %d)\n", e->name, enemy_damage, p->health);
        if(p->health <= 0) { // Player is defeated
            printf("Game over! You have been defeated by %s.\n", e->name);
            exit(0);
        }
    }
    printf("\n");
}

// Function to start the game
void start_game(Player *p) {
    srand(time(NULL)); // Seed random number generator with current time
    for(int i=1; i<=MAX_LEVELS; i++) { // Loop through levels
        Level level = create_level(i, rand() % MAX_ENEMIES + 1); // Create level
        printf("Level %d\n", i);
        for(int j=0; j<level.num_enemies; j++) { // Loop through enemies
            start_battle(p, &level.enemies[j]); // Start battle with enemy
        }
        printf("Congratulations! You have defeated all the enemies in level %d\n\n", i);
        display_inventory(*p); // Display player inventory
    }
    printf("Congratulations! You have beaten the game!\n"); // Game is won
}