//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>

// Declare variables
unsigned int player_health = 100;
unsigned int enemy_health = 100;
unsigned int player_attack = 25;
unsigned int enemy_attack = 20;

int main() {

    printf("A medieval battle is about to begin!\n");
    printf("Player health: %d\n", player_health);
    printf("Enemy health: %d\n", enemy_health);
    printf("Player attack: %d\n", player_attack);
    printf("Enemy attack: %d\n", enemy_attack);

    // Round 1
    printf("====== ROUND 1 ======\n");
    enemy_health = enemy_health - player_attack;
    player_health = player_health - enemy_attack;

    printf("Player strikes enemy! Enemy health now: %d\n", enemy_health);
    printf("Enemy strikes player! Player health now: %d\n", player_health);

    // Round 2
    printf("\n====== ROUND 2 ======\n");
    player_health = player_health ^ enemy_health;
    enemy_health = enemy_health ^ player_health;
    player_health = player_health ^ enemy_health;

    printf("Player and enemy swap health!\n");
    printf("Player health now: %d\n", player_health);
    printf("Enemy health now: %d\n", enemy_health);

    // Round 3
    printf("\n====== ROUND 3 ======\n");
    player_attack = player_attack << 1;
    enemy_attack = enemy_attack >> 1;

    printf("Player doubles attack! Player attack now: %d\n", player_attack);
    printf("Enemy halves attack! Enemy attack now: %d\n", enemy_attack);

    // Round 4
    printf("\n====== ROUND 4 ======\n");
    enemy_health = ~enemy_health;

    printf("Enemy curses player! Player's health inverted! Player health now: %d\n", player_health);

    // End of battle
    printf("\n====== END OF BATTLE ======\n");
    if (player_health > enemy_health) {
        printf("Player emerges victorious!\n");
    } else if (enemy_health > player_health) {
        printf("Enemy emerges victorious!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}