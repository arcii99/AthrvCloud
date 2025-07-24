//FormAI DATASET v1.0 Category: Chess AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void display_board(char board[][8]);
void initialize_board(char board[][8]);
void get_best_move(char board[][8], int *x1, int *y1, int *x2, int *y2);
int evaluate_board(char board[][8], char player);
int is_valid_move(char board[][8], int x1, int y1, int x2, int y2);
int is_same_color(char board[][8], int x1, int y1, int x2, int y2);
int is_in_check(char board[][8], char player);
int is_stalemate(char board[][8], char player);

int main()
{
    char board[8][8];
    initialize_board(board);
    display_board(board);
    
    char player = 'w';
    int x1, y1, x2, y2;
    while(1) {
        if(is_in_check(board, player)) {
            printf("%c is in check!\n", player);
        }
        
        if(is_stalemate(board, player)) {
            printf("Stalemate!\n");
            break;
        }
        
        if(player == 'w') {
            printf("White to move: ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            while(!is_valid_move(board, x1, y1, x2, y2)) {
                printf("Invalid move. White to move: ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            }
        }
        else {
            get_best_move(board, &x1, &y1, &x2, &y2);
            printf("Black moves %d %d to %d %d\n", x1, y1, x2, y2);
        }
        
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = '-';
        display_board(board);
        
        player = (player == 'w') ? 'b' : 'w';
    }
    
    return 0;
}

void display_board(char board[][8])
{
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i=0; i<8; i++) {
        printf("%d ", i);
        for(int j=0; j<8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[][8])
{
    // Set up pawns
    for(int i=0; i<8; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    
    // Set up rooks
    board[0][0] = 'R';
    board[0][7] = 'R';
    board[7][0] = 'r';
    board[7][7] = 'r';
    
    // Set up knights
    board[0][1] = 'N';
    board[0][6] = 'N';
    board[7][1] = 'n';
    board[7][6] = 'n';
    
    // Set up bishops
    board[0][2] = 'B';
    board[0][5] = 'B';
    board[7][2] = 'b';
    board[7][5] = 'b';
    
    // Set up kings and queens
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[7][3] = 'q';
    board[7][4] = 'k';
    
    // Set up empty spaces
    for(int i=2; i<6; i++) {
        for(int j=0; j<8; j++) {
            board[i][j] = '-';
        }
    }
}

void get_best_move(char board[][8], int *x1, int *y1, int *x2, int *y2)
{
    srand(time(NULL));
    *x1 = rand() % 8;
    *y1 = rand() % 8;
    *x2 = rand() % 8;
    *y2 = rand() % 8;
    while(!is_valid_move(board, *x1, *y1, *x2, *y2)) {
        *x1 = rand() % 8;
        *y1 = rand() % 8;
        *x2 = rand() % 8;
        *y2 = rand() % 8;
    }
}

int evaluate_board(char board[][8], char player)
{
    int eval = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == 'P' || board[i][j] == 'p') {
                eval += (board[i][j] == player) ? 1 : -1;
            }
            else if(board[i][j] == 'N' || board[i][j] == 'n') {
                eval += (board[i][j] == player) ? 3 : -3;
            }
            else if(board[i][j] == 'B' || board[i][j] == 'b') {
                eval += (board[i][j] == player) ? 3 : -3;
            }
            else if(board[i][j] == 'R' || board[i][j] == 'r') {
                eval += (board[i][j] == player) ? 5 : -5;
            }
            else if(board[i][j] == 'Q' || board[i][j] == 'q') {
                eval += (board[i][j] == player) ? 9 : -9;
            }
        }
    }
    return eval;
}

int is_valid_move(char board[][8], int x1, int y1, int x2, int y2)
{
    if(x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        return 0;
    }
    if(board[x1][y1] == '-' || is_same_color(board, x1, y1, x2, y2)) {
        return 0;
    }
    if(board[x2][y2] != '-') {
        if(board[x1][y1] == 'P' || board[x1][y1] == 'p') {
            if(x1-x2 == 1 || x1-x2 == -1) {
                if(board[x2][y2] == 'K' || board[x2][y2] == 'k') {
                    return 1;
                }
            }
            return 0;
        }
        else if(board[x1][y1] == 'N' || board[x1][y1] == 'n') {
            return 1;
        }
        else if(board[x1][y1] == 'B' || board[x1][y1] == 'b') {
            if(abs(x2-x1) == abs(y2-y1)) {
                int dx = (x2-x1 > 0) ? 1 : -1;
                int dy = (y2-y1 > 0) ? 1 : -1;
                int x = x1+dx;
                int y = y1+dy;
                while(x != x2 && y != y2) {
                    if(board[x][y] != '-') {
                        return 0;
                    }
                    x += dx;
                    y += dy;
                }
                return 1;
            }
            return 0;
        }
        else if(board[x1][y1] == 'R' || board[x1][y1] == 'r') {
            if(x1 == x2 || y1 == y2) {
                int dx = (x2-x1 > 0) ? 1 : (x2-x1 < 0) ? -1 : 0;
                int dy = (y2-y1 > 0) ? 1 : (y2-y1 < 0) ? -1 : 0;
                int x = x1+dx;
                int y = y1+dy;
                while(x != x2 || y != y2) {
                    if(board[x][y] != '-') {
                        return 0;
                    }
                    x += dx;
                    y += dy;
                }
                return 1;
            }
            return 0;
        }
        else if(board[x1][y1] == 'Q' || board[x1][y1] == 'q') {
            if(x1 == x2 || y1 == y2) {
                int dx = (x2-x1 > 0) ? 1 : (x2-x1 < 0) ? -1 : 0;
                int dy = (y2-y1 > 0) ? 1 : (y2-y1 < 0) ? -1 : 0;
                int x = x1+dx;
                int y = y1+dy;
                while(x != x2 || y != y2) {
                    if(board[x][y] != '-') {
                        return 0;
                    }
                    x += dx;
                    y += dy;
                }
                return 1;
            }
            else if(abs(x2-x1) == abs(y2-y1)) {
                int dx = (x2-x1 > 0) ? 1 : -1;
                int dy = (y2-y1 > 0) ? 1 : -1;
                int x = x1+dx;
                int y = y1+dy;
                while(x != x2 && y != y2) {
                    if(board[x][y] != '-') {
                        return 0;
                    }
                    x += dx;
                    y += dy;
                }
                return 1;
            }
            return 0;
        }
        else if(board[x1][y1] == 'K' || board[x1][y1] == 'k') {
            if(abs(x2-x1) <= 1 && abs(y2-y1) <= 1) {
                return 1;
            }
            return 0;
        }
    }
    else {
        if(board[x1][y1] == 'P' || board[x1][y1] == 'p') {
            int dy = (y2-y1 > 0) ? 1 : -1;
            if(x1-x2 == 1 && abs(y2-y1) == 1 && board[x2][y2] != '-') {
                return 1;
            }
            else if(x1-x2 == 2 && y1 == y2 && x1 == 6 && board[x1-1][y1] == '-' && board[x1-2][y1] == '-') {
                return 1;
            }
            else if(x1-x2 == 1 && y1 == y2 && board[x2][y2] == '-') {
                return 1;
            }
            return 0;
        }
    }
    return 0;
}

int is_same_color(char board[][8], int x1, int y1, int x2, int y2)
{
    if(board[x1][y1] == '-' || board[x2][y2] == '-') {
        return 0;
    }
    if(board[x1][y1] < 91 && board[x2][y2] < 91) {
        return 1;
    }
    else if(board[x1][y1] > 96 && board[x2][y2] > 96) {
        return 1;
    }
    return 0;
}

int is_in_check(char board[][8], char player)
{
    int king_row, king_col;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == (player == 'w' ? 'K' : 'k')) {
                king_row = i;
                king_col = j;
                break;
            }
        }
    }
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(!is_same_color(board, king_row, king_col, i, j)) {
                if(is_valid_move(board, i, j, king_row, king_col)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int is_stalemate(char board[][8], char player)
{
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] != '-' && ((player == 'w' && board[i][j] < 91) || (player == 'b' && board[i][j] > 96))) {
                for(int k=0; k<8; k++) {
                    for(int l=0; l<8; l++) {
                        if(is_valid_move(board, i, j, k, l)) {
                            char temp = board[k][l];
                            board[k][l] = board[i][j];
                            board[i][j] = '-';
                            int in_check = is_in_check(board, player);
                            board[i][j] = board[k][l];
                            board[k][l] = temp;
                            if(!in_check) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}