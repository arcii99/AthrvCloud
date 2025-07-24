//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int romeo_health = 100, juliet_health = 100;

    printf("Welcome to Romeo and Juliet Battle Game!\n");
    printf("Romeo and Juliet will fight to the death!\n");

    // Start game loop
    while (1) {
        int round = rand() % 2; // Randomly choose turn order 1 for Romeo 0 for Juliet
        int damage, dodge;

        if (round) { // Romeo goes first
            dodge = rand() % 2; // Randomly choose if Juliet can dodge Romeo's attack
            printf("Romeo attacks Juliet!\n");
            if (dodge) {
                printf("Juliet dodges Romeo's attack!\n");
                continue;
            }
            damage = rand() % 30 + 10; // Randomly generate damage between 10 and 40
            juliet_health -= damage;
            printf("Juliet takes %d damage from Romeo's attack!\n", damage);
            printf("Juliet's health is now %d!\n", juliet_health);
        } else { // Juliet goes first
            dodge = rand() % 2; // Randomly choose if Romeo can dodge Juliet's attack
            printf("Juliet attacks Romeo!\n");
            if (dodge) {
                printf("Romeo dodges Juliet's attack!\n");
                continue;
            }
            damage = rand() % 30 + 10; // Randomly generate damage between 10 and 40
            romeo_health -= damage;
            printf("Romeo takes %d damage from Juliet's attack!\n", damage);
            printf("Romeo's health is now %d!\n", romeo_health);
        }

        // Check if either character has died
        if (romeo_health <= 0) {
            printf("Juliet has defeated Romeo! Romeo is dead!\n");
            break;
        }
        if (juliet_health <= 0) {
            printf("Romeo has defeated Juliet! Juliet is dead!\n");
            break;
        }
    }

    printf("\nThanks for playing Romeo and Juliet Battle Game!\n");
    return 0;
}