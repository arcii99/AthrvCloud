//FormAI DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 20 // The number of cards in the game
#define NUM_COLS 5 // The number of columns in the game board

// Function prototypes
void create_board(int board[][NUM_COLS], int cards[]);
void shuffle(int arr[], int n);
void display_board(int board[][NUM_COLS]);
void flip_card(int row, int col, int board[][NUM_COLS], int cards[]);
int check_for_match(int board[][NUM_COLS], int cards[]);
int get_input();
void clear_screen();

// Main function
int main()
{
    int board[NUM_CARDS/NUM_COLS][NUM_COLS]; // The game board
    int cards[NUM_CARDS]; // An array to keep track of the cards
    int num_turns = 0; // The number of turns taken
    int matches = 0; // The number of matches made
    int row, col; // The row and column of the selected card

    // Seed random number generator
    srand((unsigned) time(NULL));

    // Create and shuffle the cards
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = (i+1)/2; // Each pair of cards has the same number
    }
    shuffle(cards, NUM_CARDS);

    // Create the game board
    create_board(board, cards);

    // Display the game board
    display_board(board);

    // Main game loop
    while (matches < NUM_CARDS/2) {
        // Get input from user
        printf("Enter row and column of card to flip: ");
        row = get_input();
        col = get_input();

        // Check if input is valid
        if ((row < 0 || row >= NUM_CARDS/NUM_COLS) || (col < 0 || col >= NUM_COLS)) {
            printf("\nInvalid input! Please try again.\n");
            continue;
        }

        // Flip selected card
        flip_card(row, col, board, cards);

        // Display updated game board
        clear_screen();
        display_board(board);

        // Check for a match
        if (check_for_match(board, cards)) {
            printf("\nYou made a match!\n");
            matches++;
        } else {
            printf("\nNo match. Try again.\n");
            // Flip the cards back over
            flip_card(row, col, board, cards);
            flip_card(row, col+1, board, cards);
            // Display updated game board
            clear_screen();
            display_board(board);
        }

        num_turns++;
        printf("Number of turns taken: %d\n", num_turns);
    }

    printf("\nCongratulations! You won the game in %d turns.\n", num_turns);

    return 0;
}

// Function to create the game board
void create_board(int board[][NUM_COLS], int cards[])
{
    int card_index = 0; // Index of next card in the array

    // Fill each row of the board with cards
    for (int i = 0; i < NUM_CARDS/NUM_COLS; i++) {
        // Fill each column in the row with a card
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = cards[card_index];
            card_index++;
        }
    }
}

// Function to shuffle the cards
void shuffle(int arr[], int n)
{
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to display the game board
void display_board(int board[][NUM_COLS])
{
    printf("\n   0  1  2  3  4\n");
    printf("------------------\n");
    for (int i = 0; i < NUM_CARDS/NUM_COLS; i++) {
        printf("%d |", i);
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j] == 0) {
                printf("   ");
            } else {
                printf(" %d ", board[i][j]);
            }
            printf("|");
        }
        printf("\n------------------\n");
    }
}

// Function to flip a card
void flip_card(int row, int col, int board[][NUM_COLS], int cards[])
{
    board[row][col] = cards[row*NUM_COLS + col];
}

// Function to check for a match
int check_for_match(int board[][NUM_COLS], int cards[])
{
    int card1 = board[0][0];
    int card2 = 0;

    // Check if there are any flipped over cards on the board
    for (int i = 0; i < NUM_CARDS/NUM_COLS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j] != 0) {
                card2 = board[i][j];
                break;
            }
        }
        if (card2 != 0) {
            break;
        }
    }

    // Check if there is a match
    if (card1 == card2) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get input from the user
int get_input()
{
    int input;
    scanf("%d", &input);
    return input;
}

// Function to clear the screen
void clear_screen()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}