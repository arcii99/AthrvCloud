//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_PLANETS 5

// Function prototypes
void init_game();
void print_map();
void print_status();
void move_player();
void generate_enemies();
void battle_enemy(int enemy_index);
void visit_planet(int planet_index);
void end_game();

// Struct definitions
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
} Player;

typedef struct {
    Position pos;
    int health;
    int power;
} Enemy;

typedef struct {
    Position pos;
    int visits;
} Planet;

// Global variables
int game_over = 0;
Player player;
Enemy enemies[MAX_ENEMIES];
Planet planets[MAX_PLANETS];
int num_enemies = 0;
int num_visited_planets = 0;

int main() {
    init_game();
    
    while (!game_over) {
        print_map();
        print_status();
        move_player();
    }
    
    end_game();
    return 0;
}

void init_game() {
    srand(time(NULL));
    
    // Initialize player at (0,0) with full health
    player.pos.x = 0;
    player.pos.y = 0;
    player.health = 100;
    
    // Initialize enemies at random positions on the map with random health and power
    generate_enemies();
    
    // Initialize planets at random positions on the map with 0 visits each
    for (int i = 0; i < MAX_PLANETS; i++) {
        planets[i].pos.x = rand() % 10 - 5;
        planets[i].pos.y = rand() % 10 - 5;
        planets[i].visits = 0;
    }
}

void generate_enemies() {
    num_enemies = rand() % MAX_ENEMIES;
    
    for (int i = 0; i < num_enemies; i++) {
        // Generate random position, health, and power for each enemy
        enemies[i].pos.x = rand() % 10 - 5;
        enemies[i].pos.y = rand() % 10 - 5;
        enemies[i].health = rand() % 50 + 50;
        enemies[i].power = rand() % 10 + 1;
    }
}

void print_map() {
    printf("------------------------------\n");
    for (int y = 5; y >= -5; y--) {
        printf("|");
        for (int x = -5; x <= 5; x++) {
            // Print player character at player position
            if (x == player.pos.x && y == player.pos.y) {
                printf(" P ");
            }
            // Print enemy character at enemy positions
            else {
                int enemy_exists = 0;
                for (int i = 0; i < num_enemies; i++) {
                    if (x == enemies[i].pos.x && y == enemies[i].pos.y) {
                        printf(" E ");
                        enemy_exists = 1;
                        break;
                    }
                }
                if (!enemy_exists) {
                    // Print planet character at planet positions
                    int planet_exists = 0;
                    for (int i = 0; i < MAX_PLANETS; i++) {
                        if (x == planets[i].pos.x && y == planets[i].pos.y) {
                            printf(" @ ");
                            planet_exists = 1;
                            break;
                        }
                    }
                    if (!planet_exists) {
                        // Print empty space
                        printf(" . ");
                    }
                }
            }
            printf("|");
        }
        printf("\n");
    }
    printf("------------------------------\n");
}

void print_status() {
    printf("Health: %d\n", player.health);
    printf("Enemies remaining: %d\n", num_enemies);
    printf("Planets visited: %d\n", num_visited_planets);
}

void move_player() {
    printf("Enter direction to move (N/S/E/W): ");
    char direction;
    scanf(" %c", &direction);
    
    switch (direction) {
        case 'N':
            if (player.pos.y + 1 <= 5) {
                player.pos.y += 1;
            }
            else {
                printf("You cannot move further north.\n");
            }
            break;
        case 'S':
            if (player.pos.y - 1 >= -5) {
                player.pos.y -= 1;
            }
            else {
                printf("You cannot move further south.\n");
            }
            break;
        case 'E':
            if (player.pos.x + 1 <= 5) {
                player.pos.x += 1;
            }
            else {
                printf("You cannot move further east.\n");
            }
            break;
        case 'W':
            if (player.pos.x - 1 >= -5) {
                player.pos.x -= 1;
            }
            else {
                printf("You cannot move further west.\n");
            }
            break;
        default:
            printf("Invalid direction.\n");
    }
    
    // Check if there is an enemy at the player's new position
    for (int i = 0; i < num_enemies; i++) {
        if (player.pos.x == enemies[i].pos.x && player.pos.y == enemies[i].pos.y) {
            // Battle the enemy
            battle_enemy(i);
            break;
        }
    }
    
    // Check if there is a planet at the player's new position
    for (int i = 0; i < MAX_PLANETS; i++) {
        if (player.pos.x == planets[i].pos.x && player.pos.y == planets[i].pos.y) {
            // Visit the planet
            visit_planet(i);
            break;
        }
    }
}

void battle_enemy(int enemy_index) {
    printf("You have encountered an enemy!\n");
    Enemy enemy = enemies[enemy_index];
    printf("Enemy health: %d\n", enemy.health);
    
    while (player.health > 0 && enemy.health > 0) {
        // Player attacks first
        int player_hit = rand() % 10 + 1;
        printf("You attack the enemy for %d damage.\n", player_hit);
        enemy.health -= player_hit;
        if (enemy.health <= 0) {
            printf("Enemy defeated!\n");
            num_enemies--;
            enemies[enemy_index] = enemies[num_enemies];
            return;
        }
        
        // Enemy attacks next
        int enemy_hit = rand() % 10 + 1;
        printf("Enemy attacks you for %d damage.\n", enemy_hit);
        player.health -= enemy_hit;
        if (player.health <= 0) {
            printf("You have been defeated.\n");
            game_over = 1;
            return;
        }
    }
}

void visit_planet(int planet_index) {
    Planet planet = planets[planet_index];
    printf("You have landed on a planet!\n");
    printf("Planet visits: %d\n", planet.visits);
    planet.visits++;
    num_visited_planets++;
    
    if (planet.visits == 1) {
        printf("You have found a medical kit on the planet.\n");
        player.health += 25;
        printf("Health increased to %d.\n", player.health);
    }
    else {
        printf("No items found on this planet.\n");
    }
}

void end_game() {
    printf("Game over.\n");
    printf("Planets visited: %d\n", num_visited_planets);
    if (num_visited_planets == MAX_PLANETS) {
        printf("Congratulations, you have visited all planets!\n");
    }
    else {
        printf("You did not visit all planets.\n");
    }
}