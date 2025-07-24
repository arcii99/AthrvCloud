//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int steps = 10;
    int health = 100;
    int damage = 0;
    int killed = 0;
    int weapon = 1;
    int armor = 1;
    int luck = 1;
    int enemy_health = rand() % 50 + 50;

    printf("Welcome to the Dungeon of Doom!\n");

    for(int i = 0; i < steps; i++) {
        printf("\nYou take a step forward.\n");

        int event = rand() % 5;
        if(event == 0) {
            printf("You found a health potion. Your health is now 100.\n");
            health = 100;
        }
        else if(event == 1) {
            printf("You found a sword. Your weapon level is now 2.\n");
            weapon = 2;
        }
        else if(event == 2) {
            printf("You found a shield. Your armor level is now 2.\n");
            armor = 2;
        }
        else if(event == 3) {
            printf("You found a horseshoe. Your luck level is now 2.\n");
            luck = 2;
        }
        else {
            printf("You encountered an enemy with %d health points.\n", enemy_health);

            while(enemy_health > 0) {
                int enemy_damage = rand() % 10 + 10 - armor;
                printf("The enemy did %d damage to you.\n", enemy_damage);
                health -= enemy_damage;
                if(health <= 0) {
                    printf("You died! Game over.\n");
                    return 0;
                }

                int attack = rand() % 10 + 10 + damage;
                printf("You did %d damage to the enemy.\n", attack);
                enemy_health -= attack;

                if(enemy_health <= 0) {
                    printf("You killed the enemy! Congratulations.\n");
                    killed++;
                    damage += weapon + luck;
                    enemy_health = rand() % 50 + 50;
                }
            }
        }
    }

    printf("\nYou reached the final level of the Dungeon of Doom!\n");
    printf("You killed %d enemies and your final level is %d.\n", killed, damage);
    printf("Thanks for playing!\n");

    return 0;
}