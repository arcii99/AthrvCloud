//FormAI DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>

char board[8][8] = {
    {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
    {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
    {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'W', ' ', 'W', ' ', 'W', ' ', 'W'},
    {'W', ' ', 'W', ' ', 'W', ' ', 'W', ' '},
    {' ', 'W', ' ', 'W', ' ', 'W', ' ', 'W'}
};

void print_board() {
    printf("\n   1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < 8; j++) {
            printf("|%c", board[i][j]);
        }
        printf("| %d\n", i+1);
    }
    printf("   1 2 3 4 5 6 7 8\n\n");
}

void move_piece(int start_pos[], int end_pos[]) {
    int start_row = start_pos[0];
    int start_col = start_pos[1];
    int end_row = end_pos[0];
    int end_col = end_pos[1];
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
}

int main() {
    int game_over = 0;
    printf("Welcome to Happy Checkers Game!\n");
    printf("Player 1: B | Player 2: W\n");
    print_board();
    while(!game_over) {
        int current_player = 1;
        int valid_move = 0;
        int start_pos[2];
        int end_pos[2];
        while(!valid_move) {
            printf("Player %d's turn. Enter starting position (row col): ", current_player);
            scanf("%d %d", &start_pos[0], &start_pos[1]);
            printf("Enter ending position (row col): ");
            scanf("%d %d", &end_pos[0], &end_pos[1]);
            if(board[start_pos[0]-1][start_pos[1]-1] == 'B' && current_player == 1) {
                if(start_pos[0]-1 == end_pos[0] && (start_pos[1]-1 == end_pos[1]-1 || start_pos[1]-1 == end_pos[1]+1)) {
                    move_piece(start_pos, end_pos);
                    valid_move = 1;
                } else {
                    printf("Invalid move. Try again.\n");
                }
            } else if(board[start_pos[0]-1][start_pos[1]-1] == 'W' && current_player == 2) {
                if(start_pos[0]-1 == end_pos[0] && (start_pos[1]-1 == end_pos[1]-1 || start_pos[1]-1 == end_pos[1]+1)) {
                    move_piece(start_pos, end_pos);
                    valid_move = 1;
                } else {
                    printf("Invalid move. Try again.\n");
                }
            } else {
                printf("Invalid starting position. Try again.\n");
            }
        }
        print_board();
        if(current_player == 1) {
            current_player = 2;
        } else {
            current_player = 1;
        }
    }
    printf("Game over. Thanks for playing!\n");
    return 0;
}