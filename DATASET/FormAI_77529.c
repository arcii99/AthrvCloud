//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Game setup
    srand(time(NULL)); // Initialize random seed
    int health = 50; // Starting health
    int gold = 0; // Starting gold
    int room_number = 1; // Starting room number

    // Intro
    printf("Welcome to the Dungeon Adventure Game!\n");
    printf("You find yourself in a dark and mysterious dungeon...\n");
    printf("Your goal is to find the treasure and escape alive!\n");
    printf("Good luck!\n\n");

    // Game loop
    while (health > 0 && room_number < 6) {
        // Display current status
        printf("You are currently in room #%d.\n", room_number);
        printf("You have %d health and %d gold.\n", health, gold);

        // Randomly select an encounter
        int encounter = rand() % 3; // 0, 1, or 2
        switch (encounter) {
            case 0: // Combat
                printf("A monster appears! Get ready to fight!\n");
                int monster_health = 10 + (rand() % 10); // Random health between 10 and 19
                while (health > 0 && monster_health > 0) {
                    int damage = 2 + (rand() % 5); // Random damage between 2 and 6
                    printf("You attack the monster and deal %d damage.\n", damage);
                    monster_health -= damage;
                    if (monster_health > 0) {
                        damage = 2 + (rand() % 5);
                        printf("The monster attacks you and deals %d damage.\n", damage);
                        health -= damage;
                    }
                }
                if (health > 0) {
                    printf("You defeated the monster! You gain 10 gold.\n");
                    gold += 10;
                } else {
                    printf("You died!\n");
                }
                break;

            case 1: // Treasure
                printf("You have found treasure! You gain 20 gold.\n");
                gold += 20;
                break;

            case 2: // Trap
                printf("You have triggered a trap! You take 5 damage.\n");
                health -= 5;
                break;
        }

        // Move to next room
        room_number++;
        printf("\n");
    }

    // End game
    if (health > 0) {
        printf("Congratulations, you have found the treasure and escaped the dungeon!\n");
        printf("You have %d health and %d gold.\n", health, gold);
    } else {
        printf("Game over! You died in room #%d.\n", room_number);
    }

    return 0;
}