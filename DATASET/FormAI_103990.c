//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number between two values
int get_random(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to display a ghost
void display_ghost()
{
    printf("\n");
    printf("           _________\n");
    printf("          /         \\\n");
    printf("         /           \\\n");
    printf("        /             \\\n");
    printf("       /  ( o )   ( o )  \\\n");
    printf("      /                     \\\n");
    printf("     /                       \\\n");
    printf("     \\                       /\n");
    printf("      \\                     /\n");
    printf("       \\                   /\n");
    printf("        \\                 /\n");
    printf("         \\_______________/\n");
    printf("\n");
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Display the title screen
    printf("Welcome to the Haunted House Simulator!\n\n");
    
    // Display the instructions
    printf("You are trapped in a haunted house and must find a way out.\n");
    printf("To move between rooms, enter 'n', 's', 'e', or 'w'.\n\n");
    
    // Set up the initial room
    char room[10][10] = {
        {' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' '},
        {' ', '#', '#', '#', ' ', ' ', '#', '#', '#', ' '},
        {' ', ' ', ' ', '#', '#', ' ', '#', ' ', ' ', ' '},
        {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' '},
        {'#', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' '},
        {' ', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    int player_x = 4;
    int player_y = 0;
    int has_key = 0;
    int has_flashlight = 0;
    
    // Loop until the player finds the exit
    while (1) {
        // Display the current room
        printf("\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == player_y && j == player_x) {
                    printf("O");
                } else {
                    printf("%c", room[i][j]);
                }
            }
            printf("\n");
        }
        
        // Check for win condition
        if (player_x == 9 && player_y == 4 && has_key) {
            printf("\n");
            printf("Congratulations, you found the exit!\n");
            printf("Thanks for playing the Haunted House Simulator!\n\n");
            break;
        }
        
        // Check for game over conditions
        if (room[player_y][player_x] == '#' && !has_flashlight) {
            display_ghost();
            printf("Oh my god, you were just attacked by a ghost and killed!\n");
            printf("Thanks for playing the Haunted House Simulator!\n\n");
            break;
        } else if (room[player_y][player_x] == '#' && has_flashlight) {
            printf("You shine your flashlight on the ghost and it disappears!\n");
            room[player_y][player_x] = ' ';
        }
        
        // Get user input
        char input;
        printf("Which way do you want to go? ");
        scanf(" %c", &input);
        
        // Handle user input
        switch(input) {
            case 'n':
                if (player_y > 0) {
                    player_y--;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            case 's':
                if (player_y < 9) {
                    player_y++;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            case 'e':
                if (player_x < 9) {
                    player_x++;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            case 'w':
                if (player_x > 0) {
                    player_x--;
                } else {
                    printf("You can't go that way!\n");
                }
                break;
            default:
                printf("I didn't understand that!\n");
        }
        
        // Spawn items randomly
        if (get_random(1, 100) <= 20) {
            int item = get_random(1, 2);
            if (item == 1 && !has_key) {
                printf("You found a key!\n");
                has_key = 1;
            } else if (item == 2 && !has_flashlight) {
                printf("You found a flashlight!\n");
                has_flashlight = 1;
            }
        }
    }
    
    return 0;
}