//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int level = 1;

struct roguelike {
    char map[SIZE][SIZE];
    int player_x;
    int player_y;
};

void init_roguelike(struct roguelike *game) {
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            game->map[i][j] = '#';
        }
    }

    /* Procedural Generation for Walls*/
    srand(time(NULL));
    int num_walls = 100 + rand() % 50;

    for(i = 0; i < num_walls; i++) {
        int coord_x = rand() % (SIZE - 2) + 1;
        int coord_y = rand() % (SIZE - 2) + 1;

        game->map[coord_y][coord_x] = '#';
    }

    /* Procedural Generation for Player*/
    int player_x = rand() % (SIZE - 2) + 1;
    int player_y = rand() % (SIZE - 2) + 1;

    game->player_x = player_x;
    game->player_y = player_y;
    game->map[player_y][player_x] = '@';

    /* Procedural Generation for Stairs*/
    int stairs_x = rand() % (SIZE - 2) + 1;
    int stairs_y = rand() % (SIZE - 2) + 1;

    game->map[stairs_y][stairs_x] = '>';

    printf("Welcome to level %d of the Rogue-like game!\n", level);
    printf("Find the stairs to advance to the next level!\n\n");
}

int move_player(struct roguelike *game, char direction) {
    int player_x = game->player_x;
    int player_y = game->player_y;

    switch(direction) {
        case 'w':
            if(game->map[player_y - 1][player_x] == '#') {
                return -1;
            } else {
                game->map[player_y][player_x] = '.';
                game->player_y -= 1;
                game->map[player_y][player_x] = '@';
            }
            break;
        case 's':
            if(game->map[player_y + 1][player_x] == '#') {
                return -1;
            } else {
                game->map[player_y][player_x] = '.';
                game->player_y += 1;
                game->map[player_y][player_x] = '@';
            }
            break;
        case 'a':
            if(game->map[player_y][player_x - 1] == '#') {
                return -1;
            } else {
                game->map[player_y][player_x] = '.';
                game->player_x -= 1;
                game->map[player_y][player_x] = '@';
            }
            break;
        case 'd':
            if(game->map[player_y][player_x + 1] == '#') {
                return -1;
            } else {
                game->map[player_y][player_x] = '.';
                game->player_x += 1;
                game->map[player_y][player_x] = '@';
            }
            break;
        default:
            printf("Invalid direction!\n");
            return -1;
    }

    if(game->map[game->player_y][game->player_x] == '>') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct roguelike game;
    char direction;
    int result;

    init_roguelike(&game);

    while(1) {
        int i, j;

        for(i = 0; i < SIZE; i++) {
            for(j = 0; j < SIZE; j++) {
                printf("%c ", game.map[i][j]);
            }
            printf("\n");
        }

        printf("\nEnter direction (w, a, s, d): ");
        scanf(" %c", &direction);

        result = move_player(&game, direction);

        if(result == -1) {
            printf("Cannot move in that direction!\n");
        } else if(result == 1) {
            level++;
            printf("Congratulations! You have advanced to level %d!\n", level);
            init_roguelike(&game);
        }
    }

    return 0;
}