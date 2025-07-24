//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>

#define MAX_HEALTH 100 // Maximum health a character can have

typedef struct character {
    char name[20];
    int health;
    int attack;
} Character;

void attackCharacter(Character* attacker, Character* victim) {
    victim->health -= attacker->attack;
    if (victim->health < 0) {
        victim->health = 0;
    }
    printf("%s attacked %s for %d damage.\n", attacker->name, victim->name, attacker->attack);
}

int main() {
    Character player = {"Player", MAX_HEALTH, 25};
    Character enemy = {"Enemy", MAX_HEALTH, 10};

    printf("Combat has begun! %s vs %s\n", player.name, enemy.name);

    while (player.health > 0 && enemy.health > 0) {
        attackCharacter(&player, &enemy);
        attackCharacter(&enemy, &player);
        printf("%s's health: %d\n", player.name, player.health);
        printf("%s's health: %d\n", enemy.name, enemy.health);
    }

    if (player.health <= 0) {
        printf("You have been defeated... GAME OVER.\n");
    } else {
        printf("Congratulations! You have won the battle.\n");
    }

    return 0;
}