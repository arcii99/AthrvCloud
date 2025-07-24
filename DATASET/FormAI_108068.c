//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // for random number generation
    int health = 100; // player's health
    int fuel = 100; // spaceship fuel
    int points = 0; // points earned
    int days = 0; // days survived

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are flying solo in your spaceship, exploring the vast expanse of the cosmos.\n");
    printf("Your mission is to survive as long as you can, earn points, and make discoveries.\n\n");

    while (health > 0 && fuel > 0) { // continue game until player runs out of health or fuel
        printf("You have %d health and %d fuel. What would you like to do? \n", health, fuel);

        int choice = rand() % 4; // randomly choose a scenario

        if (choice == 0) { // find a new planet
            printf("You have discovered a new planet! You land on the surface and begin to explore.\n");
            printf("After several hours, you find a strange crystal that glows with an otherworldly light.\n");
            printf("You pocket the crystal and take off, feeling victorious.\n");
            points += 50; // earn 50 points
            days++; // survive one more day
        } else if (choice == 1) { // encounter alien life
            printf("You have encountered a race of friendly aliens! They invite you to their home planet for a feast.\n");
            printf("You accept their kind offer and spend the night eating delicious alien dishes and learning about their culture.\n");
            printf("The next morning, they present you with a potion that can heal any ailment instantly. You thank them and return to your spaceship.\n");
            health = 100; // restore health
            points += 100; // earn 100 points
            days++; // survive one more day
        } else if (choice == 2) { // asteroid field
            printf("You are flying through an asteroid field when suddenly, your spaceship is hit!\n");
            printf("You try to regain control, but it's no use. You crash into a nearby asteroid and lose some fuel.\n");
            fuel -= 25; // lose 25 fuel
            days++; // survive one more day
        } else { // find a wormhole
            printf("You have discovered a wormhole! You carefully navigate your spaceship through the swirling vortex.\n");
            printf("When you emerge on the other side, you find yourself in a completely different part of the universe.\n");
            printf("You decide to explore this new area and spend several hours charting the stars.\n");
            points += 75; // earn 75 points
            days++; // survive one more day
        }
    }

    if (health <= 0) { // player lost
        printf("Your spaceship has been destroyed and you have perished.\n");
        printf("You survived for %d days and earned %d points. \n", days, points);
    } else { // player won
        printf("Congratulations! You have successfully completed your mission and returned home safely.\n");
        printf("You survived for %d days and earned %d points. \n", days, points);
    }

    return 0;
}