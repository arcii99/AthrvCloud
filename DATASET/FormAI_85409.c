//FormAI DATASET v1.0 Category: Game ; Style: futuristic
/* Futuristic Space Adventure Game */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int spaceship_health = 100;
    int alien_health = 100;
    int player_choice;
    int alien_choice;
    int player_damage;
    int alien_damage;
    int turn = 1;

    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the Futuristic Space Adventure Game!\n");
    printf("You are the captain of a spaceship, traveling through space. Your goal is to defeat the alien race threatening the universe.\n\n");

    while (spaceship_health > 0 && alien_health > 0)
    {
        printf("Turn %d: Your spaceship health: %d || Alien spaceship health: %d\n", turn, spaceship_health, alien_health);
        printf("Choose your action:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");

        scanf("%d", &player_choice);

        // Player attacks
        if (player_choice == 1)
        {
            player_damage = rand() % 30 + 10; // Random damage between 10 and 40

            printf("You attack the alien spaceship and deal %d damage!\n", player_damage);

            alien_health -= player_damage;
        }
        // Player defends
        else if (player_choice == 2)
        {
            player_damage = rand() % 10; // Random defense between 0 and 10
            player_damage *= -1; // Make it negative to subtract from alien damage

            printf("You defend against the alien attack and reduce their damage by %d!\n", player_damage);

            alien_choice = rand() % 3; // Choose a random attack for the alien

            if (alien_choice == 1)
            {
                printf("The alien attacks with lasers and deals %d damage!\n", rand() % 20 + 10); // Random damage between 10 and 30
                spaceship_health += player_damage + (rand() % 10); // Reduce alien damage by player defense and add a small random amount of healing
            }
            else if (alien_choice == 2)
            {
                printf("The alien attacks with missiles and deals %d damage!\n", rand() % 30 + 20); // Random damage between 20 and 50
                spaceship_health += player_damage + (rand() % 20); // Reduce alien damage by player defense and add a small random amount of healing
            }
            else
            {
                printf("The alien attacks with a tractor beam, but your shields hold strong and you take no damage!\n");
                spaceship_health += player_damage; // Add player defense as healing
            }
        }
        // Player heals
        else if (player_choice == 3)
        {
            player_damage = rand() % 10 + 10; // Random heal between 10 and 20

            printf("You restore your spaceship's systems and heal for %d!\n", player_damage);

            spaceship_health += player_damage;
        }
        // Invalid choice
        else
        {
            printf("Invalid choice, try again.\n");
            continue; // Go back to the beginning of the loop
        }

        // Alien attacks
        if (alien_health > 0)
        {
            alien_choice = rand() % 3; // Choose a random attack for the alien

            if (alien_choice == 1)
            {
                alien_damage = rand() % 20 + 10; // Random damage between 10 and 30
                printf("The alien attacks with lasers and deals %d damage!\n", alien_damage);

                spaceship_health -= alien_damage;
            }
            else if (alien_choice == 2)
            {
                alien_damage = rand() % 30 + 20; // Random damage between 20 and 50
                printf("The alien attacks with missiles and deals %d damage!\n", alien_damage);

                spaceship_health -= alien_damage;
            }
            else
            {
                printf("The alien attacks with a tractor beam, but your shields hold strong and you take no damage!\n");
            }
        }

        turn++; // Increase the turn counter
    }

    // Check who won
    if (alien_health <= 0)
    {
        printf("\nCongratulations, you have defeated the alien race and saved the universe!\n");
    }
    else if (spaceship_health <= 0)
    {
        printf("\nGame over, your spaceship has been destroyed by the alien race.\n");
    }

    return 0;
}