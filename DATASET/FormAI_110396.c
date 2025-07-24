//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ENEMIES 3
#define MAX_SHOTS 3

typedef struct {
    int x, y;
} Position;

typedef struct {
    int health;
    Position position;
} EnemyShip;

typedef struct {
    Position position;
    int active;
} Shot;

void initialize(Position *playerPosition, EnemyShip *enemies, Shot *shots) {
    srand(time(0));
    // Initialize player position
    playerPosition->x = MAP_SIZE / 2;
    playerPosition->y = MAP_SIZE / 2;

    // Initialize enemies
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].health = 100;
        enemies[i].position.x = rand() % MAP_SIZE;
        enemies[i].position.y = rand() % MAP_SIZE;
    }

    // Initialize shots
    for (int i = 0; i < MAX_SHOTS; i++) {
        shots[i].position.x = -1;
        shots[i].position.y = -1;
        shots[i].active = 0;
    }
}

void printMap(Position playerPosition, EnemyShip *enemies, Shot *shots) {
    printf(" ");
    for (int i = 0; i < MAP_SIZE; i++) {
        printf("%d", i);
    }
    printf("\n");

    for (int y = 0; y < MAP_SIZE; y++) {
        printf("%d", y);
        for (int x = 0; x < MAP_SIZE; x++) {
            if (x == playerPosition.x && y == playerPosition.y) {
                printf("P");
            } else {
                int hasEnemy = 0;
                for (int i = 0; i < MAX_ENEMIES; i++) {
                    if (enemies[i].health > 0 && enemies[i].position.x == x && enemies[i].position.y == y) {
                        printf("E");
                        hasEnemy = 1;
                        break;
                    }
                }
                if (!hasEnemy) {
                    int hasShot = 0;
                    for (int i = 0; i < MAX_SHOTS; i++) {
                        if (shots[i].active && shots[i].position.x == x && shots[i].position.y == y) {
                            printf("*");
                            hasShot = 1;
                            break;
                        }
                    }
                    if (!hasShot) {
                        printf(".");
                    }
                }
            }
        }
        printf("\n");
    }
}

void shoot(Position playerPosition, Shot *shots) {
    for (int i = 0; i < MAX_SHOTS; i++) {
        if (!shots[i].active) {
            shots[i].position.x = playerPosition.x;
            shots[i].position.y = playerPosition.y;
            shots[i].active = 1;
            break;
        }
    }
}

void moveEnemies(EnemyShip *enemies) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].health > 0) {
            enemies[i].position.x += rand() % 3 - 1;
            enemies[i].position.y += rand() % 3 - 1;

            if (enemies[i].position.x < 0) {
                enemies[i].position.x = 0;
            } else if (enemies[i].position.x >= MAP_SIZE) {
                enemies[i].position.x = MAP_SIZE - 1;
            }

            if (enemies[i].position.y < 0) {
                enemies[i].position.y = 0;
            } else if (enemies[i].position.y >= MAP_SIZE) {
                enemies[i].position.y = MAP_SIZE - 1;
            }
        }
    }
}

void moveShots(Shot *shots) {
    for (int i = 0; i < MAX_SHOTS; i++) {
        if (shots[i].active) {
            shots[i].position.y--;

            if (shots[i].position.y < 0) {
                shots[i].active = 0;
            }
        }
    }
}

void checkCollisions(Position playerPosition, EnemyShip *enemies, Shot *shots) {
    // Check enemy collisions with player and shots
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].health > 0) {
            if (enemies[i].position.x == playerPosition.x && enemies[i].position.y == playerPosition.y) {
                printf("Game over!\n");
                exit(0);
            }

            for (int j = 0; j < MAX_SHOTS; j++) {
                if (shots[j].active && shots[j].position.x == enemies[i].position.x && shots[j].position.y == enemies[i].position.y) {
                    enemies[i].health -= 10;
                    shots[j].active = 0;
                    printf("Enemy hit! Health: %d\n", enemies[i].health);
                    break;
                }
            }
        }
    }
}

int main() {
    Position playerPosition;
    EnemyShip enemies[MAX_ENEMIES];
    Shot shots[MAX_SHOTS];

    initialize(&playerPosition, enemies, shots);

    while (1) {
        system("clear");
        printMap(playerPosition, enemies, shots);
        printf("Move (WASD), shoot (space): ");

        char input;
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                playerPosition.y--;
                break;
            case 'a':
                playerPosition.x--;
                break;
            case 's':
                playerPosition.y++;
                break;
            case 'd':
                playerPosition.x++;
                break;
            case ' ':
                shoot(playerPosition, shots);
                break;
        }

        moveEnemies(enemies);
        moveShots(shots);
        checkCollisions(playerPosition, enemies, shots);
    }

    return 0;
}