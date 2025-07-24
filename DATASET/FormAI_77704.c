//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

// This struct represents a player
typedef struct {
    char name[100];
    char symbol;
    int position;
} Player;

// Global variables
Player players[2];
char board[3][3];
bool game_over = false;

// This function checks if a player has won
bool check_win(Player player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player.symbol &&
            board[i][1] == player.symbol &&
            board[i][2] == player.symbol) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player.symbol &&
            board[1][i] == player.symbol &&
            board[2][i] == player.symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player.symbol &&
        board[1][1] == player.symbol &&
        board[2][2] == player.symbol) {
        return true;
    }
    if (board[0][2] == player.symbol &&
        board[1][1] == player.symbol &&
        board[2][0] == player.symbol) {
        return true;
    }

    return false;
}

// This function prints the board
void print_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// This function handles a player's turn
void handle_turn(Player player) {
    int row, col;

    // Ask the player for their move
    printf("%s's turn (%c): ", player.name, player.symbol);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move, try again!\n");
        handle_turn(player);
        return;
    }

    // Update the board and check for a win
    board[row][col] = player.symbol;
    if (check_win(player)) {
        printf("%s has won!\n", player.name);
        game_over = true;
        return;
    }

    // Check for a tie
    bool tie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                tie = false;
                break;
            }
        }
        if (!tie) {
            break;
        }
    }
    if (tie) {
        printf("It's a tie!\n");
        game_over = true;
        return;
    }

    // Notify the other player
    printf("Waiting for the other player...\n");
}

// This function is the thread function for a player
void *player_thread(void *player_ptr) {
    Player *player = (Player *) player_ptr;

    while (!game_over) {
        // Lock the board for the player
        printf("%s is waiting to make a move...\n", player->name);

        // Handle the player's turn
        handle_turn(*player);

        // Unlock the board for the other player
    }

    return NULL;
}

// This function starts the game
void start_game() {
    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    // Set up the players
    Player player1 = {"Player 1", 'X', 1};
    Player player2 = {"Player 2", 'O', 2};
    players[0] = player1;
    players[1] = player2;

    // Create the threads for the players
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, player_thread, (void *) &player1);
    pthread_create(&threads[1], NULL, player_thread, (void *) &player2);

    // Wait for the threads to finish
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    // Print the final board
    print_board();
}

// This is the main function
int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("=======================\n");
    printf("To make a move, enter the row (0-2) and column (0-2) separated by a space.\n");
    printf("Let's start the game...\n");

    start_game();

    return 0;
}