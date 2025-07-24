//FormAI DATASET v1.0 Category: Checkers Game ; Style: genious
#include <stdio.h>

enum player {
    PLAYER_1,
    PLAYER_2
};

int board[8][8] = {0};

void print_board() {
    printf("\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == PLAYER_1) {
                printf("X ");
            } else if (board[i][j] == PLAYER_2) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    enum player current_player = PLAYER_1;

    // Set up board with checkers
    for (int i=0; i<8; i+=2) {
        board[0][i+1] = PLAYER_2;
        board[1][i] = PLAYER_2;
        board[2][i+1] = PLAYER_2;

        board[5][i] = PLAYER_1;
        board[6][i+1] = PLAYER_1;
        board[7][i] = PLAYER_1;
    }

    while (1) {
        print_board();

        // Check for game over
        int remaining_p1 = 0;
        int remaining_p2 = 0;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (board[i][j] == PLAYER_1) {
                    remaining_p1++;
                } else if (board[i][j] == PLAYER_2) {
                    remaining_p2++;
                }
            }
        }
        if (remaining_p1 == 0) {
            printf("Player 2 wins!\n");
            break;
        } else if (remaining_p2 == 0) {
            printf("Player 1 wins!\n");
            break;
        }

        // Get move from user
        int x1, y1, x2, y2;
        printf("Enter your move (%s): ", current_player == PLAYER_1 ? "X" : "O");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Check if move is valid
        if (board[x1][y1] != current_player || board[x2][y2] != 0) {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Check if move is a jump
        if (x1 - x2 == 2 || x2 - x1 == 2) {
            int mid_x = (x1 + x2)/2;
            int mid_y = (y1 + y2)/2;
            if (board[mid_x][mid_y] != (current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1)) {
                printf("Invalid move, try again.\n");
                continue;
            }
            // Remove jumped checker
            board[mid_x][mid_y] = 0;
        }

        // Make move
        board[x1][y1] = 0;
        board[x2][y2] = current_player;

        // Switch player
        current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
    }

    return 0;
}