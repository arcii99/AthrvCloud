//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player_hp = 100;
    int enemy_hp = 50 + rand() % 50; // random enemy health between 50-100
    int player_damage = 10;
    int enemy_damage = 5 + rand() % 10; // random enemy damage between 5-15
    int round = 1;

    printf("You are walking in a peaceful meadow when suddenly a hostile mushroom appears!\n");

    while (player_hp > 0 && enemy_hp > 0) {
        printf("------------------------\n");
        printf("Round %d\n", round);
        printf("Player HP: %d\n", player_hp);
        printf("Enemy HP: %d\n", enemy_hp);

        // player turn
        int player_turn_damage = player_damage + rand() % 10; // random damage between 10-20
        printf("You attack the mushroom for %d damage!\n", player_turn_damage);
        enemy_hp -= player_turn_damage;

        // check if enemy is defeated
        if (enemy_hp <= 0) {
            printf("You have defeated the mushroom! Congratulations!\n");
            break;
        }

        // enemy turn
        int enemy_turn_damage = enemy_damage + rand() % 5; // random damage between 5-10
        printf("The mushroom attacks you for %d damage!\n", enemy_turn_damage);
        player_hp -= enemy_turn_damage;

        // check if player has been defeated
        if (player_hp <= 0) {
            printf("You have been defeated by the mushroom. Game Over.\n");
            break;
        }

        round++;
    }

    printf("------------------------\n");
    printf("Final Results\n");
    printf("Player HP: %d\n", player_hp);
    printf("Enemy HP: %d\n", enemy_hp);

    return 0;
}