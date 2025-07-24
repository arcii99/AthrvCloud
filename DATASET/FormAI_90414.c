//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ENEMIES 3
#define MAX_HEALTH 10

int player_position = MAP_SIZE / 2;
int enemies_positions[MAX_ENEMIES];

int player_health = MAX_HEALTH;
int enemies_health[MAX_ENEMIES];

void generate_enemies() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies_positions[i] = rand() % MAP_SIZE;
        enemies_health[i] = rand() % MAX_HEALTH + 1;
    }
}

void print_map() {
    printf("|=|");
    for (int i = 0; i < MAP_SIZE; i++) {
        if (i == player_position) {
            printf("P");
        } else {
            int enemy_found = 0;
            for (int j = 0; j < MAX_ENEMIES; j++) {
                if (enemies_positions[j] == i) {
                    enemy_found = 1;
                    printf("E");
                    break;
                }
            }
            if (!enemy_found) {
                printf("-");
            }
        }
        printf("|");
    }
    printf("|=|\n");
}

void print_health() {
    printf("Player Health: %d\n", player_health);
    for (int i = 0; i < MAX_ENEMIES; i++) {
        printf("Enemy %d Health: %d\n", i+1, enemies_health[i]);
    }
}

int main() {
    generate_enemies();

    while (player_health > 0 && (enemies_health[0] > 0 || enemies_health[1] > 0 || enemies_health[2] > 0)) {
        print_map();
        print_health();

        printf("Enter your move (L/R): ");
        char move;
        scanf(" %c", &move);

        if (move == 'L') {
            player_position--;
        } else if (move == 'R') {
            player_position++;
        } else {
            printf("Invalid move!\n");
            continue;
        }

        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies_positions[i] == player_position) {
                enemies_health[i]--;
                if (enemies_health[i] == 0) {
                    printf("Enemy %d defeated!\n", i+1);
                } else {
                    printf("Player hit enemy %d!\n", i+1);
                }
            }
        }

        for (int i = 0; i < MAX_ENEMIES; i++) {
            int enemy_move = rand() % 3 - 1;
            enemies_positions[i] += enemy_move;
            if (enemies_positions[i] < 0) {
                enemies_positions[i] = 0;
            } else if (enemies_positions[i] >= MAP_SIZE) {
                enemies_positions[i] = MAP_SIZE - 1;
            }

            if (enemies_positions[i] == player_position) {
                player_health--;
                printf("Enemy %d hit player!\n", i+1);
            }
        }

        printf("\n");
    }

    if (player_health > 0) {
        printf("You have successfully defeated all of the enemies!\n");
    } else {
        printf("GAME OVER\n");
    }

    return 0;
}