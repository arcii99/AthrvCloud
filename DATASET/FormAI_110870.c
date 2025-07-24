//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
/*
 * Terminal-based game: "Escape the Dungeon"
 * By [Your Name Here]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    int player_x = 0, player_y = 0;
    int treasure_x = 0, treasure_y = 0;
    int enemy_x = 0, enemy_y = 0;

    srand(time(NULL));

    /* Initialize the map */
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '.';
        }
    }

    /* Place the player randomly on the map */
    player_x = rand() % MAP_SIZE;
    player_y = rand() % MAP_SIZE;
    map[player_y][player_x] = 'P';

    /* Place the treasure randomly on the map */
    do {
        treasure_x = rand() % MAP_SIZE;
        treasure_y = rand() % MAP_SIZE;
    } while (treasure_x == player_x && treasure_y == player_y);
    map[treasure_y][treasure_x] = 'T';

    /* Place the enemy randomly on the map */
    do {
        enemy_x = rand() % MAP_SIZE;
        enemy_y = rand() % MAP_SIZE;
    } while (enemy_x == player_x && enemy_y == player_y
             && enemy_x == treasure_x && enemy_y == treasure_y);
    map[enemy_y][enemy_x] = 'E';

    /* Display the map */
    printf("Welcome to Escape the Dungeon!\n");
    printf("Use the arrow keys to move the player (P) around the map.\n");
    printf("Try to reach the treasure (T) without being caught by the enemy (E)!\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    /* Game loop */
    int game_over = 0;
    while (!game_over) {
        /* Clear screen */
        system("clear");

        /* Move the enemy randomly */
        int move_dir = rand() % 4;
        switch (move_dir) {
            case 0: /* up */
                if (enemy_y > 0) {
                    map[enemy_y][enemy_x] = '.';
                    enemy_y--;
                    map[enemy_y][enemy_x] = 'E';
                }
                break;
            case 1: /* down */
                if (enemy_y < MAP_SIZE - 1) {
                    map[enemy_y][enemy_x] = '.';
                    enemy_y++;
                    map[enemy_y][enemy_x] = 'E';
                }
                break;
            case 2: /* left */
                if (enemy_x > 0) {
                    map[enemy_y][enemy_x] = '.';
                    enemy_x--;
                    map[enemy_y][enemy_x] = 'E';
                }
                break;
            case 3: /* right */
                if (enemy_x < MAP_SIZE - 1) {
                    map[enemy_y][enemy_x] = '.';
                    enemy_x++;
                    map[enemy_y][enemy_x] = 'E';
                }
                break;
        }

        /* Display the map */
        for (int i = 0; i < MAP_SIZE; i++) {
            for (int j = 0; j < MAP_SIZE; j++) {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        /* Get player input */
        printf("Move the player using the arrow keys: ");
        char input = getchar();
        while (getchar() != '\n') {} /* discard extra characters */
        
        /* Move the player */
        switch (input) {
            case 'A': case 'a': /* left */
                if (player_x > 0) {
                    map[player_y][player_x] = '.';
                    player_x--;
                    map[player_y][player_x] = 'P';
                }
                break;
            case 'D': case 'd': /* right */
                if (player_x < MAP_SIZE - 1) {
                    map[player_y][player_x] = '.';
                    player_x++;
                    map[player_y][player_x] = 'P';
                }
                break;
            case 'W': case 'w': /* up */
                if (player_y > 0) {
                    map[player_y][player_x] = '.';
                    player_y--;
                    map[player_y][player_x] = 'P';
                }
                break;
            case 'S': case 's': /* down */
                if (player_y < MAP_SIZE - 1) {
                    map[player_y][player_x] = '.';
                    player_y++;
                    map[player_y][player_x] = 'P';
                }
                break;
            default:
                printf("Invalid input!\n");
                break;
        }

        /* Check for win or loss */
        if (player_x == treasure_x && player_y == treasure_y) {
            printf("Congratulations, you escaped the dungeon!\n");
            game_over = 1;
        } else if (player_x == enemy_x && player_y == enemy_y) {
            printf("You were caught by the enemy, game over!\n");
            game_over = 1;
        }
    }

    return 0;
}