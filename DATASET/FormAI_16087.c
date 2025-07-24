//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    int fuel_level = 100;
    int distance = 1000;
    int ship_health = 100;
    int alien_health = 50 + rand() % 50; // Randomize alien health between 50 and 100
    int encounter_chance = 30; // Percentage chance of encountering an alien ship
    
    printf("Welcome to the Space Adventure!\n");
    printf("Your mission is to travel %dkm to the planet Eden.\n", distance);
    printf("You have a full tank of fuel and a healthy ship.\n");
    
    while (distance > 0)
    {
        printf("\nDistance to Eden: %dkm\n", distance);
        printf("Fuel level: %d\n", fuel_level);
        printf("Ship health: %d\n", ship_health);
        
        int move_distance = rand() % 50 + 50; // Move between 50 and 100 km
        distance -= move_distance;
        fuel_level -= move_distance * 2; // Consume fuel at a rate of 2km per liter
        
        printf("You move %dkm forward.\n", move_distance);
        
        int encounter_roll = rand() % 100; // Roll for chance of encountering an alien ship
        
        if (encounter_roll < encounter_chance)
        {
            printf("\nAn alien ship has appeared!\n");
            
            while (alien_health > 0 && ship_health > 0)
            {
                int alien_attack = rand() % 20 + 30; // Alien deals between 30 and 50 damage
                int ship_attack = rand() % 10 + 10; // Ship deals between 10 and 20 damage
                
                printf("Your ship attacks for %d damage!\n", ship_attack);
                alien_health -= ship_attack;
                
                if (alien_health <= 0)
                {
                    printf("The alien ship has been defeated!\n");
                    break;
                }
                
                printf("The alien ship attacks for %d damage!\n", alien_attack);
                ship_health -= alien_attack;
                
                if (ship_health <= 0)
                {
                    printf("Your ship has been destroyed.\n");
                    return 0;
                }
            }
            
            encounter_chance += 10; // Increase chance of encountering an alien after each encounter
        }
        
        if (fuel_level < 0)
        {
            printf("\nYour ship has run out of fuel and you are stranded.\n");
            return 0;
        }
        
        if (distance <= 0)
        {
            printf("\nCongratulations, you have arrived at Eden!\n");
            return 0;
        }
    }
    
    return 0;
}