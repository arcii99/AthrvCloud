//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_STARS 100
#define MAX_ENEMIES 10

struct Position {
    int x;
    int y;
};

struct Star {
    struct Position position;
    int size;
};

struct Enemy {
    struct Position position;
    int health;
    int damage;
};

struct Player {
    struct Position position;
    int health;
    int ammo;
    int score;
};

void createStars(struct Star stars[], int numStars) {
    for (int i = 0; i < numStars; i++) {
        stars[i].position.x = rand() % 100;
        stars[i].position.y = rand() % 100;
        stars[i].size = rand() % 3 + 1;
    }
}

void displayStars(struct Star stars[], int numStars) {
    for (int i = 0; i < numStars; i++) {
        printf("* size %d at (%d,%d)\n", stars[i].size, stars[i].position.x, stars[i].position.y);
    }
}

void createEnemies(struct Enemy enemies[], int numEnemies) {
    for (int i = 0; i < numEnemies; i++) {
        enemies[i].position.x = rand() % 100;
        enemies[i].position.y = rand() % 100;
        enemies[i].health = rand() % 3 + 1;
        enemies[i].damage = rand() % 2 + 1;
    }
}

void displayEnemies(struct Enemy enemies[], int numEnemies) {
    for (int i = 0; i < numEnemies; i++) {
        printf("Enemy %d at (%d,%d), health %d, damage %d\n", i+1, enemies[i].position.x, enemies[i].position.y, enemies[i].health, enemies[i].damage);
    }
}

void updatePlayer(struct Player *player) {
    player->ammo -= 1;
    player->score += 10;
}

void displayPlayer(struct Player *player) {
    printf("Player at (%d,%d), health %d, ammo %d, score %d\n", player->position.x, player->position.y, player->health, player->ammo, player->score);
}

int main() {
    srand(time(0));
    struct Star stars[MAX_STARS];
    struct Enemy enemies[MAX_ENEMIES];
    struct Player player = {{50, 50}, 3, 10, 0};
    createStars(stars, MAX_STARS);
    createEnemies(enemies, MAX_ENEMIES);

    printf("Welcome to Procedural Space Adventure!\n");

    while (player.health > 0 && player.ammo > 0) {
        printf("\nStar Map:\n");
        displayStars(stars, MAX_STARS);

        printf("\nEnemy Status:\n");
        displayEnemies(enemies, MAX_ENEMIES);

        printf("\nPlayer Status:\n");
        displayPlayer(&player);

        struct Position targetPosition;
        printf("\nEnter target x y coordinates: ");
        scanf("%d %d", &targetPosition.x, &targetPosition.y);

        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].health > 0 && enemies[i].position.x == targetPosition.x && enemies[i].position.y == targetPosition.y) {
                printf("Player shot enemy %d\n", i+1);
                enemies[i].health -= 1;
                if (enemies[i].health <= 0) {
                    printf("Enemy %d has been destroyed!\n", i+1);
                    updatePlayer(&player);
                }
                break;
            }
        }
    }

    printf("\nGame over!\n");
    if (player.health <= 0) {
        printf("You have died. Better luck next time!\n");
    } else {
        printf("Congratulations! You have saved humanity and scored %d points!\n", player.score);
    }
    return 0;
}