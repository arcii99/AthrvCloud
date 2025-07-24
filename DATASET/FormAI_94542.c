//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Introduction
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are about to embark on a spooky adventure through a haunted house!\n");
    printf("Do you have what it takes to survive?\n\n");

    // Game variables
    int health = 100;
    int damage = 0;
    int num_rooms_visited = 0;
    bool has_key = false;

    // Start game loop
    while (health > 0 && num_rooms_visited < 5) {
        // Increment number of rooms visited
        num_rooms_visited++;

        // Display room number
        printf("\n--- Room %d ---\n", num_rooms_visited);

        // Generate random event
        int event_num = rand() % 3;
        
        // Event 1: Safe room
        if (event_num == 0) {
            printf("Congratulations! You have found a safe room!\n");
            printf("Your health has been restored.\n");
            health = 100;
        }
        // Event 2: Ghost encounter
        else if (event_num == 1) {
            printf("Uh oh! You have encountered a ghost!\n");
            printf("You take 30 damage.\n");
            health -= 30;
            printf("Your health is now %d.\n", health);
        }
        // Event 3: Key room
        else {
            printf("You have found a room with a key!\n");
            printf("You pick up the key.\n");
            has_key = true;
        }

        // Check if player has key
        if (has_key && num_rooms_visited == 5) {
            printf("\nCongratulations! You have found the way out of the haunted house!\n");
            printf("You win!\n");
            return 0;
        }
        else if (num_rooms_visited == 5) {
            printf("\nYou have explored the entire haunted house, but you did not find the way out.\n");
            printf("You lose.\n");
            return 0;
        }
    }

    return 0;
}