//FormAI DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define MAX_MOVES GRID_SIZE * GRID_SIZE * 3

// Define a struct to hold the game board
typedef struct {
    int x, y;
    char symbol;
    int is_hidden;
} card;

// function prototypes
void init_cards(card cards[GRID_SIZE][GRID_SIZE]);
void print_board(card cards[GRID_SIZE][GRID_SIZE]);
int choose_card(card cards[GRID_SIZE][GRID_SIZE]);
void reveal_card(card* selected_card);
void hide_card(card* selected_card);
void check_match(card cards[GRID_SIZE][GRID_SIZE], int x1, int y1, int x2, int y2);
int check_for_win(card cards[GRID_SIZE][GRID_SIZE]);

int main() {
    // seed the random number generator
    srand(time(0));
    
    // Initialize the game board with cards
    card cards[GRID_SIZE][GRID_SIZE];
    init_cards(cards);
    
    // Initialize game variables
    int moves = 0;
    int x1, y1, x2, y2;
    
    // Display the game board
    print_board(cards);
    
    // Main game loop
    while (moves < MAX_MOVES) {
        // Allow the player to choose two cards
        printf("Choose two cards to flip over (x1, y1, x2, y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        // Check if the cards match
        check_match(cards, x1, y1, x2, y2);
        
        // Display the game board
        print_board(cards);
        
        // Check if the player has won
        if (check_for_win(cards)) {
            printf("Congratulations! You won in %d moves.\n", moves);
            break;
        }
        
        moves++;
    }
    
    // If we get to this point, the player has lost
    printf("Sorry, you have run out of moves. Game over.\n");
    
    return 0;
}

// Initialize the game board with cards
void init_cards(card cards[GRID_SIZE][GRID_SIZE]) {
    char symbols[GRID_SIZE * GRID_SIZE / 2] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    };
    
    // Initialize each card with a symbol and set is_hidden to true
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        card* current_card = &(cards[i / GRID_SIZE][i % GRID_SIZE]);
        current_card->symbol = symbols[i / 2];
        current_card->is_hidden = 1;
    }
    
    // Shuffle the cards by randomly swapping them
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        int j = rand() % (GRID_SIZE * GRID_SIZE);
        int temp_x = cards[i / GRID_SIZE][i % GRID_SIZE].x;
        int temp_y = cards[i / GRID_SIZE][i % GRID_SIZE].y;
        cards[i / GRID_SIZE][i % GRID_SIZE].x = cards[j / GRID_SIZE][j % GRID_SIZE].x;
        cards[i / GRID_SIZE][i % GRID_SIZE].y = cards[j / GRID_SIZE][j % GRID_SIZE].y;
        cards[j / GRID_SIZE][j % GRID_SIZE].x = temp_x;
        cards[j / GRID_SIZE][j % GRID_SIZE].y = temp_y;
    }
}

// Print the game board
void print_board(card cards[GRID_SIZE][GRID_SIZE]) {
    printf("  ");
    for (int x = 0; x < GRID_SIZE; x++) {
        printf("%d ", x);
    }
    printf("\n");
    
    for (int y = 0; y < GRID_SIZE; y++) {
        printf("%d ", y);
        for (int x = 0; x < GRID_SIZE; x++) {
            card current_card = cards[x][y];
            if (current_card.is_hidden) {
                printf("_ ");
            } else {
                printf("%c ", current_card.symbol);
            }
        }
        printf("\n");
    }
}

// Allow the player to choose a card and return the index of the chosen card
int choose_card(card cards[GRID_SIZE][GRID_SIZE]) {
    int choice_x, choice_y;
    do {
        printf("Choose a card (x, y): ");
        scanf("%d %d", &choice_x, &choice_y);
    } while (!cards[choice_x][choice_y].is_hidden);
    
    return choice_x + choice_y * GRID_SIZE;
}

// Reveal a selected card
void reveal_card(card* selected_card) {
    selected_card->is_hidden = 0;
}

// Hide a selected card
void hide_card(card* selected_card) {
    selected_card->is_hidden = 1;
}

// Check if two cards match and hide them if they do not match
void check_match(card cards[GRID_SIZE][GRID_SIZE], int x1, int y1, int x2, int y2) {
    card* card1 = &cards[x1][y1];
    card* card2 = &cards[x2][y2];
    
    if (card1->symbol == card2->symbol) {
        printf("Match found!\n");
    } else {
        printf("Sorry, not a match.\n");
        hide_card(card1);
        hide_card(card2);
    }
}

// Check if the player has won
int check_for_win(card cards[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        if (cards[i / GRID_SIZE][i % GRID_SIZE].is_hidden) {
            return 0;
        }
    }
    return 1;
}