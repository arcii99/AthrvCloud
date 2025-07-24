//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(char board[][BOARD_SIZE]);
void reset_board(char board[][BOARD_SIZE], char letters[]);
void swap(char* a, char* b);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the letters to use in the game
    char letters[BOARD_SIZE * BOARD_SIZE / 2] = {'A', 'B', 'C', 'D'};
    
    // Create the game board
    char board[BOARD_SIZE][BOARD_SIZE];
    
    // Reset the board
    reset_board(board, letters);
    
    // Print out the starting board
    printf("Welcome to the Memory Game! Here is your starting board:\n");
    print_board(board);
    
    // Give the user some time to look at the board before clearing it
    printf("Take a good look at the board, then press enter to clear it.\n");
    getchar();
    system("clear");
    
    // Reset the board again
    reset_board(board, letters);
    
    // Start the game loop
    int matches = 0;
    int attempts = 0;
    int first_choice_row = 0;
    int first_choice_col = 0;
    while (matches < BOARD_SIZE * BOARD_SIZE / 2) {
        // Print out the current board state
        printf("Attempts: %d\n", attempts);
        print_board(board);
        
        // Get the user's first choice
        printf("Enter the row and column of your first choice (e.g. 1 2): ");
        scanf("%d %d", &first_choice_row, &first_choice_col);
        printf("You chose: %c\n", board[first_choice_row][first_choice_col]);
        
        // Get the user's second choice
        int second_choice_row = 0;
        int second_choice_col = 0;
        while (second_choice_row == 0 && second_choice_col == 0) {
            printf("Enter the row and column of your second choice (e.g. 1 2): ");
            scanf("%d %d", &second_choice_row, &second_choice_col);
            if (board[second_choice_row][second_choice_col] == ' ') {
                printf("You already matched that letter! Try again.\n");
                second_choice_row = 0;
                second_choice_col = 0;
            }
        }
        printf("You chose: %c\n", board[second_choice_row][second_choice_col]);
        
        // Check if the choices match
        if (board[first_choice_row][first_choice_col] == board[second_choice_row][second_choice_col]) {
            printf("You got a match!\n");
            board[first_choice_row][first_choice_col] = ' ';
            board[second_choice_row][second_choice_col] = ' ';
            matches++;
        } else {
            printf("No match this time.\n");
            attempts++;
        }
        
        // Clear the screen and continue
        system("clear");
    }
    
    // Print out the final board state and the user's score
    printf("Congratulations! You completed the game in %d attempts.\n", attempts);
    print_board(board);
    
    return 0;
}

void print_board(char board[][BOARD_SIZE]) {
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

void reset_board(char board[][BOARD_SIZE], char letters[]) {
    // Initialize the board with blank spaces
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = ' ';
        }
    }
    
    // Shuffle the letters and add them to the board
    int letter_count = BOARD_SIZE * BOARD_SIZE / 2;
    for (int i = 0; i < letter_count; i++) {
        int rand1 = rand() % BOARD_SIZE;
        int rand2 = rand() % BOARD_SIZE;
        while (board[rand1][rand2] != ' ') {
            rand1 = rand() % BOARD_SIZE;
            rand2 = rand() % BOARD_SIZE;
        }
        board[rand1][rand2] = letters[i];
        rand1 = rand() % BOARD_SIZE;
        rand2 = rand() % BOARD_SIZE;
        while (board[rand1][rand2] != ' ') {
            rand1 = rand() % BOARD_SIZE;
            rand2 = rand() % BOARD_SIZE;
        }
        board[rand1][rand2] = letters[i];
    }
    
    // Shuffle the board
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int rand1 = rand() % BOARD_SIZE;
        int rand2 = rand() % BOARD_SIZE;
        int rand3 = rand() % BOARD_SIZE;
        int rand4 = rand() % BOARD_SIZE;
        swap(&(board[rand1][rand2]), &(board[rand3][rand4]));
    }
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}