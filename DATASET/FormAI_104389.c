//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for the player
struct player {
    int x, y;
    char icon;
    int score;
    int level;
};

// Function to create the game map with walls and food
void createMap(char map[20][20], int *foodx, int *foody) {
    // First create the outer walls
    for (int i = 0; i < 20; i++) {
        map[0][i] = '#';
        map[19][i] = '#';
        map[i][0] = '#';
        map[i][19] = '#';
    }
    // Then place the food randomly inside the map
    srand(time(NULL));
    *foodx = rand() % 18 + 1;
    *foody = rand() % 18 + 1;
    map[*foodx][*foody] = 'O';
}

// Function to move the player and update score
void movePlayer(struct player *p, char map[20][20], int foodx, int foody) {
    char move;
    printf("Enter a direction (w/a/s/d): ");
    scanf(" %c", &move);
    switch (move) {
        case 'w':
            if (map[p->x-1][p->y] != '#') {
                p->x--;
            }
            break;
        case 'a':
            if (map[p->x][p->y-1] != '#') {
                p->y--;
            }
            break;
        case 's':
            if (map[p->x+1][p->y] != '#') {
                p->x++;
            }
            break;
        case 'd':
            if (map[p->x][p->y+1] != '#') {
                p->y++;
            }
            break;
        default:
            printf("Invalid move!\n");
            break;
    }
    // Check if player has reached the food
    if (p->x == foodx && p->y == foody) {
        p->score++;
        p->level++;
        createMap(map, &foodx, &foody);
    }
}

// Function to print the map and the player's score
void printMap(struct player p, char map[20][20]) {
    system("clear"); // Clear the terminal screen
    printf("Score: %d\n", p.score);
    printf("Level: %d\n", p.level);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == p.x && j == p.y) {
                printf("%c", p.icon);
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    struct player p = {1, 1, 'X', 0, 1};
    char map[20][20];
    int foodx, foody;
    createMap(map, &foodx, &foody);
    while (1) {
        printMap(p, map);
        movePlayer(&p, map, foodx, foody);
    }
    return 0;
}