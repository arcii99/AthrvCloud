//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>

#define ROWS 10
#define COLS 10
#define MAX_ATTEMPTS 25

char board[ROWS][COLS];
char player_board[ROWS][COLS];
bool game_over = false;
int attempts = 0;
int ship_count = 3;
pid_t pid;

// Function to randomly place ships on the game board
void place_ships() {
    srand(time(NULL));
    int ships_placed = 0;
    
    while (ships_placed < ship_count) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        
        if (board[row][col] != 'S') {
            board[row][col] = 'S';
            ships_placed++;
        }
    }
}

// Function to print the game board for the player to see
void print_board() {
    printf("\n");
    printf("  ");

    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c);
    }

    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);

        for (int j = 0; j < COLS; j++) {
            if (player_board[i][j] == 'O' || player_board[i][j] == 'X') {
                printf("%c ", player_board[i][j]);
            } else {
                printf("~ ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

// Function to check if the player hit a ship
bool check_ship_hit(int row, int col) {
    if (board[row][col] == 'S') {
        board[row][col] = 'X';
        return true;
    } else {
        return false;
    }
}

// Function to check if the game is over
bool check_game_over() {
    if (ship_count == 0) {
        return true;
    } else if (attempts >= MAX_ATTEMPTS) {
        return true;
    } else {
        return false;
    }
}

// Function to handle the player's guess
void handle_guess(char* guess) {
    if (isdigit(guess[1])) {
        int row = atoi(&guess[1]) - 1;
        int col = guess[0] - 'A';

        if (check_ship_hit(row, col)) {
            player_board[row][col] = 'X';
            ship_count--;
            printf("HIT!\n");
        } else {
            player_board[row][col] = 'O';
            printf("MISS!\n");
        }

        attempts++;

        if (check_game_over()) {
            game_over = true;
        }
    } else {
        printf("Invalid input. Guess again.\n");    
    }
}

// Function to read the player's input
void read_input() {
    char guess[3];

    while (!game_over) {
        printf("Enter your guess (e.g. A1): ");
        scanf("%s", guess);
        handle_guess(guess);
        print_board();
    }
}

// Function to print end game message and exit process
void end_game() {
    printf("You win!\n");
    exit(0);
}

// Function to start the AI player
void start_ai() {
    while (!game_over) {
        int row = rand() % ROWS;
        int col = rand() % COLS;

        if (check_ship_hit(row, col)) {
            printf("AI guessed: %c%d - HIT!\n", col + 'A', row + 1);
            attempts++;

            if (check_game_over()) {
                printf("AI has won!\n");
                exit(0);
            }
        }
    }
}

// Main function to start the game
int main() {
    // Initialize board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
            player_board[i][j] = '.';
        }
    }

    place_ships();
    print_board();

    // Fork child process to start AI player
    pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(1);
    } else if (pid == 0) {
        start_ai();
    } else {
        // Parent reads player input
        read_input();
        end_game();
    }

    return 0;
}