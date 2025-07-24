//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 75;
    int player_damage = 0;
    int enemy_damage = 0;
    int round_count = 1;
    
    printf("You have entered the battlefield. Get ready to fight!\n");
    while(player_health > 0 && enemy_health > 0) {
        printf("Round %d:\n", round_count);
        player_damage = rand() % 20 + 5;
        enemy_damage = rand() % 15 + 5;

        printf("You attack the enemy and deal %d damage.\n", player_damage);
        enemy_health -= player_damage;
        printf("Enemy's health: %d\n", enemy_health);

        printf("The enemy attacks you and deals %d damage.\n", enemy_damage);
        player_health -= enemy_damage;
        printf("Your health: %d\n", player_health);

        round_count++;
        printf("\n");
    }

    if(player_health <= 0) {
        printf("Oh no, you have died. Game over!\n");
    } else if(enemy_health <= 0) {
        printf("You have triumphed over your enemy. You are victorious!\n");
    }

    return 0;
}