//FormAI DATASET v1.0 Category: Memory Game ; Style: satisfied
/*
 * This is a C Memory Game program that allows users to play the classic game of Memory 
 * by matching pairs of cards. The goal of the game is to match all the pairs in the grid 
 * using the least number of moves possible.
 *
 * The program uses an array to store the shuffled cards, and another array to store 
 * the positions of the cards on the grid. Whenever the user makes a move, the program 
 * checks if the selected pair of cards is a match, and updates the score accordingly. 
 * The program also uses a timer to keep track of the time taken to complete the game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_CARDS (GRID_SIZE * GRID_SIZE)
#define MAX_MOVES (NUM_CARDS / 2)

void init_board(int board[][GRID_SIZE]);
void shuffle_cards(int cards[]);
void print_board(int board[][GRID_SIZE], int show_cards[]);
void get_move(int* row, int* col);
int is_valid_move(int row, int col, int show_cards[]);
void update_score(int board[][GRID_SIZE], int row1, int col1, int row2, int col2, int show_cards[], int* score);
void update_show_cards(int row1, int col1, int row2, int col2, int show_cards[]);
int check_win(int show_cards[]);
void print_result(int score, double elapsed_time);

int main()
{
    int board[GRID_SIZE][GRID_SIZE]; // the game board
    int show_cards[NUM_CARDS]; // array to store which cards are currently visible
    int cards[NUM_CARDS]; // array to store the value of the cards
    int moves = 0; // number of moves made by the player
    int score = 0; // player's score
    double start_time, end_time, elapsed_time; // variables to store start and end time of the game
    int row1, col1, row2, col2; // variables to store player's moves
    
    srand(time(NULL)); // initialize random seed
    
    init_board(board); // initialize game board
    shuffle_cards(cards); // shuffle the cards
    
    // initialize show_cards to 0
    for (int i = 0; i < NUM_CARDS; i++) {
        show_cards[i] = 0;
    }
    
    // start the game timer
    start_time = (double) clock() / CLOCKS_PER_SEC;
    
    printf("Welcome to Memory Game!\n");
    
    while (moves < MAX_MOVES) {
        printf("\n");
        print_board(board, show_cards); // print the game board
        
        // get player's move
        get_move(&row1, &col1);
        
        if (!is_valid_move(row1, col1, show_cards)) { // check if move is valid
            printf("Invalid move! Please try again.\n");
            continue;
        }
        
        // show the selected card
        show_cards[row1 * GRID_SIZE + col1] = 1;
        print_board(board, show_cards);
        
        // get player's second move
        get_move(&row2, &col2);
        
        if (!is_valid_move(row2, col2, show_cards)) { // check if move is valid
            printf("Invalid move! Please try again.\n");
            continue;
        }
        
        // show the second selected card
        show_cards[row2 * GRID_SIZE + col2] = 1;
        print_board(board, show_cards);
        
        // update score and show_cards array
        update_score(board, row1, col1, row2, col2, show_cards, &score);
        
        // update move counter
        moves++;
        
        if (check_win(show_cards)) { // check if all cards have been matched
            break;
        }
    }
    
    // calculate elapsed time
    end_time = (double) clock() / CLOCKS_PER_SEC;
    elapsed_time = end_time - start_time;
    
    // print final result
    print_result(score, elapsed_time);
    
    return 0;
}

// Initialize game board with card positions
void init_board(int board[][GRID_SIZE])
{
    int card_num = 1;
    
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            board[row][col] = card_num;
            card_num++;
        }
    }
}

// Shuffle the cards array
void shuffle_cards(int cards[])
{
    int i, j, temp;
    
    // initialize cards array with pairs of numbers
    for (i = 0; i < NUM_CARDS / 2; i++) {
        cards[i] = i + 1;
        cards[i + NUM_CARDS / 2] = i + 1;
    }
    
    // shuffle the cards array using Fisher-Yates algorithm
    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Print the game board
void print_board(int board[][GRID_SIZE], int show_cards[])
{
    printf("\n");
    
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (show_cards[row * GRID_SIZE + col]) { // if card is visible
                printf("%2d ", board[row][col]);
            } else {
                printf("   "); // print blank space
            }
        }
        printf("\n");
    }
}

// Get player's move (row and column)
void get_move(int* row, int* col)
{
    printf("Enter row and column of card: ");
    scanf("%d %d", row, col);
}

// Check if player's move is valid
int is_valid_move(int row, int col, int show_cards[])
{
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) { // check if row and column are valid
        return 0;
    }
    
    if (show_cards[row * GRID_SIZE + col]) { // check if card is already visible
        return 0;
    }
    
    return 1;
}

// Update player's score and show_cards array based on selected cards
void update_score(int board[][GRID_SIZE], int row1, int col1, int row2, int col2, int show_cards[], int* score)
{
    if (board[row1][col1] == board[row2][col2]) { // if cards are a match
        printf("Match found!\n");
        *score += 2;
    } else { // if cards are not a match
        printf("No match.\n");
        show_cards[row1 * GRID_SIZE + col1] = 0;
        show_cards[row2 * GRID_SIZE + col2] = 0;
        *score -= 1;
    }
}

// Update show_cards array to hide matched cards
void update_show_cards(int row1, int col1, int row2, int col2, int show_cards[])
{
    show_cards[row1 * GRID_SIZE + col1] = 0;
    show_cards[row2 * GRID_SIZE + col2] = 0;
}

// Check if all cards have been matched
int check_win(int show_cards[])
{
    for (int i = 0; i < NUM_CARDS; i++) {
        if (show_cards[i] == 0) {
            return 0;
        }
    }
    
    return 1;
}

// Print player's final score and elapsed time
void print_result(int score, double elapsed_time)
{
    printf("\n");
    printf("Final score: %d\n", score);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
}