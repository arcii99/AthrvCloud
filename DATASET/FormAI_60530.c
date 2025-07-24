//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function declarations */
void planet(int id);
void asteroid();
void alien();
int battle(int player_ship, int alien_ship);

/* define constants */
#define PLANET_MIN 1
#define PLANET_MAX 10
#define ASTEROID_CHANCE 30
#define ALIEN_CHANCE 20

/* main function */
int main()
{
    srand(time(0)); // initialize random seed

    int player_ship = 100; // initialize player ship health
    int alien_ship = 100; // initialize alien ship health
    int planet_id = PLANET_MIN; // initialize planet id

    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("Your mission is to explore the galaxy, fight alien enemies,\n");
    printf("and collect resources from planets.\n");
    printf("Good luck, captain!\n\n");

    while (player_ship > 0 && alien_ship > 0)
    {
        // random event generator
        int event = rand() % 100 + 1;

        if (event <= ASTEROID_CHANCE)
        {
            asteroid();
        }
        else if (event <= ASTEROID_CHANCE + ALIEN_CHANCE)
        {
            alien();
            alien_ship = battle(player_ship, alien_ship);
        }
        else
        {
            planet(planet_id);
            planet_id++;
        }
    }

    if (player_ship <= 0)
    {
        printf("Game over. Your ship has been destroyed.\n");
    }
    else if (alien_ship <= 0)
    {
        printf("Congratulations! You have defeated the alien enemy.\n");
    }

    return 0;
}

/* function definitions */

void planet(int id)
{
    int resources = rand() % 10 + 1; // generate random resources
    printf("You have arrived on planet %d.\n", id);
    printf("You have collected %d resources.\n", resources);
}

void asteroid()
{
    printf("You have encountered an asteroid field.\n");
    printf("You maneuver through the asteroids and avoid damage.\n");
}

void alien()
{
    printf("You have encountered an alien enemy.\n");
}

int battle(int player_ship, int alien_ship)
{
    int player_attack = rand() % 10 + 1; // generate random attack strength for player
    int alien_attack = rand() % 10 + 1; // generate random attack strength for alien

    printf("Your ship health: %d\n", player_ship);
    printf("Alien ship health: %d\n", alien_ship);
    printf("It is your turn to attack.\n");
    printf("You attack with strength %d.\n", player_attack);

    alien_ship -= player_attack;

    if (alien_ship <= 0)
    {
        return 0;
    }

    printf("Alien ship health: %d\n", alien_ship);
    printf("It is the alien's turn to attack.\n");
    printf("The alien attacks with strength %d.\n", alien_attack);

    player_ship -= alien_attack;

    if (player_ship <= 0)
    {
        return -1;
    }

    return alien_ship;
}