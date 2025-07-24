//FormAI DATASET v1.0 Category: Checkers Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int board[8][8] = {
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}
};

int player_turn = 1;
int player_piece_count = 12;
int computer_piece_count = 12;

void display_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int valid_move(int start_x, int start_y, int end_x, int end_y) {
    // Out of bounds check
    if (start_x < 0 || start_x >= 8 || start_y < 0 || start_y >= 8 ||
        end_x < 0 || end_x >= 8 || end_y < 0 || end_y >= 8) {
        return 0;
    }
    
    // Piece can't move to empty space
    if (board[end_x][end_y] != 0) {
        return 0;
    }
    
    // Piece can't move backwards
    if (player_turn == 1 && end_x > start_x) {
        return 0;
    }
    if (player_turn == -1 && end_x < start_x) {
        return 0;
    }
    
    // Destination must be diagonal
    if (abs(start_x - end_x) != 1 || abs(start_y - end_y) != 1) {
        return 0;
    }
    
    // Check for capturing move
    if (abs(start_x - end_x) == 2 && abs(start_y - end_y) == 2) {
        // Capturing only allowed for moves to top or bottom right/left diagonals
        int capture_x = (start_x + end_x) / 2;
        int capture_y = (start_y + end_y) / 2;
        if (board[capture_x][capture_y] != -player_turn) {
            return 0;
        }
    }
    
    return 1;
}

void make_move(int start_x, int start_y, int end_x, int end_y) {
    // Make the move on the board
    board[end_x][end_y] = board[start_x][start_y];
    board[start_x][start_y] = 0;
    
    // Check if it was a capturing move and remove the captured piece
    if (abs(start_x - end_x) == 2 && abs(start_y - end_y) == 2) {
        int capture_x = (start_x + end_x) / 2;
        int capture_y = (start_y + end_y) / 2;
        board[capture_x][capture_y] = 0;
        if (player_turn == 1) {
            computer_piece_count--;
        } else {
            player_piece_count--;
        }
    }
}

int game_over() {
    if (player_piece_count == 0) {
        return -1;
    }
    if (computer_piece_count == 0) {
        return 1;
    }
    return 0;
}

void computer_move() {
    // Find a computer piece to move
    int found_piece = 0;
    int piece_x = 0;
    int piece_y = 0;
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == -1) {
                if (valid_move(i, j, i+1, j+1)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i+1, j-1)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i+2, j+2)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i+2, j-2)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                }
            } else if (board[i][j] == -2) {
                if (valid_move(i, j, i+1, j+1)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i+1, j-1)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i-1, j+1)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i-1, j-1)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i+2, j+2)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i+2, j-2)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i-2, j+2)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                } else if (valid_move(i, j, i-2, j-2)) {
                    found_piece = 1;
                    piece_x = i;
                    piece_y = j;
                    break;
                }
            }
        }
        if (found_piece) {
            break;
        }
    }
    
    // Move the selected piece
    make_move(piece_x, piece_y, piece_x+1, piece_y-1);
    
    // Check for game over
    int game_over_result = game_over();
    if (game_over_result != 0) {
        printf("Game over!\n");
        if (game_over_result == 1) {
            printf("Computer wins!\n");
        } else {
            printf("Player wins!\n");
        }
    }
}

int main(void) {
    // Loop until game is over
    while (1) {
        // Display the board
        display_board();
        
        // Prompt player for move
        printf("Enter move for player %d (from_x from_y to_x to_y):\n", player_turn);
        int from_x, from_y, to_x, to_y;
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        if (!valid_move(from_x, from_y, to_x, to_y)) {
            printf("Invalid move!\n");
            continue;
        }
        make_move(from_x, from_y, to_x, to_y);
        if (player_turn == 1) {
            player_piece_count--;
        } else {
            computer_piece_count--;
        }
        
        // Check for game over
        int game_over_result = game_over();
        if (game_over_result != 0) {
            printf("Game over!\n");
            if (game_over_result == 1) {
                printf("Player wins!\n");
            } else {
                printf("Computer wins!\n");
            }
            break;
        }
        
        // Switch turns
        player_turn = -player_turn;
        
        // Computer move
        computer_move();
    }
    return 0;
}