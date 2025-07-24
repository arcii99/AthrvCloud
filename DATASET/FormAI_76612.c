//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// function prototypes
void initialize_board(int board[ROWS][COLS]);
void shuffle(int cards[ROWS * COLS]);
void print_board(int board[ROWS][COLS], int cards[ROWS * COLS], int num_turns);
void get_coords(int board[ROWS][COLS], int *row, int *col);
int get_card_val(int board[ROWS][COLS], int row, int col);
void update_board(int board[ROWS][COLS], int row1, int col1, int row2, int col2);
int check_for_match(int board[ROWS][COLS], int row1, int col1, int row2, int col2);

int main() {
    int board[ROWS][COLS];
    int cards[ROWS * COLS];
    int row1, col1, row2, col2, num_turns = 0, num_matches = 0;
    
    // seed RNG
    srand(time(NULL));
    
    // initialize board and shuffle cards
    initialize_board(board);
    shuffle(cards);
    
    // print initial board
    print_board(board, cards, num_turns);
    
    // game loop
    while (num_matches < ROWS * COLS / 2) {
        // prompt for first card
        printf("Enter the row and column of the first card: ");
        get_coords(board, &row1, &col1);
        
        // check if already matched or flipped over
        while (cards[row1 * COLS + col1] == -1 || board[row1][col1] == 1) {
            printf("Card already matched or flipped over. Enter the row and column of the first card: ");
            get_coords(board, &row1, &col1);
        }
        
        // reveal first card
        board[row1][col1] = 1;
        print_board(board, cards, num_turns);
        
        // prompt for second card
        printf("Enter the row and column of the second card: ");
        get_coords(board, &row2, &col2);
        
        // check if already matched or flipped over
        while (cards[row2 * COLS + col2] == -1 || board[row2][col2] == 1) {
            printf("Card already matched or flipped over. Enter the row and column of the second card: ");
            get_coords(board, &row2, &col2);
        }
        
        // reveal second card
        board[row2][col2] = 1;
        print_board(board, cards, num_turns);
        
        // check for match
        if (check_for_match(board, row1, col1, row2, col2) == 1) {
            // update cards array
            cards[row1 * COLS + col1] = -1;
            cards[row2 * COLS + col2] = -1;
            
            // increment matches
            num_matches++;
        } else {
            // update board
            update_board(board, row1, col1, row2, col2);
        }
        
        // increment turns
        num_turns++;
    }
    
    // print final board
    print_board(board, cards, num_turns);
    printf("Congratulations! You matched all the cards in %d turns.\n", num_turns);
    
    return 0;
}

/*
 * Initializes the board with -1 values.
 */
void initialize_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

/*
 * Shuffles the cards array.
 */
void shuffle(int cards[ROWS * COLS]) {
    for (int i = 0; i < ROWS * COLS; i++) {
        cards[i] = i / 2;
    }
    
    for (int i = 0; i < ROWS * COLS; i++) {
        int j = rand() % (ROWS * COLS);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

/*
 * Prints the current state of the board.
 */
void print_board(int board[ROWS][COLS], int cards[ROWS * COLS], int num_turns) {
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("%d ", cards[i * COLS + j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("Number of turns: %d\n", num_turns);
}

/*
 * Prompts the user for row and column coordinates.
 */
void get_coords(int board[ROWS][COLS], int *row, int *col) {
    scanf("%d %d", row, col);
    while (*row < 0 || *row >= ROWS || *col < 0 || *col >= COLS) {
        printf("Invalid row or column. Enter the row and column of the card: ");
        scanf("%d %d", row, col);
    }
}

/*
 * Returns the value of the card at the specified coordinates.
 */
int get_card_val(int board[ROWS][COLS], int row, int col) {
    return board[row][col];
}

/*
 * Updates the board to flip over the cards at the specified coordinates.
 */
void update_board(int board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    board[row1][col1] = 0;
    board[row2][col2] = 0;
}

/*
 * Checks if the cards at the specified coordinates are a match.
 */
int check_for_match(int board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    return get_card_val(board, row1, col1) == get_card_val(board, row2, col2);
}