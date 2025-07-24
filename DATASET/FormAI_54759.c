//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

/* Define the player struct */
typedef struct {
    int x;
    int y;
} Player;

/* Define the enemy struct */
typedef struct {
    int x;
    int y;
} Enemy;

/* Define the item struct */
typedef struct {
    int x;
    int y;
    char type; /* 'P' for potion, 'G' for gold */
} Item;

/* Declare functions */
void generateLevel(char level[HEIGHT][WIDTH], Player *player, Enemy enemies[], Item items[]);
void printLevel(char level[HEIGHT][WIDTH], Player *player);
void movePlayer(char level[HEIGHT][WIDTH], Player *player);
void moveEnemies(char level[HEIGHT][WIDTH], Enemy enemies[]);
void pickUpItem(Player *player, Item items[]);

int main() {
    char level[HEIGHT][WIDTH];
    Player player = {0};
    Enemy enemies[3];
    Item items[3];
    srand(time(NULL));
    generateLevel(level, &player, enemies, items);
    while (1) {
        printLevel(level, &player);
        movePlayer(level, &player);
        moveEnemies(level, enemies);
        pickUpItem(&player, items);
    }
    return 0;
}

/* Generates a random level with walls and enemies and items */
void generateLevel(char level[HEIGHT][WIDTH], Player *player, Enemy enemies[], Item items[]) {
    /* Fill level with walls */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
                level[i][j] = '#';
            } else {
                level[i][j] = ' ';
            }
        }
    }
    /* Place player in center of level */
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;
    level[player->y][player->x] = '@';
    /* Place enemies randomly */
    for (int i = 0; i < 3; i++) {
        int x = rand() % (WIDTH - 2) + 1;
        int y = rand() % (HEIGHT - 2) + 1;
        enemies[i].x = x;
        enemies[i].y = y;
        level[y][x] = 'E';
    }
    /* Place items randomly */
    for (int i = 0; i < 3; i++) {
        int x = rand() % (WIDTH - 2) + 1;
        int y = rand() % (HEIGHT - 2) + 1;
        char type = (rand() % 2 == 0) ? 'P' : 'G';
        items[i].x = x;
        items[i].y = y;
        items[i].type = type;
        level[y][x] = type;
    }
}

/* Prints the level */
void printLevel(char level[HEIGHT][WIDTH], Player *player) {
    system("clear"); /* Clears the console */
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (player->x == j && player->y == i) {
                printf("@");
            } else {
                printf("%c", level[i][j]);
            }
        }
        printf("\n");
    }
}

/* Moves the player based on user input */
void movePlayer(char level[HEIGHT][WIDTH], Player *player) {
    printf("Use arrow keys to move, press q to quit: ");
    char move;
    scanf(" %c", &move);
    switch (move) {
        case 'q':
            exit(0);
        case 'w':
            if (level[player->y - 1][player->x] != '#') {
                player->y--;
                level[player->y + 1][player->x] = ' ';
            }
            break;
        case 'a':
            if (level[player->y][player->x - 1] != '#') {
                player->x--;
                level[player->y][player->x + 1] = ' ';
            }
            break;
        case 's':
            if (level[player->y + 1][player->x] != '#') {
                player->y++;
                level[player->y - 1][player->x] = ' ';
            }
            break;
        case 'd':
            if (level[player->y][player->x + 1] != '#') {
                player->x++;
                level[player->y][player->x - 1] = ' ';
            }
            break;
    }
}

/* Moves the enemies randomly */
void moveEnemies(char level[HEIGHT][WIDTH], Enemy enemies[]) {
    for (int i = 0; i < 3; i++) {
        int direction = rand() % 4;
        int x = enemies[i].x;
        int y = enemies[i].y;
        switch (direction) {
            case 0:
                if (level[y - 1][x] != '#') {
                    enemies[i].y--;
                }
                break;
            case 1:
                if (level[y + 1][x] != '#') {
                    enemies[i].y++;
                }
                break;
            case 2:
                if (level[y][x - 1] != '#') {
                    enemies[i].x--;
                }
                break;
            case 3:
                if (level[y][x + 1] != '#') {
                    enemies[i].x++;
                }
                break;
        }
    }
}

/* Picks up an item if the player is on the square */
void pickUpItem(Player *player, Item items[]) {
    for (int i = 0; i < 3; i++) {
        if (player->x == items[i].x && player->y == items[i].y) {
            if (items[i].type == 'P') {
                printf("You picked up a health potion!\n");
            } else {
                printf("You picked up some gold!\n");
            }
            items[i].x = -1;
            items[i].y = -1;
        }
    }
}