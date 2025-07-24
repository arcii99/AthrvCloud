//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SPACESHIP_HEALTH 100
#define MAX_ENEMY_HEALTH 50
#define MAX_ENEMIES 5
#define MAX_PLANETS 10

int spaceshipHealth = MAX_SPACESHIP_HEALTH; //initial spaceship health
int enemiesEliminated = 0; //initial enemies eliminated

struct Enemy
{
    int health;
    bool isAlive;
};

struct Planet
{
    char name[20];
    int resources;
};

void generateEnemyHealth(struct Enemy enemies[])
{
    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        enemies[i].health = rand() % MAX_ENEMY_HEALTH + 1;
        enemies[i].isAlive = true;
    }
}

void initializePlanets(struct Planet planets[])
{
    strcpy(planets[0].name, "Earth");
    planets[0].resources = 500;

    strcpy(planets[1].name, "Mars");
    planets[1].resources = 300;

    strcpy(planets[2].name, "Jupiter");
    planets[2].resources = 200;

    strcpy(planets[3].name, "Saturn");
    planets[3].resources = 150;

    strcpy(planets[4].name, "Uranus");
    planets[4].resources = 125;

    strcpy(planets[5].name, "Neptune");
    planets[5].resources = 100;

    strcpy(planets[6].name, "Pluto");
    planets[6].resources = 75;

    strcpy(planets[7].name, "Alpha Centauri");
    planets[7].resources = 5000;

    strcpy(planets[8].name, "Sirius");
    planets[8].resources = 2500;

    strcpy(planets[9].name, "Orion");
    planets[9].resources = 1500;
}

void spaceshipAttack(struct Enemy enemies[], int index)
{
    int damage = rand() % 20 + 1;
    enemies[index].health -= damage;

    if(enemies[index].health <= 0)
    {
        printf("Enemy %d has been eliminated!", index+1);
        enemies[index].isAlive = false;
        enemiesEliminated++;
    }
    else
    {
        printf("Enemy %d is attacking!\n", index+1);
    }

}

void enemyAttack()
{
    int damage = rand() % 10 + 1;
    spaceshipHealth -= damage;
}

void printPlanets(struct Planet planets[])
{
    printf("\nPlanets with Resources:\n");
    for(int i = 0; i < MAX_PLANETS; i++)
    {
        printf("%d. %s - %d Resources\n", i+1, planets[i].name, planets[i].resources);
    }
    printf("\n");
}

int main()
{
    struct Planet planets[MAX_PLANETS];
    struct Enemy enemies[MAX_ENEMIES];
    int planetIndex;

    srand(time(0)); // initialize random seed

    printf("Welcome to the Procedural Space Adventure!\n");

    initializePlanets(planets);
    generateEnemyHealth(enemies);
    printPlanets(planets);

    printf("Select a planet to explore (1-10): ");
    scanf("%d", &planetIndex);

    if(planetIndex < 1 || planetIndex > MAX_PLANETS)
    {
        printf("Invalid planet index. Exiting program.");
        exit(EXIT_FAILURE);
    }

    printf("\nExploring planet %s...\n", planets[planetIndex-1].name);

    printf("You have discovered %d resources on this planet.\n", planets[planetIndex-1].resources);

    printf("Do you want to collect the resources? (y/n): ");
    char input;
    scanf(" %c", &input);

    if(input == 'y' || input == 'Y')
    {
        printf("You have successfully collected the resources!\n");
    }
    else
    {
        printf("You have chosen to not collect the resources.\n");
    }

    printf("Encountering %d enemies...\n", MAX_ENEMIES);

    while(enemiesEliminated < MAX_ENEMIES && spaceshipHealth > 0)
    {
        for(int i = 0; i < MAX_ENEMIES; i++)
        {
            if(!enemies[i].isAlive)
            {
                continue;
            }

            spaceshipAttack(enemies, i);
            enemyAttack();
        }
    }

    if(spaceshipHealth <= 0)
    {
        printf("\nYour spaceship has been destroyed. Game over.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nCongratulations! You have eliminated all enemies and completed the game with %d health remaining\n", spaceshipHealth);

    return 0;
}