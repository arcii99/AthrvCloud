//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_WIDTH 70
#define BOARD_HEIGHT 20
#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 1
#define ENEMY_WIDTH 3
#define ENEMY_HEIGHT 1

// Structs
typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int width, height;
    char sprite;
} Entity;

// Function prototypes
void draw_board(Entity player, Entity enemy);
void move_player(Entity *player, char direction);
void move_enemy(Entity *enemy);
int check_collision(Entity player, Entity enemy);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize player and enemy
    Entity player = { { BOARD_WIDTH/2 - PLAYER_WIDTH/2, BOARD_HEIGHT-2 }, PLAYER_WIDTH, PLAYER_HEIGHT, '#' };
    Entity enemy = { { rand() % BOARD_WIDTH, 0 }, ENEMY_WIDTH, ENEMY_HEIGHT, 'X' };

    // Draw initial board
    draw_board(player, enemy);

    // Main game loop
    char input;
    while (1) {
        printf("Enter direction (l/r): ");
        scanf(" %c", &input);

        // Move player
        move_player(&player, input);

        // Move enemy
        move_enemy(&enemy);

        // Check for collision
        if (check_collision(player, enemy)) {
            printf("Game over!\n");
            break;
        }

        // Draw updated board
        draw_board(player, enemy);
    }

    return 0;
}

void draw_board(Entity player, Entity enemy) {
    // Clear screen
    system("clear");

    // Draw top of board
    for (int i = 0; i < BOARD_WIDTH+2; i++) {
        printf("-");
    }
    printf("\n");

    // Draw board contents
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (x >= player.position.x && x < player.position.x + player.width &&
                y >= player.position.y && y < player.position.y + player.height) {
                printf("%c", player.sprite);
            }
            else if (x >= enemy.position.x && x < enemy.position.x + enemy.width &&
                     y >= enemy.position.y && y < enemy.position.y + enemy.height) {
                printf("%c", enemy.sprite);
            }
            else {
                printf(" ");
            }
        }
        printf("|\n");
    }

    // Draw bottom of board
    for (int i = 0; i < BOARD_WIDTH+2; i++) {
        printf("-");
    }
    printf("\n");
}

void move_player(Entity *player, char direction) {
    if (direction == 'l' && player->position.x > 0) {
        player->position.x--;
    }
    else if (direction == 'r' && player->position.x + player->width < BOARD_WIDTH) {
        player->position.x++;
    }
}

void move_enemy(Entity *enemy) {
    if (enemy->position.y < BOARD_HEIGHT) {
        enemy->position.y++;
    }
    else {
        enemy->position.x = rand() % BOARD_WIDTH;
        enemy->position.y = 0;
    }
}

int check_collision(Entity player, Entity enemy) {
    if (player.position.x + player.width >= enemy.position.x &&
        player.position.x <= enemy.position.x + enemy.width &&
        player.position.y + player.height >= enemy.position.y &&
        player.position.y <= enemy.position.y + enemy.height) {
        return 1;
    }
    else {
        return 0;
    }
}