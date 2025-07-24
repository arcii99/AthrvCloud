//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_CHAR '-'

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int row, col;
    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY_CHAR;
        }
    }
}

void print_board() {
    int row, col;
    printf("\n");
    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            printf(" %c", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_score(char player, int depth) {
    int score = 0;
    int row, col;
    int player_count, opponent_count;

    // Check rows
    for(row = 0; row < BOARD_SIZE; row++) {
        player_count = 0;
        opponent_count = 0;
        for(col = 0; col < BOARD_SIZE; col++) {
            if(board[row][col] == player)
                player_count++;
            else if(board[row][col] == (player == PLAYER_X ? PLAYER_O : PLAYER_X))
                opponent_count++;
        }
        if(player_count == BOARD_SIZE)
            return 10 - depth;
        if(opponent_count == BOARD_SIZE)
            return depth - 10;
    }

    // Check columns
    for(col = 0; col < BOARD_SIZE; col++) {
        player_count = 0;
        opponent_count = 0;
        for(row = 0; row < BOARD_SIZE; row++) {
            if(board[row][col] == player)
                player_count++;
            else if(board[row][col] == (player == PLAYER_X ? PLAYER_O : PLAYER_X))
                opponent_count++;
        }
        if(player_count == BOARD_SIZE)
            return 10 - depth;
        if(opponent_count == BOARD_SIZE)
            return depth - 10;
    }

    // Check main diagonal
    player_count = 0;
    opponent_count = 0;
    for(row = 0; row < BOARD_SIZE; row++) {
        if(board[row][row] == player)
            player_count++;
        else if(board[row][row] == (player == PLAYER_X ? PLAYER_O : PLAYER_X))
            opponent_count++;
    }
    if(player_count == BOARD_SIZE)
        return 10 - depth;
    if(opponent_count == BOARD_SIZE)
        return depth - 10;

    // Check reverse diagonal
    player_count = 0;
    opponent_count = 0;
    for(row = 0; row < BOARD_SIZE; row++) {
        if(board[row][BOARD_SIZE - 1 - row] == player)
            player_count++;
        else if(board[row][BOARD_SIZE - 1 - row] == (player == PLAYER_X ? PLAYER_O : PLAYER_X))
            opponent_count++;
    }
    if(player_count == BOARD_SIZE)
        return 10 - depth;
    if(opponent_count == BOARD_SIZE)
        return depth - 10;

    return score;
}

int minimax(char player, int depth) {
    int row, col;
    int move_row, move_col;
    int best_score;
    int score;
    int best_row = -1;
    int best_col = -1;

    if(depth == 0) 
        return get_score(player, depth);

    if(player == PLAYER_X) {
        best_score = -1000;
        for(row = 0; row < BOARD_SIZE; row++) {
            for(col = 0; col < BOARD_SIZE; col++) {
                if(board[row][col] == EMPTY_CHAR) {
                    board[row][col] = PLAYER_X;
                    score = minimax(PLAYER_O, depth-1);
                    board[row][col] = EMPTY_CHAR;
                    if(score > best_score) {
                        best_score = score;
                        best_row = row;
                        best_col = col;
                    }
                }
            }
        }
    }
    else {
        best_score = 1000;
        for(row = 0; row < BOARD_SIZE; row++) {
            for(col = 0; col < BOARD_SIZE; col++) {
                if(board[row][col] == EMPTY_CHAR) {
                    board[row][col] = PLAYER_O;
                    score = minimax(PLAYER_X, depth-1);
                    board[row][col] = EMPTY_CHAR;
                    if(score < best_score) {
                        best_score = score;
                        best_row = row;
                        best_col = col;
                    }
                }
            }
        }
    }

    if(depth == 8) {
        board[best_row][best_col] = player;
    }

    return best_score;
}

int main() {
    initialize_board();
    print_board();

    int current_player = PLAYER_X;
    int moves_made = 0;

    while(1) {
        if(current_player == PLAYER_O) {
            minimax(PLAYER_O, 8);
            moves_made++;
        }
        else {
            int row, col;
            printf("Enter row and column to place a move for %c: ", current_player);
            scanf("%d %d", &row, &col);
            if(row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY_CHAR) {
                printf("Invalid move, try again.\n");
                continue;
            }
            board[row][col] = current_player;
            moves_made++;
        }

        print_board();

        int row, col;
        char winner = EMPTY_CHAR;

        // Check rows
        for(row = 0; row < BOARD_SIZE; row++) {
            if(board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                winner = board[row][0];
            }
        }

        // Check columns
        for(col = 0; col < BOARD_SIZE; col++) {
            if(board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                winner = board[0][col];
            }
        }

        // Check diagonals
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        }
        else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }

        if(winner != EMPTY_CHAR) {
            printf("Congratulations %c, you have won!\n", winner);
            return 0;
        }

        if(moves_made == BOARD_SIZE * BOARD_SIZE) {
            printf("It's a draw!\n");
            return 0;
        }

        current_player = current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
    }

    return 0;
}