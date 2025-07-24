//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    // Creates a delay of the specified number of seconds
    clock_t start_time = clock();
    while (clock() < start_time + (seconds * CLOCKS_PER_SEC));
}

int main() {
    // Initialize spacecraft data
    int distance_from_earth = 0;
    int fuel = 100;
    int oxygen = 100;
    int health = 100;
    int aliens_encountered = 0;

    // Display welcome message
    printf("Welcome to the Space Adventure!\n\n");
    printf("You have been selected to pilot the newest spacecraft on its maiden voyage to explore the depths of space.\n\n");

    // Main game loop
    while (1) {
        // Display current spacecraft data
        printf("Current Distance from Earth: %d\n", distance_from_earth);
        printf("Fuel Level: %d\n", fuel);
        printf("Oxygen Level: %d\n", oxygen);
        printf("Health Level: %d\n", health);
        printf("Number of Aliens Encountered: %d\n", aliens_encountered);

        // Generate random event
        int event = rand() % 5;

        if (event == 0) {
            // Alien encounter
            printf("\nYou have encountered an alien spaceship!\n");
            delay(1);
            printf("You have two options:\n");
            printf("1) Attempt to negotiate\n");
            printf("2) Attack\n");

            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                // Negotiate with aliens
                printf("\nYou attempt to negotiate with the alien ship.\n");
                delay(1);
                printf("After several tense moments, the aliens decide to let you pass unharmed.\n");
            } else {
                // Engage in battle with aliens
                printf("\nYou engage the alien ship in battle!\n");
                delay(1);
                int alien_health = 100;
                while (alien_health > 0 && health > 0) {
                    int damage = rand() % 20 + 10;
                    printf("You fire your weapons and deal %d damage!\n", damage);
                    delay(1);
                    alien_health -= damage;
                    if (alien_health <= 0) {
                        printf("You have defeated the alien spaceship! Congratulations!\n");
                        aliens_encountered++;
                    } else {
                        damage = rand() % 20 + 10;
                        printf("The alien ship retaliates and deals %d damage!\n", damage);
                        delay(1);
                        health -= damage;
                        if (health <= 0) {
                            printf("You have been defeated by the alien spaceship! GAME OVER!\n");
                            return 0;
                        }
                    }
                }
            }
        } else if (event == 1) {
            // Discover a new planet
            printf("\nYou have discovered a new planet!\n");
            delay(1);
            printf("The planet appears to be habitable. Do you want to land and explore?\n");
            printf("1) Yes\n");
            printf("2) No\n");

            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                // Land on the planet
                printf("\nYou land your spacecraft on the planet.\n");
                delay(1);
                printf("As you exit your spacecraft, you are immediately greeted by a group of friendly aliens.\n");
                delay(1);
                printf("The aliens invite you back to their village where they treat you to a feast of exotic foods.\n");
                delay(1);
                printf("After spending a few hours with your new alien friends, you decide to return to your spacecraft to continue your journey.\n");
            } else {
                // Continue on your journey
                printf("\nYou decide not to land on the planet and continue on your journey.\n");
                delay(1);
            }
        } else if (event == 2) {
            // Fuel leak
            printf("\nYou experience a fuel leak!\n");
            delay(1);
            printf("Your spacecraft starts losing fuel at an alarming rate. You need to act fast!\n");
            delay(1);
            printf("You have two options:\n");
            printf("1) Attempt to fix the leak\n");
            printf("2) Ditch your current spacecraft and use your emergency escape pod\n");

            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                // Attempt to fix the leak
                printf("\nYou attempt to fix the fuel leak.\n");
                delay(1);
                printf("After several failed attempts, you finally manage to patch the leak and stop the fuel from leaking out of your spacecraft.\n");
                fuel += 50;
            } else {
                // Use emergency escape pod
                printf("\nYou use your emergency escape pod to escape your malfunctioning spacecraft.\n");
                delay(1);
                printf("You float helplessly through space until you are eventually rescued by a passing spaceship.\n");
                distance_from_earth += 500;
                oxygen = 100;
            }
        } else if (event == 3) {
            // Asteroid field
            printf("\nYou enter an asteroid field!\n");
            delay(1);
            printf("Your spacecraft is being pelted with asteroids from all directions.\n");
            delay(1);
            printf("You have two options:\n");
            printf("1) Attempt to dodge the asteroids\n");
            printf("2) Brace for impact\n");

            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                // Attempt to dodge the asteroids
                printf("\nYou attempt to dodge the asteroids.\n");
                delay(1);
                printf("After a few minutes of expert piloting, you manage to navigate your way out of the asteroid field unscathed.\n");
            } else {
                // Brace for impact
                printf("\nYou brace for impact as asteroids pelt your spacecraft.\n");
                delay(1);
                int damage = rand() % 50 + 10;
                printf("Your spacecraft takes %d damage!\n", damage);
                delay(1);
                health -= damage;
                if (health <= 0) {
                    printf("Your spacecraft has been destroyed by the asteroid field! GAME OVER!\n");
                    return 0;
                }
            }
        } else {
            // Nothing happens
            printf("\nYou continue on your journey through space.\n");
            delay(1);
            distance_from_earth += 100;
            fuel -= 10;
            oxygen -= 10;
            health -= 5;
            if (fuel <= 0 || oxygen <= 0 || health <= 0) {
                printf("Your spacecraft has run out of fuel, oxygen, or health! GAME OVER!\n");
                return 0;
            }
        }

        // Check for win condition
        if (distance_from_earth >= 10000) {
            printf("\nCongratulations! You have completed your Space Adventure!\n");
            return 0;
        }
    }
}