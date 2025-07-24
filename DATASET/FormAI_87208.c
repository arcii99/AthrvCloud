//FormAI DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

int main(int argc, char *argv[]) {
    int board[BOARD_SIZE] = {0};
    int revealed[BOARD_SIZE] = {0};
    int num_turns = 0;
    
    // Seed the random number generator using current time
    srand(time(NULL));
    
    // Initialize the board with random numbers
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = rand() % 8 + 1;
    }
    
    // Print the board
    printf("MEMORY GAME\n");
    printf("===========");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n| ");
        if (revealed[i]) {
            printf("%d ", board[i]);
        } else {
            printf("? ");
        }
        printf("|  ");
        // Print a newline after every fourth square
        if ((i+1) % 4 == 0) {
            printf("\n=============");
        }
    }
    printf("\n\n");
    
    int choice1, choice2;
    while (1) {
        // Prompt for the first choice
        printf("Pick a square (1-16): ");
        scanf("%d", &choice1);
        printf("\n");
        
        // Make sure the choice is valid
        if (choice1 < 1 || choice1 > 16) {
            printf("Invalid choice. Try again.\n\n");
            continue;
        }
        if (revealed[choice1-1]) {
            printf("That square has already been chosen. Try again.\n\n");
            continue;
        }
        
        // Reveal the first choice
        revealed[choice1-1] = 1;
        num_turns++;
        
        // Print the board with the first choice revealed
        printf("MEMORY GAME\n");
        printf("===========");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("\n| ");
            if (revealed[i]) {
                printf("%d ", board[i]);
            } else {
                printf("? ");
            }
            printf("|  ");
            if ((i+1) % 4 == 0) {
                printf("\n=============");
            }
        }
        printf("\n\n");
        
        // Prompt for the second choice
        printf("Pick another square (1-16): ");
        scanf("%d", &choice2);
        printf("\n");
        
        // Make sure the choice is valid
        if (choice2 < 1 || choice2 > 16) {
            printf("Invalid choice. Try again.\n\n");
            revealed[choice1-1] = 0;
            num_turns--;
            continue;
        }
        if (revealed[choice2-1]) {
            printf("That square has already been chosen. Try again.\n\n");
            revealed[choice1-1] = 0;
            num_turns--;
            continue;
        }
        
        // Reveal the second choice
        revealed[choice2-1] = 1;
        num_turns++;
        
        // Print the board with both choices revealed
        printf("MEMORY GAME\n");
        printf("===========");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("\n| ");
            if (revealed[i]) {
                printf("%d ", board[i]);
            } else {
                printf("? ");
            }
            printf("|  ");
            if ((i+1) % 4 == 0) {
                printf("\n=============");
            }
        }
        printf("\n\n");
        
        // Check if the choices match
        if (board[choice1-1] == board[choice2-1]) {
            printf("Match!\n\n");
        } else {
            printf("No match.\n\n");
            revealed[choice1-1] = 0;
            revealed[choice2-1] = 0;
            num_turns -= 2;
        }
        
        // Check if the game is over
        int game_over = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (!revealed[i]) {
                game_over = 0;
                break;
            }
        }
        if (game_over) {
            printf("Game over! You completed the game in %d turns.\n", num_turns);
            break;
        }
    }
    
    return 0;
}