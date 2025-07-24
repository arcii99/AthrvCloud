//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char map[ROWS][COLS];
    Position player;
} Game;

void initGame(Game* game);
void generateMap(Game* game);
void drawMap(Game* game);
void movePlayer(Game* game, int x, int y);

int main() {
    Game game;
    initGame(&game);

    char input;
    do {
        drawMap(&game);
        printf("\n\nEnter movement (w,a,s,d): ");
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                movePlayer(&game, -1, 0);
                break;
            case 'a':
                movePlayer(&game, 0, -1);
                break;
            case 's':
                movePlayer(&game, 1, 0);
                break;
            case 'd':
                movePlayer(&game, 0, 1);
                break;
            case 'q':
                printf("\n\nExiting game...");
                exit(0);
                break;
            default:
                printf("\n\nInvalid input! Please enter (w,a,s,d) to move or 'q' to quit.");
                break;
        }
    } while (1);

    return 0;
}

void initGame(Game* game) {
    srand(time(NULL));
    generateMap(game);
    game->player.x = ROWS/2;
    game->player.y = COLS/2;
    game->map[game->player.x][game->player.y] = '@';
}

void generateMap(Game* game) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int val = rand() % 10;
            if (val < 3) {
                game->map[i][j] = '#';
            } else {
                game->map[i][j] = '.';
            }
        }
    }
}

void drawMap(Game* game) {
    system("clear");
    printf("\n\n");
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", game->map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(Game* game, int x, int y) {
    int newX = game->player.x + x;
    int newY = game->player.y + y;
    if (newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS || game->map[newX][newY] == '#') {
        printf("\n\nCannot move there! Press any key to continue...");
        getchar();
        return;
    }
    game->map[game->player.x][game->player.y] = '.';
    game->player.x = newX;
    game->player.y = newY;
    game->map[newX][newY] = '@';
}