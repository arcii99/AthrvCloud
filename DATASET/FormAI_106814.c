//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

// Function to initialize the game board with random Happy emojis
void init_game_board(char board[][COLS]) {
    srand(time(NULL)); // seed the random number generator with the current time
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int rand_num = rand() % 2;
            if (rand_num == 0) {
                board[i][j] = ':)'; // Happy emoji
            }
            else {
                board[i][j] = ':D'; // Big grin emoji
            }
        }
    }
}

// Function to print the game board to the console
void print_game_board(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%s", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the game board with new emojis
void update_game_board(char board[][COLS]) {
    srand(time(NULL)); // seed the random number generator with the current time
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int rand_num = rand() % 3;
            if (rand_num == 0) {
                board[i][j] = ':)'; // Happy emoji
            }
            else if (rand_num == 1) {
                board[i][j] = ':D'; // Big grin emoji
            }
            else {
                board[i][j] = ';)'; // Winking emoji
            }
        }
    }
}

int main() {
    char game_board[ROWS][COLS];

    // Initialize the game board with random Happy emojis
    init_game_board(game_board);

    while (1) {
        system("clear"); // Clear the console screen
        printf("Welcome to the Happy Game!\n\n");
        printf("Instructions: Press any key to refresh the game board with new Happy emojis.\n");
        printf("Press 'q' to quit.\n\n");

        // Print the game board to the console
        print_game_board(game_board);

        // Get user input from the keyboard
        char user_input = getchar();

        // Check if user wants to quit
        if (user_input == 'q') {
            break;
        }

        // Update the game board with new emojis
        update_game_board(game_board);
    }

    printf("\nBye! Thanks for playing the Happy Game!\n");

    return 0;
}