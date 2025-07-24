//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LEN 50

int health = 100;
int ammo = 0;
bool key = false;
bool flashlight = false;

void print_intro() {
    printf("You find yourself in a dark and mysterious forest. You have no idea how you got here or what to do next.\n");
    printf("As you wander around, you see a couple of paths in front of you. Which one would you like to take?\n\n");
}

void print_options() {
    printf("1. Take the left path\n");
    printf("2. Take the right path\n");
    printf("3. Stay put and wait for help\n\n");
}

void print_status() {
    printf("You currently have %d health and %d ammo.\n", health, ammo);
    if(key) {
        printf("You have a key.\n");
    }
    if(flashlight) {
        printf("You have a flashlight.\n");
    }
    printf("\n");
}

void game_over() {
    printf("Game over. Thanks for playing!\n");
    exit(0);
}

void attack() {
    if(ammo > 0) {
        ammo--;
        printf("You shoot your gun and hit the monster. It retreats.\n");
    } else {
        printf("You don't have any ammo left.\n");
    }
    health -= 20;
    if(health <= 0) {
        game_over();
    } else {
        printf("The monster attacks back and you lose 20 health.\n");
        printf("You now have %d health.\n", health);
    }
}

int main() {
    int choice;
    char input[MAX_INPUT_LEN];

    print_intro();

    while(true) {
        print_options();

        fgets(input, MAX_INPUT_LEN, stdin);
        choice = atoi(input);

        if(choice == 1) {
            printf("You take the left path and stumble upon a monster.\n");
            printf("What do you do?\n\n");

            while(true) {
                printf("1. Attack the monster\n");
                printf("2. Run away\n");
                printf("3. Look around for useful items\n\n");

                fgets(input, MAX_INPUT_LEN, stdin);
                choice = atoi(input);

                if(choice == 1) {
                    attack();
                } else if(choice == 2) {
                    printf("You try to run away but the monster catches up to you and kills you.\n");
                    game_over();
                } else if(choice == 3) {
                    printf("You look around and find a key and a flashlight.\n");
                    printf("You pick them up and continue on your journey.\n");
                    key = true;
                    flashlight = true;
                    break;
                } else {
                    printf("Invalid choice. Please try again.\n");
                }
            }
        } else if(choice == 2) {
            printf("You take the right path and stumble upon a locked gate.\n");
            printf("What do you do?\n\n");

            if(!key) {
                printf("You don't have a key to open the gate.\n");
                printf("You decide to go back and explore other areas.\n");
            } else {
                printf("You use the key to open the gate.\n");
                printf("You walk through and find a stash of ammo.\n");
                printf("You pick it up and continue on your journey.\n");
                ammo += 10;
            }
        } else if(choice == 3) {
            printf("You stay put and wait for help.\n");
            printf("After a few hours, a search and rescue team finds you and takes you home.\n");
            printf("Congratulations, you've made it out of the forest!\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        print_status();
    }

}