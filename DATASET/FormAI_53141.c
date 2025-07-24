//FormAI DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Function prototypes
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]);
void shuffle(int deck[], int num_cards);
void initialize_deck(int deck[], int num_cards);
int get_input();
void update_board(int card, int board[BOARD_SIZE][BOARD_SIZE]);
int check_match(int board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int deck[BOARD_SIZE*BOARD_SIZE/2];
    int num_cards = BOARD_SIZE*BOARD_SIZE/2;
    int card1, card2;

    initialize_board(board);
    initialize_deck(deck, num_cards);

    while(check_match(board) != 1) {
        // Shuffle deck
        shuffle(deck, num_cards);

        // Show user the board
        print_board(board);

        // Get user input for card1
        card1 = get_input();

        // Update board with card1
        update_board(card1, board);
        print_board(board);

        // Get user input for card2
        card2 = get_input();

        // Update board with card2
        update_board(card2, board);
        print_board(board);

        // Determine if there is a match
        if(deck[card1] == deck[card2]) {
            printf("Match found!\n");
        } else {
            printf("No match.\n");
            board[card1/BOARD_SIZE][card1%BOARD_SIZE] = 0;
            board[card2/BOARD_SIZE][card2%BOARD_SIZE] = 0;
        }
    }

    printf("Congratulations, you won the game!\n");
    return 0;
}

// Prints the board to the console
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Initializes the board with 0's
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Shuffles the deck of cards
void shuffle(int deck[], int num_cards) {
    srand(time(NULL));

    for(int i=num_cards-1; i>0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Initializes the deck of cards
void initialize_deck(int deck[], int num_cards) {
    for(int i=0; i<num_cards; i++) {
        deck[i] = (i%2) + 1;
    }
}

// Gets user input for a card
int get_input() {
    int card;
    printf("Enter a card (0-%d): ", BOARD_SIZE*BOARD_SIZE-1);
    scanf("%d", &card);
    return card;
}

// Updates the board with the selected card
void update_board(int card, int board[BOARD_SIZE][BOARD_SIZE]) {
    int row = card/BOARD_SIZE;
    int col = card%BOARD_SIZE;
    board[row][col] = card+1;
}

// Determines if the board is in a winning state
int check_match(int board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}