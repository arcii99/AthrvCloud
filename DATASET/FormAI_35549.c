//FormAI DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Medieval Error Handling Program!\n");

    int health = 100;
    int shield = 50;
    int sword = 75;
    int attacked_monster = 20;

    printf("Your health is: %d\n", health);
    printf("Your shield is: %d\n", shield);
    printf("Your sword is: %d\n", sword);
    printf("The attacked monster has a damage of: %d\n", attacked_monster);

    printf("You just encountered a monster!\n");
    printf("Attacking with Sword...\n");

    if (sword <= 0) {
        printf("Your sword broke! Fleeing from battle...\n");
        exit(0);
    } else if (attacked_monster > sword) {
        int damage = attacked_monster - sword;
        health -= damage;
        printf("You dealt %d damage to the monster, but it also attacked you back!\n", sword);
        printf("Your health is now: %d\n", health);
    } else {
        sword -= attacked_monster;
        printf("You have successfully killed the monster!\n");
    }

    printf("The next monster is very strong, let's use our shield...\n");

    if (shield <= 0) {
        printf("Your shield is shattered beyond repair! Leaving the battle...\n");
        exit(0);
    } else if (attacked_monster > shield) {
        int damage = attacked_monster - shield;
        health -= damage;
        printf("You block the attack with your shield, but it still dealt %d damage.\n", damage);
        printf("Your health is now: %d\n", health);
    } else {
        shield -= attacked_monster;
        printf("You have successfully blocked the attack and killed the monster!\n");
    }

    printf("The third monster is too strong for just a shield, let's use both our sword and shield...\n");

    if (sword <= 0 || shield <= 0) {
        printf("You do not have the proper equipment to battle and must escape!\n");
        exit(0);
    } else if (attacked_monster > (sword + shield)) {
        int damage = attacked_monster - (sword + shield);
        health -= damage;
        printf("You use both your sword and shield to fight, but the monster still deals %d damage.\n", damage);
        printf("Your health is now: %d\n", health);
    } else {
        sword -= attacked_monster/2;
        shield -= attacked_monster/2;
        printf("You have successfully killed the monster with both your sword and shield!\n");
    }

    printf("Thank you for using the Medieval Error Handling Program!\n");
    return 0;
}