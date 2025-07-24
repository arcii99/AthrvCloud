//FormAI DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the needed constants and variables

#define ROWS 4
#define COLUMNS 4
#define BOARD_SIZE 16
#define MAX_GUESSES 8
#define TRUE 1
#define FALSE 0

int board[ROWS][COLUMNS]; // Game board
int guess_board[ROWS][COLUMNS]; // Board showing guesses
int choices[BOARD_SIZE / 2]; // Available choices for the game
int num_choices = BOARD_SIZE / 2; // Number of available choices
int guesses_left = MAX_GUESSES; // Number of guesses left
int num_pairs_found = 0; // Number of pairs found
int game_won = FALSE; // Whether the game has been won
int game_over = FALSE; // Whether the game is over

// Function definitions

void init_board();
void init_choices();
void shuffle_choices();
void print_board();
void print_guess_board();
int do_guess(int, int);
void check_for_pairs();

// Main game loop

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    init_board(); // Create the game board
    init_choices(); // Generate available choices
    shuffle_choices(); // Shuffle the choices
    print_board(); // Print the game board
    
    while (!game_over) {
        int row, col;
        
        printf("\nGuesses left: %d\n", guesses_left);
        printf("Enter row (1-4): ");
        scanf("%d", &row);
        printf("Enter column (1-4): ");
        scanf("%d", &col);
        
        int result = do_guess(row - 1, col - 1);
        
        if (!result) {
            guesses_left--;
            
            if (guesses_left == 0) {
                game_over = TRUE;
                printf("\nSorry, you ran out of guesses. Game over!\n");
            }
        }
        
        check_for_pairs();
        
        if (num_pairs_found == BOARD_SIZE / 2) {
            game_over = TRUE;
            game_won = TRUE;
            printf("\nCongratulations! You won the game!\n");
        }
        
        print_guess_board(); // Print guesses so far
    }
    
    print_board(); // Print the final state of the board
    
    return 0;
}

// Initialize the game board

void init_board() {
    int i, j;
    int k = 0;
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = -1;
            guess_board[i][j] = '?';
        }
    }
}

// Initialize the available choices

void init_choices() {
    int i;
    
    for (i = 0; i < num_choices; i++) {
        choices[i] = i / 2;
    }
}

// Shuffle the available choices

void shuffle_choices() {
    int i;
    
    for (i = 0; i < num_choices; i++) {
        int temp = choices[i];
        int rand_index = rand() % num_choices;
        
        choices[i] = choices[rand_index];
        choices[rand_index] = temp;
    }
}

// Print the game board

void print_board() {
    int i, j;
    
    printf("\n");
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] == -1) {
                printf("    |");
            } else {
                printf(" %2d |", board[i][j]);
            }
        }
        
        printf("\n");
        
        for (j = 0; j < COLUMNS; j++) {
            printf("----+");
        }
        
        printf("\n");
    }
}

// Print the board showing guesses so far

void print_guess_board() {
    int i, j;
    
    printf("\n");
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf(" %2c |", guess_board[i][j]);
        }
        
        printf("\n");
        
        for (j = 0; j < COLUMNS; j++) {
            printf("----+");
        }
        
        printf("\n");
    }
}

// Process a guess from the player

int do_guess(int row, int col) {
    if (guess_board[row][col] != '?') {
        printf("\nSorry, that spot has already been guessed!\n");
        return 1; // Guess failed
    }
    
    int choice = board[row][col];
    guess_board[row][col] = choice + 'A'; // Change to a letter to indicate choice
    
    if (choice == -1) {
        printf("\nSorry, no match at that location!\n");
        return 0; // Guess succeeded but no match
    }
    
    printf("\nCongratulations, you found a match!\n");
    return 1; // Guess succeeded and found a match
}

// Check if any pairs have been found

void check_for_pairs() {
    int i, j;
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (guess_board[i][j] != '?') {
                continue;
            }
            
            int choice = board[i][j];
            
            if (choice == -1) {
                continue;
            }
            
            int k, l;
            
            for (k = 0; k < ROWS; k++) {
                for (l = 0; l < COLUMNS; l++) {
                    if ((k == i && l == j) || guess_board[k][l] == '?') {
                        continue;
                    }
                    
                    int other_choice = board[k][l];
                    
                    if (choice == other_choice) {
                        guess_board[i][j] = choice + 'A';
                        guess_board[k][l] = choice + 'A';
                        num_pairs_found++;
                        return;
                    }
                }
            }
        }
    }
}