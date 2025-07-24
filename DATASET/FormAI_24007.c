//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int health = 100;
int gold = 0;
char weapon[20];
char choice[20];

void battle()
{
    char enemy[50] = "Dragon";
    int enemyHealth = 100;

    printf("\nYou have encountered a %s!\n", enemy);

    while (enemyHealth > 0 && health > 0)
    {
        int damage = rand() % 30 + 1;
        printf("The %s attacks you and deals %d damage\n", enemy, damage);
        health -= damage;
        printf("Your health is now %d\n\n", health);

        printf("What action will you take?\n1. Attack\n2. Run away\n\n");
        fgets(choice, sizeof(choice), stdin);

        if (strcmp(choice, "1\n") == 0)
        {
            damage = rand() % 50 + 1;
            printf("You attack the %s and deal %d damage\n", enemy, damage);
            enemyHealth -= damage;
            printf("%s health is now %d\n\n", enemy, enemyHealth);
        }
        else if (strcmp(choice, "2\n") == 0)
        {
            printf("You run away from the battle!\n\n");
            break;
        }
        else
        {
            printf("Invalid input, try again\n\n");
        }
    }

    if (health <= 0)
    {
        printf("You have died in combat!\n\n");
        exit(0);
    }
    else if (enemyHealth <= 0)
    {
        printf("You have defeated the %s and gained 50 gold!\n\n", enemy);
        gold += 50;
    }
}

void shop()
{
    printf("\nWelcome to the Shop!\n\n");
    printf("What would you like to buy?\n1. Sword (50 gold)\n2. Shield (25 gold)\n3. Exit\n\n");
    fgets(choice, sizeof(choice), stdin);

    if (strcmp(choice, "1\n") == 0)
    {
        if (gold >= 50)
        {
            strcpy(weapon, "Sword");
            gold -= 50;
            printf("\nYou have purchased the Sword for 50 gold!\n\n");
        }
        else
        {
            printf("\nYou don't have enough gold to buy the Sword, come back later!\n\n");
        }
    }
    else if (strcmp(choice, "2\n") == 0)
    {
        if (gold >= 25)
        {
            printf("\nYou have purchased the Shield for 25 gold!\n\n");
            gold -= 25;
        }
        else
        {
            printf("\nYou don't have enough gold to buy the Shield, come back later!\n\n");
        }
    }
    else if (strcmp(choice, "3\n") == 0)
    {
        printf("\nThank you for visiting the Shop!\n\n");
    }
    else
    {
        printf("\nInvalid input, try again!\n\n");
    }
}

int main()
{
    printf("Welcome to Brave Adventure!\n\n");

    while (1)
    {
        printf("What would you like to do?\n1. Battle\n2. Shop\n3. Status\n4. Exit\n\n");
        fgets(choice, sizeof(choice), stdin);

        if (strcmp(choice, "1\n") == 0)
        {
            battle();
        }
        else if (strcmp(choice, "2\n") == 0)
        {
            shop();
        }
        else if (strcmp(choice, "3\n") == 0)
        {
            printf("\nHealth: %d\nGold: %d\nWeapon: %s\n\n", health, gold, weapon);
        }
        else if (strcmp(choice, "4\n") == 0)
        {
            printf("\nThank you for playing Brave Adventure!\n\n");
            break;
        }
        else
        {
            printf("\nInvalid input, try again!\n\n");
        }
    }

    return 0;
}