//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int current_fitness_lvl = 0;
    int max_fitness_lvl = 5;
    int health = 100;
    int stamina = 100;
    int steps_taken = 0;
    int water_consumed = 0;
    int food_consumed = 0;
    int medkits_used = 0;
    int zombie_kills = 0;

    printf("It's been 10 years since the nuclear war that decimated human civilization. You are one of the few survivors, fighting for survival daily.\n\n");

    while(health > 0) {

        printf("Current stats:\n");
        printf("Fitness Level: %d/%d\nHealth: %d%%\nStamina: %d%%\nSteps taken: %d\nWater consumed: %dL\nFood consumed: %dKcal\n", current_fitness_lvl, max_fitness_lvl, health, stamina, steps_taken, water_consumed, food_consumed);
        printf("Medkits used: %d\nZombie kills: %d\n\n", medkits_used, zombie_kills);

        int random_event = rand() % 5;

        switch(random_event) {
            case 0:
                // walk
                if(stamina < 20) {
                    printf("You collapsed due to lack of energy. You lost 10 health points.\n");
                    health -= 10;
                    stamina = 0;
                } else {
                    printf("You walked for an hour.\n");
                    stamina -= 20;
                    steps_taken += 100;
                    current_fitness_lvl = (steps_taken/500) > max_fitness_lvl ? max_fitness_lvl : (steps_taken/500);
                }
                break;
            case 1:
                // scavenge for water
                printf("You found a lake and drank some water.\n");
                stamina -= 15;
                water_consumed += 1;
                break;
            case 2:
                // scavenge for food
                printf("You found some canned food and had a meal.\n");
                stamina -= 20;
                food_consumed += 500;
                break;
            case 3:
                // fight a zombie
                printf("You encountered a zombie and fought it.\n");
                if(current_fitness_lvl < 3) {
                    printf("You were not fit enough to fight it properly. You lost 10 health points.\n");
                    health -= 10;
                } else {
                    int random_zombie_kill = rand() % 2;
                    if(random_zombie_kill == 0) {
                        printf("You killed the zombie. Great job!\n");
                        zombie_kills += 1;
                    } else {
                        printf("The zombie killed you. You lost 20 health points.\n");
                        health -= 20;
                    }
                }
                stamina -= 30;
                break;
            case 4:
                //use a medkit
                printf("You applied a medkit to your wounds.\n");
                health += 20;
                medkits_used += 1;
                break;
        }

        // check if player has died
        if(health <= 0) {
            printf("Game over. You have died.\n");
            break;
        }

        // check if player has won
        if(zombie_kills == 10) {
            printf("You have defeated 10 zombies and saved humanity. Congrats, you survived!.\n");
            break;
        }

        // regenerate stamina
        if(stamina < 100) {
            stamina += 10;
        }

        printf("Press ENTER to continue.\n");
        getchar();
    }

    return 0;
}