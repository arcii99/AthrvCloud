//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[9]; // board configuration
int player = 1; // player's turn
int cpu = 2; // CPU's turn
int curr_player; // current player, set randomly
int winner; // winner of the game (if there's any)

/* Function to display the game board */
void display_board() {
    int i;
    for (i = 0; i < 9; i++) {
        if (i == 2 || i == 5) printf("\n-----------\n");
        printf(" %c ", board[i] == 0 ? '-' : (board[i] == 1 ? 'X' : 'O'));
        if (i != 2 && i != 5 && i != 8) printf("|");
    }
    printf("\n\n");
}

/* Function to check if the game is over */
int is_game_over() {
    int i;
    // Check rows
    for (i = 0; i <= 6; i += 3) {
        if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != 0) {
            winner = board[i];
            return 1;
        }
    }
    // Check columns
    for (i = 0; i <= 2; i++) {
        if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != 0) {
            winner = board[i];
            return 1;
        }
    }
    // Check diagonals
    if ((board[0] == board[4] && board[4] == board[8] && board[0] != 0) || 
        (board[2] == board[4] && board[4] == board[6] && board[2] != 0)) {
        winner = board[4];
        return 1;
    }
    // Check tie
    int count = 0;
    for (i = 0; i < 9; i++) {
        if (board[i] != 0) count++;
    }
    if (count == 9) {
        winner = 0;
        return 1;
    }
    return 0;
}

/* Function to get the CPU's move */
int get_cpu_move() {
    int i, j, cnt = 0;
    int available[9];
    // Look for winning move
    for (i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = cpu;
            if (is_game_over() == 1) {
                board[i] = 0;
                return i;
            }
            board[i] = 0;
        }
    }
    // Block player's winning move
    for (i = 0; i < 9; i++) {
        if (board[i] == 0) {
            board[i] = player;
            if (is_game_over() == 1) {
                board[i] = 0;
                return i;
            }
            board[i] = 0;
        }
    }
    // Random move
    for (i = 0; i < 9; i++) {
        if (board[i] == 0) {
            available[cnt++] = i;
        }
    }
    srand(time(NULL));
    int rand_idx = rand() % cnt;
    return available[rand_idx];
}

/* Function to start a new game */
void start_game() {
    printf("\n***** TIC TAC TOE *****\n\n");
    printf("Welcome to the game!\n\n");
    printf("You will play against the CPU,\n");

    // Randomly choose the starting player
    srand(time(NULL));
    curr_player = (rand() % 2) + 1;
    if (curr_player == 1) printf("You will start first.\n\n");
    else printf("The CPU will start first.\n\n");

    display_board();

    // While game is not over
    while (is_game_over() != 1) {
        if (curr_player == 1) {
            int move;
            printf("Enter your move (1-9): ");
            scanf("%d", &move);
            if (board[move-1] != 0) {
                printf("Invalid move. Try again.\n\n");
                continue;
            }
            board[move-1] = player;
            display_board();
            curr_player = 2;
        } else {
            printf("CPU's move:\n");
            int cpu_move = get_cpu_move();
            board[cpu_move] = cpu;
            display_board();
            curr_player = 1;
        }
    }
    // Game is over, display winner or tie
    if (winner == 1) printf("Congratulations! You win!\n");
    else if (winner == 2) printf("Sorry, you lose. Better luck next time!\n");
    else printf("It's a tie. Good game!\n");
}

int main() {
    int play_again = 1;
    while (play_again == 1) {
        // Reset game board and winner
        int i;
        for (i = 0; i < 9; i++) board[i] = 0;
        winner = -1;
        start_game();
        printf("Do you want to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &play_again);
        printf("\n");
    }
    return 0;
}