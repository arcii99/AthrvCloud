//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int health;
    int strength;
    int speed;
} Player;

typedef struct {
    char name[20];
    int health;
    int strength;
    int speed;
} Enemy;

void battle(Player *player, Enemy *enemy) {
    printf("BATTLE BEGINS: %s VS %s\n", player->name, enemy->name);
    
    while (player->health > 0 && enemy->health > 0) {
        printf("\n%s health: %d, %s health: %d\n", player->name, player->health, enemy->name, enemy->health);
        int player_damage = player->strength * (rand() % 10 + 1) / 10;
        int enemy_damage = enemy->strength * (rand() % 10 + 1) / 10;
        if (player->speed >= enemy->speed) {
            enemy->health -= player_damage;
            printf("%s attacks %s and deals %d damage!\n", player->name, enemy->name, player_damage);
            if (enemy->health <= 0) {
                printf("%s has won!\n", player->name);
                break;
            }
            player->health -= enemy_damage;
            printf("%s attacks %s and deals %d damage!\n", enemy->name, player->name, enemy_damage);
            if (player->health <= 0) {
                printf("%s has won!\n", enemy->name);
                break;
            }
        }
        else {
            player->health -= enemy_damage;
            printf("%s attacks %s and deals %d damage!\n", enemy->name, player->name, enemy_damage);
            if (player->health <= 0) {
                printf("%s has won!\n", enemy->name);
                break;
            }
            enemy->health -= player_damage;
            printf("%s attacks %s and deals %d damage!\n", player->name, enemy->name, player_damage);
            if (enemy->health <= 0) {
                printf("%s has won!\n", player->name);
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    int num_enemies = rand() % 5 + 1;
    printf("WELCOME TO THE OUTER SPACE ADVENTURE! GET READY TO FIGHT %d ENEMIES!\n\n", num_enemies);
    
    Player player = {"You", 50, 8, 5};
    printf("YOUR STATS: Health - %d, Strength - %d, Speed - %d\n\n", player.health, player.strength, player.speed);
    
    for (int i = 1; i <= num_enemies; i++) {
        Enemy enemy = {"Enemy", rand() % 30 + 20, rand() % 6 + 3, rand() % 4 + 1};
        printf("ENEMY %d STATS: Health - %d, Strength - %d, Speed - %d\n", i, enemy.health, enemy.strength, enemy.speed);
        battle(&player, &enemy);
        printf("\n");
    }
    
    printf("THANK YOU FOR PLAYING!\n");
    return 0;
}