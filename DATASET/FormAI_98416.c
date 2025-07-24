//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate a random number between min and max
int random_number(int min, int max){
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main(){
    //creating an array of planet names
    char planet_names[10][20] = {"Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Mercury", "Venus", "Pluto", "Chiron"};

    //declaring variables for space adventure
    int fuel = 100;
    int food = 100;
    int distance = 0;
    int current_planet = 0;
    int planet_count = sizeof(planet_names)/sizeof(planet_names[0]);
    int alien_threat = 0;

    //generating random distance to the next planet
    int next_planet = random_number(50, 150);

    //printing the welcome message
    printf("Welcome to Space Adventure!\n");
    printf("You are currently on planet %s.\n", planet_names[current_planet]);
    printf("You have %d units of fuel and %d units of food.\n", fuel, food);

    while(fuel > 0 && food > 0){
        //prompting the user for their next action
        printf("\nWhat would you like to do?\n");
        printf("Enter 1 to travel to the next planet.\n");
        printf("Enter 2 to look for resources on the current planet.\n");
        printf("Enter 3 to check the status of your ship.\n");
        printf("Enter 4 to quit the game.\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1: //travel to the next planet
                fuel -= random_number(10, 30); //consume fuel
                food -= random_number(5, 15); //consume food
                distance += next_planet; //update current distance traveled
                printf("You have traveled %d light years.\n", distance);

                //check if there is an alien threat on the next planet
                alien_threat = random_number(0, 1);
                if(alien_threat){
                    printf("WARNING: There is an alien threat on the next planet.\n");
                }

                //check if the player has reached the last planet
                if(current_planet == planet_count - 1){
                    printf("Congratulations! You have reached the final planet.\n");
                    printf("Your total distance traveled is %d light years.\n", distance);
                    return 0;
                }

                //update current planet and get the name of the next planet
                current_planet++;
                next_planet = random_number(50, 150);
                printf("You have arrived at planet %s.\n", planet_names[current_planet]);
                printf("You have %d units of fuel and %d units of food left.\n", fuel, food);
                break;

            case 2: //look for resources on the current planet
                int fuel_found = random_number(10, 20);
                int food_found = random_number(5, 10);
                printf("You have found %d units of fuel and %d units of food.\n", fuel_found, food_found);
                fuel += fuel_found;
                food += food_found;
                printf("You have %d units of fuel and %d units of food left.\n", fuel, food);
                break;

            case 3: //check the status of the ship
                printf("You have %d units of fuel and %d units of food left.\n", fuel, food);
                printf("You have traveled %d light years.\n", distance);
                printf("You are currently on planet %s.\n", planet_names[current_planet]);
                break;

            case 4: //quit the game
                printf("Thanks for playing Space Adventure!\n");
                return 0;

            default: //invalid input
                printf("Invalid input. Please enter a number between 1 and 4.\n");
        }
    }

    //game over if run out of fuel or food
    printf("Game over! You have run out of fuel or food.\n");
    printf("Your total distance traveled is %d light years.\n", distance);
    return 0;
}