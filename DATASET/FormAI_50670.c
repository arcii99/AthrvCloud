//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function that generates a random number within a given range*/
int get_random(int min, int max)
{
    srand(time(NULL)); //initialize random seed
    return (rand() % (max - min + 1)) + min; //return random number within range
}

/*Function that sets up the game environment*/
void initialize_game()
{
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You wake up in your spaceship to find yourself drifting in an unfamiliar part of space...\n");
    printf("Your mission is to explore this space and gather resources for your journey back home.\n");
    printf("Good luck!\n\n");

    //set up game variables
    int fuel = 100;
    int food = 100;
    int oxygen = 100;
    int days = 0;
    int planets_explored = 0;
    int resources_collected = 0;
    int planet_distance;

    printf("Your spaceship has 3 main resources that you need to manage:\n\n");
    printf("Fuel: %d\nFood: %d\nOxygen: %d\n\n", fuel, food, oxygen);

    //start game loop
    while (fuel > 0 && food > 0 && oxygen > 0)
    {
        days++; //increment number of days passed

        //generate a random planet distance between 10 and 50 light years away
        planet_distance = get_random(10, 50);

        printf("Day %d:\n", days);
        printf("You are currently %d LY away from the next planet.\n", planet_distance);

        //check if player has enough resources to travel to the next planet
        if (fuel >= planet_distance / 2 && food >= days * 2 && oxygen >= days)
        {
            printf("You have enough resources to travel to the next planet!\n\n");

            //decrement resources used for travel
            fuel -= planet_distance / 2;
            food -= days * 2;
            oxygen -= days;

            //generate a random resource on the planet
            int resource = get_random(1, 3);
            if (resource == 1)
            {
                printf("You found a fuel deposit on the planet!\n");
                fuel += 20;
            }
            else if (resource == 2)
            {
                printf("You found a food source on the planet!\n");
                food += 20;
            }
            else
            {
                printf("You found an oxygen-rich environment on the planet!\n");
                oxygen += 20;
            }

            //increment number of resources collected and planets explored
            resources_collected++;
            planets_explored++;

            printf("Your current resources:\nFuel: %d\nFood: %d\nOxygen: %d\n\n", fuel, food, oxygen);
        }
        else
        {
            printf("You do not have enough resources to travel to the next planet!\n\n");
            printf("Your current resources:\nFuel: %d\nFood: %d\nOxygen: %d\n\n", fuel, food, oxygen);
            break; //end game loop if player runs out of resources
        }
    }

    //end of game message
    if (fuel <= 0 || food <= 0 || oxygen <= 0)
    {
        printf("Game over! You ran out of resources and were unable to complete your mission.\n");
    }
    else
    {
        printf("Congratulations! You completed your mission and collected %d resources on %d planets.\n", resources_collected, planets_explored);
    }

    printf("Thanks for playing Procedural Space Adventure!\n");
}

int main()
{
    initialize_game(); //start the game
    return 0;
}