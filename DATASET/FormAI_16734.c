//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ENEMIES 10
#define MAX_PLAYERS 5

typedef struct Enemy {
    int health;
    int attack;
} Enemy;

typedef struct Player {
    int health;
    int attack;
    bool isAlive;
} Player;

void attackPlayer(Player* player, int attack) {
    player->health -= attack;
    if (player->health <= 0) {
        player->isAlive = false;
    }
}

void attackEnemy(Enemy* enemy, int attack) {
    enemy->health -= attack;
}

void fight(Player players[], Enemy enemies[], int numOfPlayers, int numOfEnemies) {
    int enemyIndex = 0;
    while (enemyIndex < numOfEnemies) {
        for (int i = 0; i < numOfPlayers; i++) {
            if (players[i].isAlive) {
                attackEnemy(&enemies[enemyIndex], players[i].attack);
                if (enemies[enemyIndex].health <= 0) {
                    enemyIndex++;
                    if (enemyIndex == numOfEnemies) {
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < numOfEnemies; i++) {
            if (enemies[i].health > 0) {
                int randomPlayerIndex = rand() % numOfPlayers;
                attackPlayer(&players[randomPlayerIndex], enemies[i].attack);
            }
        }
    }

    // print result
    printf("The battle is over!\n");
    for (int i = 0; i < numOfPlayers; i++) {
        printf("Player %d: %s\n", i+1, players[i].isAlive ? "Survived" : "Died");
    }
}

int main() {
    Player players[MAX_PLAYERS] = {
        {100, 20, true},
        {80, 30, true},
        {70, 40, true},
        {60, 50, true},
        {50, 60, true}
    };
    Enemy enemies[MAX_ENEMIES] = {
        {200, 30},
        {250, 25},
        {300, 20},
        {350, 15},
        {400, 10},
        {450, 5},
        {500, 3},
        {550, 2},
        {600, 1},
        {700, 1},
    };

    int numOfPlayers = sizeof(players)/sizeof(players[0]);
    int numOfEnemies = sizeof(enemies)/sizeof(enemies[0]);

    fight(players, enemies, numOfPlayers, numOfEnemies);

    return 0;
}