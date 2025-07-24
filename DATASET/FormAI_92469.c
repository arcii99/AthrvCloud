//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define AI_PLAYER 1
#define HUMAN_PLAYER -1
#define EMPTY 0

int board[BOARD_SIZE][BOARD_SIZE]; // The tic tac toe board

// Returns 1 if the specified player has won the game
int check_winner(int player)
{
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        int count = 0;
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        int count = 0;
        for (int row = 0; row < BOARD_SIZE; row++) {
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonal
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == player) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    // Check reverse diagonal
    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - 1 - i] == player) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    return 0;
}

// Returns a random number between min and max
int random_number(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

// Returns the best move for the AI player using the Monte Carlo method
int get_best_move()
{
    int win_count[BOARD_SIZE][BOARD_SIZE] = {0}; // The number of wins for each possible move
    int total_count[BOARD_SIZE][BOARD_SIZE] = {0}; // The total number of simulations for each possible move
    int simulations = 10000; // The number of simulations to run for each move

    // Simulate all possible moves and count the number of wins for each move
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] != EMPTY) { // Square is occupied
                continue;
            }

            for (int i = 0; i < simulations; i++) {
                int temp_board[BOARD_SIZE][BOARD_SIZE];
                for (int row2 = 0; row2 < BOARD_SIZE; row2++) {
                    for (int col2 = 0; col2 < BOARD_SIZE; col2++) {
                        temp_board[row2][col2] = board[row2][col2];
                    }
                }

                temp_board[row][col] = AI_PLAYER; // Make the move

                // Simulate the game until the end
                while (1) {
                    // Check for a winner or a tie
                    if (check_winner(HUMAN_PLAYER)) {
                        win_count[row][col]++;
                        total_count[row][col]++;
                        break;
                    } else if (check_winner(AI_PLAYER)) {
                        total_count[row][col]++;
                        break;
                    } else if (total_count[row][col] == simulations) {
                        break;
                    }

                    // Randomly make a move for the human player
                    int empty_squares[BOARD_SIZE * BOARD_SIZE];
                    int num_empty_squares = 0;
                    for (int row2 = 0; row2 < BOARD_SIZE; row2++) {
                        for (int col2 = 0; col2 < BOARD_SIZE; col2++) {
                            if (temp_board[row2][col2] == EMPTY) {
                                empty_squares[num_empty_squares] = row2 * BOARD_SIZE + col2;
                                num_empty_squares++;
                            }
                        }
                    }
                    if (num_empty_squares == 0) {
                        break;
                    }
                    int random_index = random_number(0, num_empty_squares - 1);
                    int random_square = empty_squares[random_index];
                    int row2 = random_square / BOARD_SIZE;
                    int col2 = random_square % BOARD_SIZE;
                    temp_board[row2][col2] = HUMAN_PLAYER;

                    // Check for a winner or a tie
                    if (check_winner(HUMAN_PLAYER)) {
                        win_count[row][col]++;
                        total_count[row][col]++;
                        break;
                    } else if (check_winner(AI_PLAYER)) {
                        total_count[row][col]++;
                        break;
                    } else if (total_count[row][col] == simulations) {
                        break;
                    }
                }
            }
        }
    }

    // Find the move with the highest win rate
    int best_row = 0;
    int best_col = 0;
    float highest_win_rate = -1.0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] != EMPTY) {
                continue;
            }

            float win_rate = (float)win_count[row][col] / total_count[row][col];
            if (win_rate > highest_win_rate) {
                best_row = row;
                best_col = col;
                highest_win_rate = win_rate;
            }
        }
    }

    return best_row * BOARD_SIZE + best_col;
}

// Prints the tic tac toe board
void print_board()
{
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == AI_PLAYER) {
                printf("X ");
            } else if (board[row][col] == HUMAN_PLAYER) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the board with empty squares
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY;
        }
    }

    while (1) {
        // AI player's turn
        int move = get_best_move();
        int row = move / BOARD_SIZE;
        int col = move % BOARD_SIZE;
        board[row][col] = AI_PLAYER;
        printf("AI player made a move: %d, %d\n", row, col);
        print_board();

        // Check for a winner or a tie
        if (check_winner(AI_PLAYER)) {
            printf("AI player won!\n");
            break;
        } else if (check_winner(HUMAN_PLAYER)) {
            printf("Human player won!\n");
            break;
        } else {
            int empty_squares[BOARD_SIZE * BOARD_SIZE];
            int num_empty_squares = 0;
            for (int row = 0; row < BOARD_SIZE; row++) {
                for (int col = 0; col < BOARD_SIZE; col++) {
                    if (board[row][col] == EMPTY) {
                        empty_squares[num_empty_squares] = row * BOARD_SIZE + col;
                        num_empty_squares++;
                    }
                }
            }
            if (num_empty_squares == 0) {
                printf("Tie!\n");
                break;
            }
        }

        // Human player's turn
        printf("Enter your move (row,column): ");
        int human_row, human_col;
        scanf("%d,%d", &human_row, &human_col);
        if (human_row < 0 || human_row >= BOARD_SIZE || human_col < 0 ||
            human_col >= BOARD_SIZE || board[human_row][human_col] != EMPTY) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[human_row][human_col] = HUMAN_PLAYER;
        printf("You made a move: %d, %d\n", human_row, human_col);
        print_board();

        // Check for a winner or a tie
        if (check_winner(AI_PLAYER)) {
            printf("AI player won!\n");
            break;
        } else if (check_winner(HUMAN_PLAYER)) {
            printf("Human player won!\n");
            break;
        } else {
            int empty_squares[BOARD_SIZE * BOARD_SIZE];
            int num_empty_squares = 0;
            for (int row = 0; row < BOARD_SIZE; row++) {
                for (int col = 0; col < BOARD_SIZE; col++) {
                    if (board[row][col] == EMPTY) {
                        empty_squares[num_empty_squares] = row * BOARD_SIZE + col;
                        num_empty_squares++;
                    }
                }
            }
            if (num_empty_squares == 0) {
                printf("Tie!\n");
                break;
            }
        }
    }

    return 0;
}