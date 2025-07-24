//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
char human_symbol, ai_symbol;
int human_score = 0, ai_score = 0, tie_score = 0;

// Function that prints the board
void print_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function that prompts the user to choose their symbol
void choose_symbol() {
    printf("Do you want to play with 'X' or 'O'? ");
    scanf(" %c", &human_symbol);

    // Check if the input is valid
    while (human_symbol != 'X' && human_symbol != 'O') {
        printf("Invalid input. Please choose 'X' or 'O': ");
        scanf(" %c", &human_symbol);
    }

    // Set AI symbol
    if (human_symbol == 'X') {
        ai_symbol = 'O';
    } else {
        ai_symbol = 'X';
    }
}

// Function that checks if a move is valid
int is_valid_move(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function that checks if someone has won
int has_won(char symbol) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }

    if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol) {
        return 1;
    }

    return 0;
}

// Function that checks if the game is over
int is_game_over() {
    int i, j;

    // Check if the board is full
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

// Function that gets the score of a move
int get_score(int row, int col, char symbol) {
    int score = 0;

    // Set the symbol temporarily
    board[row][col] = symbol;

    // If the move wins the game, return maximum score
    if (has_won(symbol)) {
        score = 100;
    }

    // If the move doesn't win the game, try all possible moves for the other player
    else {
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    int temp_score;
                    if (symbol == human_symbol) {
                        temp_score = get_score(i, j, ai_symbol);
                    } else {
                        temp_score = get_score(i, j, human_symbol);
                    }

                    // If the other player wins, subtract their score
                    if (temp_score == 100) {
                        temp_score = -100;
                    }

                    score += temp_score;
                }
            }
        }
    }

    // Reset the symbol
    board[row][col] = ' ';

    return score;
}

// Function that gets the best move for the AI
void get_best_move(int *row, int *col) {
    int max_score = -1000;
    int i, j;

    // Try all possible moves
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                int score = get_score(i, j, ai_symbol);
                if (score > max_score) {
                    max_score = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

// Function that simulates the AI's turn
void ai_move() {
    int row, col;

    // Get the best move
    get_best_move(&row, &col);

    // Make the move
    board[row][col] = ai_symbol;
    printf("AI plays %c at row %d and column %d\n", ai_symbol, row+1, col+1);
}

// Function that simulates the human's turn
void human_move() {
    int row, col;

    // Prompt the user to make a move
    printf("Enter the row (1-3) and column (1-3) of your move: ");
    scanf("%d %d", &row, &col);

    // Adjust for 0-based indexing
    row--;
    col--;

    // Check if the move is valid
    while (!is_valid_move(row, col)) {
        printf("Invalid move. Please enter a valid row (1-3) and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
    }

    // Make the move
    board[row][col] = human_symbol;
}

// Function that simulates a game
void play_game() {
    int turn = 1;

    // Clear the board
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    // Choose symbols and who goes first
    choose_symbol();
    printf("Do you want to go first? (y/n) ");
    char first;
    scanf(" %c", &first);

    // Check if the input is valid
    while (first != 'y' && first != 'n') {
        printf("Invalid input. Please choose 'y' or 'n': ");
        scanf(" %c", &first);
    }

    // Play the game
    if (first == 'y') {
        // Human goes first
        while (!is_game_over()) {
            printf("-------- Turn %d --------\n", turn);
            print_board();
            human_move();
            turn++;

            if (has_won(human_symbol)) {
                printf("-------- Game over! --------\n");
                printf("You won!\n");
                human_score++;
                return;
            }

            if (is_game_over()) {
                printf("-------- Game over! --------\n");
                printf("It's a tie.\n");
                tie_score++;
                return;
            }

            ai_move();

            if (has_won(ai_symbol)) {
                printf("-------- Game over! --------\n");
                printf("You lost!\n");
                ai_score++;
                return;
            }

            turn++;
        }
    } else {
        // AI goes first
        while (!is_game_over()) {
            printf("-------- Turn %d --------\n", turn);
            ai_move();
            turn++;

            if (has_won(ai_symbol)) {
                printf("-------- Game over! --------\n");
                printf("You lost!\n");
                ai_score++;
                return;
            }

            if (is_game_over()) {
                printf("-------- Game over! --------\n");
                printf("It's a tie.\n");
                tie_score++;
                return;
            }

            printf("\n");
            print_board();
            human_move();

            if (has_won(human_symbol)) {
                printf("-------- Game over! --------\n");
                printf("You won!\n");
                human_score++;
                return;
            }

            turn++;
        }
    }
}

// Function that simulates multiple games
void simulate_games(int num_games) {
    int i;

    for (i = 0; i < num_games; i++) {
        printf("Game %d\n", i+1);
        play_game();
    }

    printf("\n---------- Simulation Results ----------\n");
    printf("Human: %d\n", human_score);
    printf("AI: %d\n", ai_score);
    printf("Tie: %d\n", tie_score);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Simulate multiple games
    simulate_games(10);

    return 0;
}