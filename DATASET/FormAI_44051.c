//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_SYMBOL '@'
#define ENEMY_SYMBOL 'E'
#define TREASURE_SYMBOL '$'

#define MAP_SIZE 20
#define ENEMY_NUM 5

struct position {
    int x;
    int y;
};

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate player position
    struct position player_pos = {MAP_SIZE/2, MAP_SIZE/2};
    
    // Generate enemy positions
    struct position enemy_pos[ENEMY_NUM];
    for (int i = 0; i < ENEMY_NUM; i++) {
        struct position pos = {rand() % MAP_SIZE, rand() % MAP_SIZE};
        enemy_pos[i] = pos;
    }
    
    // Generate treasure position
    struct position treasure_pos = {rand() % MAP_SIZE, rand() % MAP_SIZE};
    
    // Generate map
    char map[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == player_pos.x && j == player_pos.y) {
                map[i][j] = PLAYER_SYMBOL;
            }else if (i == treasure_pos.x && j == treasure_pos.y) {
                map[i][j] = TREASURE_SYMBOL;
            } else {
                int is_enemy = 0;
                for (int k = 0; k < ENEMY_NUM; k++) {
                    if (i == enemy_pos[k].x && j == enemy_pos[k].y) {
                        map[i][j] = ENEMY_SYMBOL;
                        is_enemy = 1;
                    }
                }
                if (!is_enemy) {
                    map[i][j] = '.';
                }
            }
        }
    }
    
    // Print map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}