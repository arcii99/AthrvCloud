//FormAI DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_gameboard(int gameboard[ROWS][COLS]);
void print_gameboard(int gameboard[ROWS][COLS], int revealed[ROWS][COLS]);
void shuffle(int array[], int size);
int check_win(int revealed[ROWS][COLS]);

int main() {
    int gameboard[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int num_pairs = (ROWS * COLS) / 2;
    int pairs_remaining = num_pairs;
    int current_selection[2] = {-1, -1};
    int selection_counter = 0;
    int num_moves = 0;
    int i, j;
    int game_over = 0;
    
    // Initialize gameboard with pairs of numbers
    initialize_gameboard(gameboard);
    
    // Shuffle the gameboard
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int index = gameboard[i][j];
            shuffle(gameboard[index], num_pairs);
        }
    }
    
    printf("Welcome to the Memory Game!\n");
    printf("Match all the pairs to win!\n");
    printf("Enter row and column coordinates separated by a space to reveal a card.\n\n");
    
    // Main game loop
    while (!game_over) {
        print_gameboard(gameboard, revealed);
        
        if (pairs_remaining == 0) {
            printf("Congratulations, you won in %d moves!\n", num_moves);
            game_over = 1;
        }
        
        printf("Enter your selection: ");
        scanf("%d %d", &i, &j);
        
        // Ensure that selection is valid
        if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
            printf("Invalid selection.\n");
            continue;
        }
        
        // Check if card has already been revealed
        if (revealed[i][j]) {
            printf("That card has already been revealed.\n");
            continue;
        }
        
        // Record the current selection
        if (selection_counter == 0) {
            current_selection[0] = i;
            current_selection[1] = j;
            revealed[i][j] = 1;
            selection_counter++;
        } else if (selection_counter == 1) {
            current_selection[0] = gameboard[current_selection[0]][current_selection[1]];
            current_selection[1] = gameboard[i][j];
            revealed[i][j] = 1;
            num_moves++;
            selection_counter = 0;
            
            if (current_selection[0] == current_selection[1]) {
                printf("You found a pair!\n");
                pairs_remaining--;
            } else {
                printf("Sorry, not a match.\n");
                revealed[current_selection[0]][current_selection[1]] = 0;
                revealed[i][j] = 0;
            }
        }
    }
    
    return 0;
}

// Initialize gameboard with pairs of numbers
void initialize_gameboard(int gameboard[ROWS][COLS]) {
    int i, j, k;
    int num_pairs = (ROWS * COLS) / 2;
    int pairs[num_pairs];
    
    for (i = 0; i < num_pairs; i++) {
        pairs[i] = i;
    }
    
    shuffle(pairs, num_pairs);
    
    k = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            gameboard[i][j] = pairs[k / 2];
            k++;
        }
    }
}

// Print the gameboard with revealed cards
void print_gameboard(int gameboard[ROWS][COLS], int revealed[ROWS][COLS]) {
    int i, j;
    
    printf(" ");
    for (j = 0; j < COLS; j++) {
        printf(" %d", j);
    }
    printf("\n");
    
    for (i = 0; i < ROWS; i++) {
        printf("%d", i);
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf(" %d", gameboard[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Shuffle an array of integers using Fisher-Yates shuffle
void shuffle(int array[], int size) {
    int i, j, temp;
    
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
} 

// Check if the game has been won
int check_win(int revealed[ROWS][COLS]) {
    int i, j;
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (!revealed[i][j]) {
                return 0;
            }
        }
    }
    
    return 1;
}