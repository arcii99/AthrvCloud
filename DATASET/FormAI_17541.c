//FormAI DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6
#define MAX_PAIRS 9

// Define a struct to represent a card
typedef struct {
    char symbol;
    int is_face_up;
} Card;

// Define a struct to represent a game board
typedef struct {
    Card cards[BOARD_SIZE][BOARD_SIZE];
} Board;

// Define a function to initialize a new board with random cards
void init_board(Board *board) {
    // Define an array of possible symbols
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Define an array to track which symbols have been used
    int used_symbols[MAX_PAIRS] = {0};

    // Define variables to keep track of the number of pairs placed and the index of the current symbol
    int pairs_placed = 0;
    int current_symbol_index;

    // Seed the random number generator
    srand(time(NULL));

    // Loop through each card on the board and set its symbol randomly
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // If we've placed all the pairs, we can just pick any unused symbol
            if (pairs_placed == MAX_PAIRS) {
                current_symbol_index = rand() % (MAX_PAIRS + 1);
            }
            // Otherwise, we need to pick an unused symbol to place
            else {
                do {
                    current_symbol_index = rand() % MAX_PAIRS;
                } while (used_symbols[current_symbol_index]);
                used_symbols[current_symbol_index] = 1;
                pairs_placed++;
            }
            board->cards[i][j].symbol = symbols[current_symbol_index];
            board->cards[i][j].is_face_up = 0;
        }
    }
}

// Define a function to print the current state of the board
void print_board(Board *board) {
    // Print the column headers
    printf("    A   B   C   D   E   F\n");
    printf("  +---+---+---+---+---+---+\n");
    // Loop through each row of the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Print the row number
        printf("%d ", i+1);
        // Loop through each column of the row and print the card symbol or a face-down card
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].is_face_up) {
                printf("| %c ", board->cards[i][j].symbol);
            }
            else {
                printf("|   ");
            }
        }
        // Print the end of the row
        printf("|\n");
        printf("  +---+---+---+---+---+---+\n");
    }
}

// Define a function to prompt the user for a card choice
void get_card_choice(Board *board, int *choice_r, int *choice_c) {
    char col_letter;
    int row_num;

    do {
        printf("Enter the row and column of the card you want to flip (e.g. B3): ");
        scanf(" %c%d", &col_letter, &row_num);
        row_num--;
        *choice_r = row_num;
        switch(col_letter) {
            case 'a':
            case 'A':
                *choice_c = 0;
                break;
            case 'b':
            case 'B':
                *choice_c = 1;
                break;
            case 'c':
            case 'C':
                *choice_c = 2;
                break;
            case 'd':
            case 'D':
                *choice_c = 3;
                break;
            case 'e':
            case 'E':
                *choice_c = 4;
                break;
            case 'f':
            case 'F':
                *choice_c = 5;
                break;
            default:
                printf("Invalid column letter. Please enter a valid column letter (A-F).\n");
                break;
        }
    } while (*choice_c < 0 || *choice_c >= BOARD_SIZE);
}

// Define a function to check whether the game is over
int check_game_over(Board *board) {
    // Loop through each card on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // If any card is still face-down, the game is not over
            if (!board->cards[i][j].is_face_up) {
                return 0;
            }
        }
    }
    // If all cards are face-up, the game is over
    return 1;
}

int main() {
    printf("Welcome to the Sherlock Holmes Memory Game!\n");
    printf("You are Sherlock Holmes, and you must use your memory to solve the case.\n");
    printf("On the board, you will see pairs of cards with letters on them.\n");
    printf("You must flip over cards to find matching pairs and clear the board to solve the case.\n");
    printf("Good luck!\n\n");

    // Define a new game board
    Board board;
    init_board(&board);

    int choice1_r, choice1_c, choice2_r, choice2_c;

    // Loop until the game is over
    while (!check_game_over(&board)) {
        // Print the current state of the board
        print_board(&board);

        // Get the user's first card choice
        get_card_choice(&board, &choice1_r, &choice1_c);

        // Flip over the first card
        board.cards[choice1_r][choice1_c].is_face_up = 1;

        // Print the current state of the board
        print_board(&board);

        // Get the user's second card choice
        get_card_choice(&board, &choice2_r, &choice2_c);

        // Flip over the second card
        board.cards[choice2_r][choice2_c].is_face_up = 1;

        // Print the current state of the board
        print_board(&board);

        // Check if the card choices were a match
        if (board.cards[choice1_r][choice1_c].symbol == board.cards[choice2_r][choice2_c].symbol) {
            printf("You found a match!\n");
        }
        else {
            printf("Sorry, those cards don't match.\n");
            // Flip the cards back over
            board.cards[choice1_r][choice1_c].is_face_up = 0;
            board.cards[choice2_r][choice2_c].is_face_up = 0;
        }
    }

    // The game is over, so print the final board and a victory message
    print_board(&board);
    printf("Congratulations, Sherlock! You solved the case!\n");

    return 0;
}