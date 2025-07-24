//FormAI DATASET v1.0 Category: Chess engine ; Style: irregular
#include <stdio.h>

// Global constants
#define BOARD_SIZE 8

// Function prototypes
void setup_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
int count_pieces(char board[][BOARD_SIZE], char piece);
void play_chess(char board[][BOARD_SIZE], char player);

int main() {
    // Initialize the chess board
    char board[BOARD_SIZE][BOARD_SIZE];
    setup_board(board);

    // Start playing the game
    char player = 'W';
    play_chess(board, player);

    return 0;
}

void setup_board(char board[][BOARD_SIZE]) {
    // Set up the initial pieces on the board
    board[0][0] = 'B';
    board[0][1] = 'N';
    board[0][2] = 'R';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'R';
    board[0][6] = 'N';
    board[0][7] = 'B';

    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P';
        board[6][i] = 'P';
    }

    board[7][0] = 'b';
    board[7][1] = 'n';
    board[7][2] = 'r';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'r';
    board[7][6] = 'n';
    board[7][7] = 'b';

    // Set the remaining cells empty
    for (int row = 2; row < BOARD_SIZE-2; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = ' ';
        }
    }
}

void print_board(char board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int count_pieces(char board[][BOARD_SIZE], char piece) {
    int count = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == piece) {
                count++;
            }
        }
    }
    return count;
}

void play_chess(char board[][BOARD_SIZE], char player) {
    int turn = 1;
    while (1) {
        printf("Turn %d: Player %c\n", turn, player);
        print_board(board);

        // Check if any player has lost all their pieces
        if (count_pieces(board, 'P') == 0 || count_pieces(board, 'p') == 0) {
            printf("Game over! Player %c wins!\n", player == 'W' ? 'B' : 'W');
            break;
        }

        char move[5];
        printf("Enter your move (e.g. a2-a3): ");
        scanf("%s", move);

        int from_row = move[1] - '1';
        int from_col = move[0] - 'a';
        int to_row = move[4] - '1';
        int to_col = move[3] - 'a';

        // Check if the move is valid
        if (from_row < 0 || from_row >= BOARD_SIZE || from_col < 0 || from_col >= BOARD_SIZE ||
            to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (board[from_row][from_col] == ' ') {
            printf("No piece at the specified location! Try again.\n");
            continue;
        }

        if ((player == 'W' && board[from_row][from_col] >= 'a' && board[from_row][from_col] <= 'z') ||
            (player == 'B' && board[from_row][from_col] >= 'A' && board[from_row][from_col] <= 'Z')) {
            printf("Invalid move! Cannot move opponent's pieces. Try again.\n");
            continue;
        }

        // Update the chess board
        board[to_row][to_col] = board[from_row][from_col];
        board[from_row][from_col] = ' ';

        // Switch to the other player's turn
        player = player == 'W' ? 'B' : 'W';
        turn++;
    }
}