//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 50
#define MAX_NAME_LENGTH 20

typedef struct {
   char name[MAX_NAME_LENGTH];
   int resource;
} planet_t;

typedef struct {
    int fuel;
    int health;
    int location;
} spaceship_t;

planet_t planets[MAX_PLANETS];
spaceship_t spaceship;

void generate_planets()
{
    for (int i = 0; i < MAX_PLANETS; i++) {
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].resource = rand()%1000;
    }
}

void print_planets()
{
    printf("Available planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%s\t\tResources: %d\n", planets[i].name, planets[i].resource);
    }
}

int travel()
{
    printf("Enter planet number to travel: ");
    int choice;
    scanf("%d", &choice);
    
    if (choice < 1 || choice > MAX_PLANETS) {
        printf("Invalid choice!\n");
        return 1;
    }
    
    // check distance
    int distance = abs(choice - spaceship.location);
    if (choice > spaceship.location) {
        printf("Traveling %d light years to %s...\n", distance, planets[choice-1].name);
    } else {
        printf("Traveling %d light years to %s...\n", distance, planets[choice-1].name);
    }
    
    spaceship.location = choice;
    spaceship.fuel -= distance*10;
    spaceship.health -= rand()%10;
    
    if (spaceship.fuel < 0) {
        printf("You don't have enough fuel to travel that far!\n");
        spaceship.location = 0;
        return 1;
    }
    
    if (spaceship.health < 0) {
        printf("Your spaceship sustained too much damage during travel!\n");
        spaceship.location = 0;
        return 1;
    }
    
    printf("You have arrived at %s!\n", planets[spaceship.location-1].name);
    return 0;
}

void mine_resource()
{
    int resource = rand()%100;
    planets[spaceship.location-1].resource -= resource;
    spaceship.fuel += resource;
    printf("Mining successful! You gained %d fuel.\n", resource);
}

void print_ship_status()
{
    printf("Spaceship status:\n");
    printf("Fuel: %d\n", spaceship.fuel);
    printf("Health: %d\n", spaceship.health);
    printf("Location: %s\n", planets[spaceship.location-1].name);
}

void game_over()
{
    printf("Game over. You have failed to save humanity.\n");
    exit(1);
}

int main()
{
    printf("Initializing space adventure...\n");
    srand(time(NULL));
    
    generate_planets();
    
    printf("Enter your name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    
    spaceship.fuel = 100;
    spaceship.health = 100;
    spaceship.location = 1;
    
    printf("Welcome %s! Your mission is to find a new planet for humanity to inhabit.\n", name);
    int turn = 1;
    
    while (turn <= 10) {
        printf("\nTURN %d:\n", turn);
        print_planets();
        printf("Press 1 to travel, 2 to mine resource, or 3 to check spaceship status: ");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (travel() == 0) {
                    if (planets[spaceship.location-1].resource == 0) {
                        printf("Planet %s is depleted of resources. You must find another planet!\n", planets[spaceship.location-1].name);
                    } else {
                        printf("%s has %d resources.\n", planets[spaceship.location-1].name, planets[spaceship.location-1].resource);
                        printf("You can mine resources here.\n");
                    }
                }
                break;
                
            case 2:
                if (spaceship.location == 0) {
                    printf("You cannot mine resources when you have not yet arrived at a planet!\n");
                } else {
                    mine_resource();
                }
                break;
                
            case 3:
                print_ship_status();
                break;
                
            default:
                printf("Invalid choice!\n");
                continue;
        }
        
        // check game over
        if (spaceship.fuel < 0 || spaceship.health < 0) {
            game_over();
        }
        
        turn++;
    }
    
    printf("\nCongratulations! You have found a new planet for humanity to inhabit.\n");
    
    return 0;
}