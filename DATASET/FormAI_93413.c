//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_MOVES 20
#define MAX_ENEMIES 5

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    Coord position;
    int health;
    int damage;
} Enemy;

void print_map(char map[MAP_SIZE][MAP_SIZE], Coord player) {
    printf(" ");
    for (int col = 0; col < MAP_SIZE; col++) {
        printf(" %d", col);
    }
    printf("\n");
    
    for (int row = 0; row < MAP_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < MAP_SIZE; col++) {
            if (row == player.y && col == player.x) {
                printf("P ");
            } else {
                printf("%c ", map[row][col]);
            }
        }
        printf("\n");
    }
}

void print_enemy_status(Enemy enemies[MAX_ENEMIES], int num_enemies) {
    printf("Enemies:\n");
    for (int i = 0; i < num_enemies; i++) {
        printf("Enemy %d at position (%d, %d), health: %d, damage: %d\n", 
            i+1, enemies[i].position.x, enemies[i].position.y,
            enemies[i].health, enemies[i].damage);
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    srand(time(NULL));  // seed random number generator

    // initialize map
    for (int row = 0; row < MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {
            map[row][col] = '.';
        }
    }

    // randomly place enemies
    Enemy enemies[MAX_ENEMIES];
    int num_enemies = 0;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        int row = rand() % MAP_SIZE;
        int col = rand() % MAP_SIZE;
        if (map[row][col] == '.') {  // only add if spot is empty
            enemies[num_enemies].position.x = col;
            enemies[num_enemies].position.y = row;
            enemies[num_enemies].health = rand() % 10 + 1;
            enemies[num_enemies].damage = rand() % 5 + 1;
            map[row][col] = 'E';
            num_enemies++;
        }
    }

    // randomly place player
    Coord player;
    do {
        player.x = rand() % MAP_SIZE;
        player.y = rand() % MAP_SIZE;
    } while (map[player.y][player.x] != '.');

    // game loop
    int moves_left = MAX_MOVES;
    int enemies_left = num_enemies;
    while (moves_left > 0 && enemies_left > 0) {
        // print map and enemy status
        printf("Moves left: %d\n", moves_left);
        print_map(map, player);
        print_enemy_status(enemies, num_enemies);
        
        // get player input
        int dx, dy;
        printf("Enter movement (dx dy): ");
        scanf("%d %d", &dx, &dy);

        // update player position
        if (player.x + dx >= 0 && player.x + dx < MAP_SIZE &&
            player.y + dy >= 0 && player.y + dy < MAP_SIZE &&
            map[player.y+dy][player.x+dx] == '.') {
            player.x += dx;
            player.y += dy;
        } else {
            printf("Invalid move!\n");
        }

        // check for enemy encounters
        for (int i = 0; i < num_enemies; i++) {
            if (enemies[i].position.x == player.x && 
                enemies[i].position.y == player.y) {
                printf("You encounter an enemy!\n");
                while (enemies[i].health > 0 && moves_left > 0) {
                    enemies[i].health -= rand() % 5 + 1;
                    moves_left -= rand() % 2 + 1;
                    printf("You attack the enemy and deal %d damage.\n",
                        rand() % 5 + 1);
                    if (enemies[i].health > 0) {
                        printf("The enemy attacks you and deals %d damage.\n",
                            enemies[i].damage);
                    }
                }
                if (enemies[i].health <= 0) {
                    printf("You defeated the enemy!\n");
                    enemies_left--;
                    map[enemies[i].position.y][enemies[i].position.x] = '.';
                } else {
                    printf("You were defeated by the enemy!\n");
                    moves_left = 0;
                }
            }
        }

        moves_left--;
    }

    // end game
    printf("Game over!\n");
    if (enemies_left == 0) {
        printf("Congratulations, you defeated all the enemies!\n");
    } else {
        printf("You were not able to defeat all the enemies...\n");
    }
    return 0;
}