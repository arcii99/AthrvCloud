//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for randomization
    int player_hp = 100;
    int ghoul_hp = 50;
    int werewolf_hp = 75;
    int ghost_hp = 60;

    printf("\nWelcome to the Haunted House Simulator!\n\n");

    while (player_hp > 0) { 
        // Player encounters a random creature in each room
        int creature = rand() % 3;
        switch (creature) {
            case 0:
                printf("You enter a room and are faced with a ghoul!\n");
                while (ghoul_hp > 0) {
                    int attack = rand() % 10 + 1;
                    ghoul_hp -= attack;
                    printf("You attack the ghoul for %d damage. The ghoul has %d HP left.\n", attack, ghoul_hp);
                    attack = rand() % 5 + 1;
                    player_hp -= attack;
                    printf("The ghoul claws you for %d damage. You have %d HP left.\n", attack, player_hp);
                }
                printf("You vanquish the ghoul and move on to the next room.\n\n");
                ghoul_hp = 50;
                break;
            case 1:
                printf("You enter a room and are faced with a werewolf!\n");
                while (werewolf_hp > 0) {
                    int attack = rand() % 15 + 1;
                    werewolf_hp -= attack;
                    printf("You attack the werewolf for %d damage. The werewolf has %d HP left.\n", attack, werewolf_hp);
                    attack = rand() % 10 + 1;
                    player_hp -= attack;
                    printf("The werewolf bites you for %d damage. You have %d HP left.\n", attack, player_hp);
                }
                printf("You defeat the werewolf and move on to the next room.\n\n");
                werewolf_hp = 75;
                break;
            case 2:
                printf("You enter a room and are faced with a ghost!\n");
                while (ghost_hp > 0) {
                    int attack = rand() % 5 + 1;
                    ghost_hp -= attack;
                    printf("You attack the ghost for %d damage. The ghost has %d HP left.\n", attack, ghost_hp);
                    int roll = rand() % 2;
                    if (roll == 0) {
                        printf("The ghost phases through your body, dealing no damage.\n");
                    } else {
                        attack = rand() % 20 + 1;
                        player_hp -= attack;
                        printf("The ghost possesses you for %d damage. You have %d HP left.\n", attack, player_hp);
                    }
                }
                printf("You banish the ghost and move on to the next room.\n\n");
                ghost_hp = 60;
                break;
            default:
                printf("An error has occurred. You are trapped in this room forever.\n");
                return 1;
        }
        // Check if the player has survived all the rooms
        if (player_hp > 0) {
            printf("You move on to the next room...\n\n");
        } else {
            printf("You succumb to your injuries and die.\n");
            return 0;
        }
    }
}