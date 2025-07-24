//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Set up random number generator
    srand(time(NULL));
    
    // Create variables for game state
    int is_running = 1;
    int player_health = 100;
    int current_room = 0;

    // Create arrays for descriptions and options
    char room_descriptions[6][100] = {
        "You are standing in a dimly lit entrance hall. To your left is a creaky old staircase, to your right an ornate doorway.",
        "You are in the kitchen. A cauldron bubbles over an open fire, filling the room with a sickly sweet smell.",
        "You have stumbled into a cobweb-filled living room. A dusty grand piano stands against one wall.",
        "You are in a long hallway lined with portraits. Their eyes follow you as you walk by.",
        "You find yourself in a cluttered study. Papers and books cover every surface.",
        "You are standing in a dark, musty cellar. Water drips from the ceiling onto the damp floor."
    };

    char room_options[6][3][50] = {
        { // Entrance hall
            "Go up the stairs",
            "Go through the doorway",
            "Stay put"
        },
        { // Kitchen
            "Drink the potion",
            "Search the cupboards",
            "Flee the room"
        },
        { // Living room
            "Play the piano",
            "Investigate the fireplace",
            "Leave the room"
        },
        { // Hallway
            "Go left",
            "Go right",
            "Continue straight"
        },
        { // Study
            "Read the papers",
            "Solve the puzzle",
            "Leave the room"
        },
        { // Cellar
            "Search for a way out",
            "Search for weapons",
            "Wait for help"
        }
    };

    // Game loop
    while (is_running) {
        // Print room description
        printf("%s\n", room_descriptions[current_room]);

        // Print options
        printf("What do you do?\n");
        printf("1. %s\n", room_options[current_room][0]);
        printf("2. %s\n", room_options[current_room][1]);
        printf("3. %s\n", room_options[current_room][2]);

        // Get user input
        int input;
        scanf("%d", &input);

        // Handle user input
        switch(current_room) {
            case 0: // Entrance hall
                switch(input) {
                    case 1: // Stairs
                        current_room = 3; // Move to hallway
                        break;
                    case 2: // Doorway
                        current_room = 1; // Move to kitchen
                        break;
                    case 3: // Stay put
                        printf("You cower in fear.\n");
                        break;
                    default:
                        printf("Invalid input.\n");
                }
                break;
            case 1: // Kitchen
                switch(input) {
                    case 1: // Drink potion
                        printf("You feel your health restored.");
                        player_health = 100;
                        break;
                    case 2: // Search cupboards
                        printf("You find a rusty knife.");
                        break;
                    case 3: // Flee
                        current_room = 0; // Move to entrance hall
                        break;
                    default:
                        printf("Invalid input.\n");
                }
                break;
            case 2: // Living room
                switch(input) {
                    case 1: // Play piano
                        printf("The keys are sticky and out of tune.");
                        break;
                    case 2: // Investigate fireplace
                        int roll = rand() % 100;
                        if (roll < 50) {
                            printf("You find a hidden passage!\n");
                            current_room = 5; // Move to cellar
                        } else {
                            printf("You find nothing of interest.\n");
                        }
                        break;
                    case 3: // Leave room
                        current_room = 3; // Move to hallway
                        break;
                    default:
                        printf("Invalid input.\n");
                }
                break;
            case 3: // Hallway
                switch(input) {
                    case 1: // Go left
                        current_room = 2; // Move to living room
                        break;
                    case 2: // Go right
                        printf("The door is locked.\n");
                        break;
                    case 3: // Continue straight
                        current_room = 4; // Move to study
                        break;
                    default:
                        printf("Invalid input.\n");
                }
                break;
            case 4: // Study
                switch(input) {
                    case 1: // Read papers
                        printf("The writing is illegible.\n");
                        break;
                    case 2: // Solve puzzle
                        printf("You hear a satisfying *click* as the puzzle is solved.\n");
                        break;
                    case 3: // Leave room
                        current_room = 3; // Move to hallway
                        break;
                    default:
                        printf("Invalid input.\n");
                }
                break;
            case 5: // Cellar
                switch(input) {
                    case 1: // Search for way out
                        printf("You find a small hole in the wall, but you're too big to fit through.\n");
                        break;
                    case 2: // Search for weapons
                        printf("You find a rusty axe, but it's too heavy to lift.\n");
                        break;
                    case 3: // Wait for help
                        printf("You huddle in a corner, hoping someone will find you soon.\n");
                        break;
                    default:
                        printf("Invalid input.\n");
                }
                break;
            default:
                printf("Error: Invalid room.\n");
        }

        // Check if player is still alive
        if (player_health <= 0) {
            printf("You have died.\n");
            is_running = 0;
        } else {
            printf("Your health is %d.\n", player_health);
        }
    }

    // Game over
    printf("Thanks for playing!\n");
    return 0;
}