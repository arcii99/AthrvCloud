//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Game function prototypes
void introduction();
void navigate_ship();
void engage_enemy();
void victory();

int main()
{
    //Seed random number generator
    srand(time(NULL));

    //Call game functions
    introduction();
    navigate_ship();
    engage_enemy();
    victory();

    return 0;
}

void introduction()
{
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are the captain of the spaceship \"Galactic Explorer\" on a mission to explore the outer reaches of the galaxy.\n");
    printf("You receive a distress signal from a nearby planet and decide to investigate.\n");
}

void navigate_ship()
{
    printf("\n\nYou arrive at the planet and encounter a group of alien spacecraft.\n");
    printf("You must navigate your ship to avoid their attacks.\n\n");

    int spaceship_health = 100; //Initialize spaceship health
    int alien_attack_chance = 50; //Initialize alien attack chance

    //Loop until spaceship health reaches 0 or alien attack chance reaches 100
    while (spaceship_health > 0 && alien_attack_chance < 100)
    {
        printf("Spaceship Health: %d\n", spaceship_health);

        //Generate a random number between 1-100 to determine if the alien will attack
        int attack = rand() % 100 + 1;
        if (attack <= alien_attack_chance)
        {
            printf("Alien attack!\n");
            int damage = rand() % 25 + 1; //Generate a random amount of damage between 1-25
            spaceship_health -= damage;
            printf("Spaceship takes %d damage.\n", damage);

            //Increase alien attack chance by 10%
            alien_attack_chance += 10;
        }
        else
        {
            printf("Alien misses!\n");

            //Decrease alien attack chance by 10%
            alien_attack_chance -= 10;
        }

        //Delay for 1 second
        sleep(1);
    }

    //Check if spaceship health reached 0 or alien attack chance reached 100
    if (spaceship_health <= 0)
    {
        printf("\n\nSpaceship destroyed! Game over.\n");
        exit(0);
    }
    else
    {
        printf("\n\nSpaceship successfully navigated through alien attack!\n");
    }
}

void engage_enemy()
{
    printf("\n\nYou have arrived at the enemy base!\n");
    printf("You must navigate the base and defeat the enemy boss.\n");

    //Initialize enemy health
    int enemy_health = 100;

    //Loop until enemy health reaches 0
    while (enemy_health > 0)
    {
        printf("Enemy Health: %d\n", enemy_health);

        //Generate a random number between 1-100 to determine player attack success
        int attack = rand() % 100 + 1;
        if (attack <= 75)
        {
            printf("Player attack successful!\n");
            int damage = rand() % 50 + 1; //Generate a random amount of damage between 1-50
            enemy_health -= damage;
            printf("Enemy takes %d damage.\n", damage);
        }
        else
        {
            printf("Player attack misses!\n");
        }

        //Delay for 1 second
        sleep(1);
    }

    printf("\n\nEnemy boss defeated!\n");
}

void victory()
{
    printf("\n\nCongratulations! You have successfully completed Procedural Space Adventure!\n");
}