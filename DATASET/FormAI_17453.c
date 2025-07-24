//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 20; // Starting health
int gold = 0; // Starting gold
int max_health = 20; // Maximum health
int min_gold = 10; // Minimum gold
int max_gold = 50; // Maximum gold

// Function to generate a random number for gold
int random_gold() {
    return (rand() % (max_gold - min_gold + 1)) + min_gold;
}

// Function to handle room one
void room_one() {
    printf("You enter a dark room with a single exit to the north and a strange object in the center.\n");
    printf("What would you like to do? (type 'help' for options)\n");

    char input[100];
    fgets(input, 100, stdin);

    while (1) {
        // Handle user input
        if (strcmp(input, "help\n") == 0) {
            printf("Options: examine, north\n");

        } else if (strcmp(input, "examine\n") == 0) {
            printf("You approach the strange object and discover it is a chest. You open it and find %d gold!\n", random_gold());
            gold += random_gold();

        } else if (strcmp(input, "north\n") == 0) {
            printf("You leave the room and enter a long hallway.\n");
            break;

        } else {
            printf("Invalid input. Type 'help' for options.\n");
        }

        printf("What would you like to do now?\n");
        fgets(input, 100, stdin);
    }
}

// Function to handle room two
void room_two() {
    printf("You come to a fork in the hallway with two paths, one to the left and one to the right. \n");
    printf("Which path will you take? (type 'help' for options)\n");

    char input[100];
    fgets(input, 100, stdin);

    while (1) {
        // Handle user input
        if (strcmp(input, "help\n") == 0) {
            printf("Options: left, right\n");

        } else if (strcmp(input, "left\n") == 0) {
            printf("You follow the left path and come to a room with a monster inside. The monster attacks you!\n");
            health -= 5;
            if (health <= 0) {
                printf("You died. Game over.\n");
                exit(0);
            } else {
                printf("You defeated the monster, but took some damage. You have %d health remaining.\n", health);
            }

        } else if (strcmp(input, "right\n") == 0) {
            printf("You follow the right path and find a pile of gold on the ground. You take the gold and add it to your collection.\n");
            gold += random_gold();

        } else {
            printf("Invalid input. Type 'help' for options.\n");
        }

        printf("What would you like to do next?\n");
        fgets(input, 100, stdin);
    }
}

// Function to handle the final room
void final_room() {
    printf("You come to the end of the hallway and find a treasure room with piles of gold.\n");
    printf("You take as much gold as you can carry and leave the dungeon victorious!\n");
    printf("Congratulations! You completed the adventure with %d health and %d gold.\n", health, gold);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Adventure Game! You have %d health and 0 gold.\n", health);

    room_one();
    room_two();
    final_room();

    return 0;
}