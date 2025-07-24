//FormAI DATASET v1.0 Category: Checkers Game ; Style: immersive
#include <stdio.h>

// Function to print the current state of the board
void print_board(char board[][8]) {
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  +----------------+\n");
    for(int i=0;i<8;i++) {
        printf("%c | ",('A'+i));
        for(int j=0;j<8;j++) {
            printf("%c ",board[i][j]);
        }
        printf("|\n");
    }
    printf("  +----------------+\n");
}

// Function to make a move on the board
void make_move(char board[][8], int start_x, int start_y, int end_x, int end_y) {
    char piece = board[start_x][start_y];
    board[start_x][start_y] = ' ';
    board[end_x][end_y] = piece;
}

// Function to check if the move is valid
int is_valid_move(char board[][8], int start_x, int start_y, int end_x, int end_y, char player) {
    if(end_x < 0 || end_x > 7 || end_y < 0 || end_y > 7) { // move out of board
        return 0;
    }
    if(board[end_x][end_y] != ' ') { // move to non-empty cell
        return 0;
    }
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    if(board[start_x][start_y] == 'b') { // black piece
        if(player == 'r' || dx <= 0) { // white player or invalid move direction
            return 0;
        }
        if(dx == 1 && (dy == 1 || dy == -1)) { // normal move
            return 1;
        }
        if(dx == 2 && (dy == 2 || dy == -2) && board[start_x+1][start_y+(dy/2)] == 'r') { // capturing move
            return 1;
        }
        return 0; // invalid move
    } else if(board[start_x][start_y] == 'r') { // red piece
        if(player == 'b' || dx >= 0) { // black player or invalid move direction
            return 0;
        }
        if(dx == -1 && (dy == 1 || dy == -1)) { // normal move
            return 1;
        }
        if(dx == -2 && (dy == 2 || dy == -2) && board[start_x-1][start_y+(dy/2)] == 'b') { // capturing move
            return 1;
        }
        return 0; // invalid move
    } else { // empty cell
        return 0;
    }
}

// Function to check if the player has won
int has_player_won(char board[][8], char player) {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(board[i][j] == player || board[i][j] == toupper(player)) {
                int dx = 1;
                if(player == 'r') {
                    dx = -1;
                }
                if((i+dx >= 0 && i+dx < 8 && j-1 >= 0 && (board[i+dx][j-1] == ' ' || board[i+dx][j-1] == toupper(player))) ||
                   (i+dx >= 0 && i+dx < 8 && j+1 < 8 && (board[i+dx][j+1] == ' ' || board[i+dx][j+1] == toupper(player)))) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Main function
int main() {
    char board[8][8] = {
        {' ','b',' ','b',' ','b',' ','b'},
        {'b',' ','b',' ','b',' ','b',' '},
        {' ','b',' ','b',' ','b',' ','b'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'r',' ','r',' ','r',' ','r',' '},
        {' ','r',' ','r',' ','r',' ','r'},
        {'r',' ','r',' ','r',' ','r',' '}
    };
    print_board(board);
    char player = 'r';
    while(1) {
        printf("Player %c's turn\n",player);
        int start_x, start_y, end_x, end_y;
        printf("Enter start position (e.g. A2): ");
        scanf("%c%d",&start_x,&start_y); // %c reads the newline character as well, so we need to ignore it
        start_x = (int)(start_x - 'A');
        start_y--;
        getchar(); // Read the newline character
        printf("Enter end position (e.g. B3): ");
        scanf("%c%d",&end_x,&end_y); // %c reads the newline character as well, so we need to ignore it
        end_x = (int)(end_x - 'A');
        end_y--;
        getchar(); // Read the newline character
        if(is_valid_move(board,start_x,start_y,end_x,end_y,player)) {
            make_move(board,start_x,start_y,end_x,end_y);
            print_board(board);
            if(has_player_won(board,player)) {
                printf("Player %c has won!\n",player);
                break;
            }
            if(player == 'r') {
                player = 'b';
            } else {
                player = 'r';
            }
        } else {
            printf("Invalid move\n");
        }
    }
    return 0;
}