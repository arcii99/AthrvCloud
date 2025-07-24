//FormAI DATASET v1.0 Category: Funny ; Style: brave
#include <stdio.h>

int main() {
    printf("The brave knight sets off into the forest!\n");
    int enemies_defeated = 0;
    int health = 100;
    int num_arrows = 10;
    int num_potions = 3;
    while (health > 0) {
        printf("A goblin appears!\n");
        int enemy_health = 25;
        while (enemy_health > 0) {
            printf("The knight takes aim with his bow...\n");
            if (num_arrows > 0) {
                printf("* twang *\n");
                enemy_health -= 10;
                num_arrows--;
            } else {
                printf("The knight is out of arrows! He draws his sword...\n");
                enemy_health -= 5;
            }
        }
        printf("The goblin falls to the ground, defeated!\n");
        enemies_defeated++;
        health -= 10;
        printf("The knight's health is now %d\n", health);
        if (health <= 0) {
            printf("The knight has been slain in battle!\n");
            break;
        }
        if (enemies_defeated % 3 == 0) {
            printf("The knight finds a chest filled with potions!\n");
            num_potions += 3;
        }
        printf("The knight continues his journey...\n");
        printf("Suddenly, a group of orcs attack!\n");
        int num_orcs = 3;
        while (num_orcs > 0 && health > 0) {
            printf("The knight takes on an orc!\n");
            int orc_health = 40;
            while (orc_health > 0) {
                printf("The knight swings his sword...\n");
                orc_health -= 15;
            }
            printf("The orc falls to the ground!\n");
            num_orcs--;
            health -= 20;
            printf("The knight's health is now %d\n", health);
            if (health <= 0) {
                printf("The knight has been slain in battle!\n");
                break;
            }
        }
        if (health <= 0) {
            break;
        }
        printf("The knight emerges victorious from the battle with the orcs!\n");
        printf("The knight discovers a magical elixir!\n");
        health += 50;
        printf("The knight's health is now %d\n", health);
        printf("The knight continues his journey...\n");
        printf("The end of the adventure is near!\n");
    }
    printf("Game over!\n");
    return 0;
}