//FormAI DATASET v1.0 Category: Chess AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

bool is_valid_move(int row, int col, char player) {
    if (board[row][col] != ' ') {
        return false;
    }
    
    int r, c;
    bool valid = false;
    
    // Check for valid moves in down direction
    r = row + 1;
    while (r < BOARD_SIZE && !valid) {
        if (board[r][col] == player) {
            valid = true;
        }
        else if (board[r][col] == ' ') {
            break;
        }
        
        r++;
    }
    
    // Check for valid moves in up direction
    r = row - 1;
    while (r >= 0 && !valid) {
        if (board[r][col] == player) {
            valid = true;
        }
        else if (board[r][col] == ' ') {
            break;
        }
        
        r--;
    }
    
    // Check for valid moves in right direction
    c = col + 1;
    while (c < BOARD_SIZE && !valid) {
        if (board[row][c] == player) {
            valid = true;
        }
        else if (board[row][c] == ' ') {
            break;
        }
        
        c++;
    }
    
    // Check for valid moves in left direction
    c = col - 1;
    while (c >= 0 && !valid) {
        if (board[row][c] == player) {
            valid = true;
        }
        else if (board[row][c] == ' ') {
            break;
        }
        
        c--;
    }
    
    // Check for valid moves in down-right direction
    r = row + 1;
    c = col + 1;
    while (r < BOARD_SIZE && c < BOARD_SIZE && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r++;
        c++;
    }
    
    // Check for valid moves in down-left direction
    r = row + 1;
    c = col - 1;
    while (r < BOARD_SIZE && c >= 0 && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r++;
        c--;
    }
    
    // Check for valid moves in up-right direction
    r = row - 1;
    c = col + 1;
    while (r >= 0 && c < BOARD_SIZE && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r--;
        c++;
    }
    
    // Check for valid moves in up-left direction
    r = row - 1;
    c = col - 1;
    while (r >= 0 && c >= 0 && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r--;
        c--;
    }
    
    return valid;
}

int count_valid_moves(char player) {
    int count = 0;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (is_valid_move(i, j, player)) {
                count++;
            }
        }
    }
    
    return count;
}

void make_move(int row, int col, char player) {
    board[row][col] = player;
    
    int r, c;
    bool valid;
    
    // Flip pieces in down direction
    r = row + 1;
    valid = false;
    while (r < BOARD_SIZE && !valid) {
        if (board[r][col] == player) {
            valid = true;
        }
        else if (board[r][col] == ' ') {
            break;
        }
        
        r++;
    }
    
    if (valid && r > row + 1) {
        for (int i = row + 1; i < r; i++) {
            board[i][col] = player;
        }
    }
    
    // Flip pieces in up direction
    r = row - 1;
    valid = false;
    while (r >= 0 && !valid) {
        if (board[r][col] == player) {
            valid = true;
        }
        else if (board[r][col] == ' ') {
            break;
        }
        
        r--;
    }
    
    if (valid && r < row - 1) {
        for (int i = row - 1; i > r; i--) {
            board[i][col] = player;
        }
    }
    
    // Flip pieces in right direction
    c = col + 1;
    valid = false;
    while (c < BOARD_SIZE && !valid) {
        if (board[row][c] == player) {
            valid = true;
        }
        else if (board[row][c] == ' ') {
            break;
        }
        
        c++;
    }
    
    if (valid && c > col + 1) {
        for (int i = col + 1; i < c; i++) {
            board[row][i] = player;
        }
    }
    
    // Flip pieces in left direction
    c = col - 1;
    valid = false;
    while (c >= 0 && !valid) {
        if (board[row][c] == player) {
            valid = true;
        }
        else if (board[row][c] == ' ') {
            break;
        }
        
        c--;
    }
    
    if (valid && c < col - 1) {
        for (int i = col - 1; i > c; i--) {
            board[row][i] = player;
        }
    }
    
    // Flip pieces in down-right direction
    r = row + 1;
    c = col + 1;
    valid = false;
    while (r < BOARD_SIZE && c < BOARD_SIZE && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r++;
        c++;
    }
    
    if (valid && r > row + 1 && c > col + 1) {
        for (int i = row + 1, j = col + 1; i < r && j < c; i++, j++) {
            board[i][j] = player;
        }
    }
    
    // Flip pieces in down-left direction
    r = row + 1;
    c = col - 1;
    valid = false;
    while (r < BOARD_SIZE && c >= 0 && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r++;
        c--;
    }
    
    if (valid && r > row + 1 && c < col - 1) {
        for (int i = row + 1, j = col - 1; i < r && j > c; i++, j--) {
            board[i][j] = player;
        }
    }
    
    // Flip pieces in up-right direction
    r = row - 1;
    c = col + 1;
    valid = false;
    while (r >= 0 && c < BOARD_SIZE && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r--;
        c++;
    }
    
    if (valid && r < row - 1 && c > col + 1) {
        for (int i = row - 1, j = col + 1; i > r && j < c; i--, j++) {
            board[i][j] = player;
        }
    }
    
    // Flip pieces in up-left direction
    r = row - 1;
    c = col - 1;
    valid = false;
    while (r >= 0 && c >= 0 && !valid) {
        if (board[r][c] == player) {
            valid = true;
        }
        else if (board[r][c] == ' ') {
            break;
        }
        
        r--;
        c--;
    }
    
    if (valid && r < row - 1 && c < col - 1) {
        for (int i = row - 1, j = col - 1; i > r && j > c; i--, j--) {
            board[i][j] = player;
        }
    }
}

void print_board() {
    printf("  ");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    
    printf("\n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
        
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        
        printf("\n");
    }
}

char get_winner() {
    int count_x = 0;
    int count_o = 0;
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'X') {
                count_x++;
            }
            else if (board[i][j] == 'O') {
                count_o++;
            }
        }
    }
    
    if (count_x > count_o) {
        return 'X';
    }
    else if (count_o > count_x) {
        return 'O';
    }
    else {
        return ' ';
    }
}

void play_game(char player) {
    int row, col;
    
    if (count_valid_moves(player) == 0) {
        return;
    }
    
    printf("Player %c's turn.\n", player);
    
    print_board();
    
    printf("Enter row and column (e.g. b3): ");
    scanf(" %c%d", &col, &row);
    fflush(stdin);
    
    row--;
    col -= 'a';
    
    if (!is_valid_move(row, col, player)) {
        printf("Invalid move. Try again.\n");
        play_game(player);
        return;
    }
    
    make_move(row, col, player);
    
    if (player == 'X') {
        play_game('O');
    }
    else {
        play_game('X');
    }
}

int main() {
    // Initialize board to all blank spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Set initial pieces
    board[3][3] = 'X';
    board[4][4] = 'X';
    board[3][4] = 'O';
    board[4][3] = 'O';
    
    play_game('X');
    
    printf("Game over!\n");
    print_board();
    
    char winner = get_winner();
    
    if (winner == ' ') {
        printf("It's a tie!\n");
    }
    else {
        printf("Player %c wins!\n", winner);
    }
    
    return 0;
}