//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed for randomization
    int health = 100;
    int score = 0;
    int level = 1;

    printf("Welcome to The Grateful Adventure Game!\n");
    printf("You are the Grateful adventurer, exploring the magical world of gratitude.\n");
    printf("Your mission is to collect as many thank you notes as possible, while avoiding obstacles and enemies.\n");

    while (health > 0) {
        printf("\n------- LEVEL %d -------\n", level);

        // generate random event
        int event = rand() % 3; // 0 for collect, 1 for obstacle, 2 for enemy

        if (event == 0) {
            printf("You found a thank you note! Score +10\n");
            score += 10;
        } else if (event == 1) {
            printf("Uh oh, you stumbled upon a negative thought! Health -20\n");
            health -= 20;
        } else {
            printf("A disgruntled goblin appears! Health -30\n");
            health -= 30;
        }

        if (health <= 0) {
            printf("Game over! Your final score is %d\n", score);
            break;
        }

        printf("Your current score: %d  |  Your health: %d\n", score, health);

        // check if level up
        if (score >= (level * 50)) {
            level++;
            printf("\n***** CONGRATULATIONS! You reached LEVEL %d! *****\n", level);
        }
    }

    return 0;
}