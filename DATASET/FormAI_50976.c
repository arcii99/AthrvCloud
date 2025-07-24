//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct spaceship {
    char name[20];
    int hull;
    int fuel;
    int price;
};

int main() {
    struct spaceship myShip;
    strcpy(myShip.name, "Enterprise"); //ship's name
    myShip.hull = 100; //initial health of the ship
    myShip.fuel = 50; //initial amount of fuel
    myShip.price = 1000; //initial price of the ship

    int round = 1; //initialize the game round

    srand(time(NULL)); //initialize random number generator

    printf("Welcome to Procedural Space Adventure!\n");
    printf("--------------------------------------\n");

    while (myShip.hull > 0 && myShip.fuel > 0) { //keep looping till ship has no hull left or fuel left
        printf("Round %d\n", round);

        int event = rand() % 5; //randomly generate an event
        switch (event) {
            case 0:
                printf("Nothing happened.\n");
                break;
            case 1:
                printf("You encountered a band of space pirates!\n");
                int success = rand() % 2; //randomly determine if the player successfully defeats the space pirates
                if (success) {
                    printf("You defeated the space pirates! You gained 50 space bucks.\n");
                    myShip.price += 50; //add 50 space bucks to the ship's price
                } else {
                    printf("The space pirates defeated you! You lost 30 hull points.\n");
                    myShip.hull -= 30; //subtract 30 hull points from the ship's health
                }
                break;
            case 2:
                printf("You found a cache of fuel! You gained 20 units of fuel.\n");
                myShip.fuel += 20; //add 20 units of fuel to the ship's fuel
                break;
            case 3:
                printf("You stumbled upon a rare mineral deposit! You gained 100 space bucks.\n");
                myShip.price += 100; //add 100 space bucks to the ship's price
                break;
            case 4:
                printf("You ran into a black hole! You lost 50 units of fuel and 20 hull points.\n");
                myShip.fuel -= 50; //subtract 50 units of fuel from the ship's fuel
                myShip.hull -= 20; //subtract 20 hull points from the ship's health
                break;
        }

        printf("Ship status:\n");
        printf("Name: %s\n", myShip.name);
        printf("Hull: %d\n", myShip.hull);
        printf("Fuel: %d\n", myShip.fuel);
        printf("Price: %d\n", myShip.price);

        round++; //increment the round number
    }

    if (myShip.hull <= 0) { //check if ship was destroyed
        printf("Your ship was destroyed! Game over!\n");
    } else { //check if ship ran out of fuel
        printf("You ran out of fuel! Game over!\n");
    }

    return 0;
}