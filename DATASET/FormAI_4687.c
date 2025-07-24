//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int distance = 60;
    int fuel = 100;
    int oxygen = 100;
    int health = 100;
    int aliens = 0;
    int random_event;
    srand(time(NULL));

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the captain of the spaceship, traveling to planet X.\n");
    printf("Your mission is to collect rare minerals and bring them back to Earth.\n\n");

    while (distance > 0) {
        printf("Distance to planet X: %d light years.\n", distance);
        printf("Fuel level: %d%%\n", fuel);
        printf("Oxygen level: %d%%\n", oxygen);
        printf("Health status: %d%%\n", health);

        random_event = rand() % 100 + 1;

        if (random_event <= 10) {
            aliens++;
            printf("You have encountered alien life form! Prepare for a battle!\n");
            health -= rand() % 30 + 1;
            if (health <= 0) {
                printf("Your spaceship has been destroyed by the aliens. Game over.\n");
                return 0;
            }
            printf("You have defeated the alien and continue your journey to planet X.\n\n");
        }
        else if (random_event > 10 && random_event <= 30) {
            printf("Your spaceship has suffered a fuel leak! You lose 20%% of your fuel.\n");
            fuel -= 20;
            if (fuel <= 0) {
                printf("Your spaceship has run out of fuel. Game over.\n");
                return 0;
            }
            printf("The leak has been contained and you continue your journey to planet X.\n\n");
        }
        else if (random_event > 30 && random_event <= 50) {
            printf("Your spaceship has encountered a space debris field! You lose 10%% of your health.\n");
            health -= 10;
            if (health <= 0) {
                printf("Your spaceship has been destroyed by the debris. Game over.\n");
                return 0;
            }
            printf("You have navigated safely through the debris field and continue your journey to planet X.\n\n");
        }
        else if (random_event > 50 && random_event <= 70) {
            printf("Your spaceship has encountered a mysterious wormhole! You jump 20 light years ahead.\n");
            distance -= 20;
            printf("You have exited the wormhole and continue your journey to planet X.\n\n");
        }
        else {
            printf("Nothing eventful happened during this leg of your journey.\n\n");
        }

        distance--;
        oxygen -= rand() % 5 + 1;
        if (oxygen <= 0) {
            printf("Your spaceship has run out of oxygen. Game over.\n");
            return 0;
        }
    }

    printf("Congratulations! You have safely reached planet X and collected the rare minerals.\n");
    printf("You begin your journey back to Earth with %d units of rare minerals.\n", aliens);

    while (distance < 60) {
        printf("Distance to Earth: %d light years.\n", 60 - distance);
        printf("Fuel level: %d%%\n", fuel);
        printf("Oxygen level: %d%%\n", oxygen);
        printf("Health status: %d%%\n", health);

        random_event = rand() % 100 + 1;

        if (random_event <= 10) {
            aliens++;
            printf("You have encountered alien life form! Prepare for a battle!\n");
            health -= rand() % 30 + 1;
            if (health <= 0) {
                printf("Your spaceship has been destroyed by the aliens. Game over.\n");
                return 0;
            }
            printf("You have defeated the alien and continue your journey to Earth.\n\n");
        }
        else if (random_event > 10 && random_event <= 30) {
            printf("Your spaceship has suffered a fuel leak! You lose 20%% of your fuel.\n");
            fuel -= 20;
            if (fuel <= 0) {
                printf("Your spaceship has run out of fuel. Game over.\n");
                return 0;
            }
            printf("The leak has been contained and you continue your journey to Earth.\n\n");
        }
        else if (random_event > 30 && random_event <= 50) {
            printf("Your spaceship has encountered a space debris field! You lose 10%% of your health.\n");
            health -= 10;
            if (health <= 0) {
                printf("Your spaceship has been destroyed by the debris. Game over.\n");
                return 0;
            }
            printf("You have navigated safely through the debris field and continue your journey to Earth.\n\n");
        }
        else if (random_event > 50 && random_event <= 70) {
            printf("Your spaceship has encountered a mysterious wormhole! You jump 20 light years ahead.\n");
            distance += 20;
            printf("You have exited the wormhole and continue your journey to Earth.\n\n");
        }
        else {
            printf("Nothing eventful happened during this leg of your journey.\n\n");
        }

        distance++;
        fuel -= rand() % 5 + 1;
        if (fuel <= 0) {
            printf("Your spaceship has run out of fuel. Game over.\n");
            return 0;
        }
        oxygen -= rand() % 5 + 1;
        if (oxygen <= 0) {
            printf("Your spaceship has run out of oxygen. Game over.\n");
            return 0;
        }
    }

    printf("You have safely landed back on Earth with %d units of rare minerals.\n", aliens);
    printf("Thanks for playing Procedural Space Adventure!\n");

    return 0;
}