//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 3

char board[BOARD_SIZE][BOARD_SIZE];

void print_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d. ", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("   a b c d e f g h\n\n");
}

int evaluate_board(char color) {
    int value = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == ' ') continue;
            int piece_value = 0;
            switch(board[i][j]) {
                case 'P':
                case 'p':
                    piece_value = 1;
                    break;
                case 'N':
                case 'n':
                case 'B':
                case 'b':
                    piece_value = 3;
                    break;
                case 'R':
                case 'r':
                    piece_value = 5;
                    break;
                case 'Q':
                case 'q':
                    piece_value = 9;
                    break;
            }
            if(board[i][j] == color || board[i][j] == color-'a'+'A') {
                value += piece_value;
            } else {
                value -= piece_value;
            }
        }
    }
    return value;
}

int minmax(int depth, int alpha, int beta, char color) {
    if(depth == 0) return evaluate_board(color);
    int best_value = color == 'w' ? -1000 : 1000;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == ' ' || (color == 'w' && board[i][j] >= 'a' && board[i][j] <= 'z') || (color == 'b' && board[i][j] >= 'A' && board[i][j] <= 'Z')) continue;
            for(int k=0; k<BOARD_SIZE; k++) {
                for(int l=0; l<BOARD_SIZE; l++) {
                    if(i==k && j==l) continue;
                    char origin = board[i][j];
                    char dest = board[k][l];
                    board[k][l] = board[i][j];
                    board[i][j] = ' ';
                    int value = minmax(depth-1, alpha, beta, color == 'w' ? 'b' : 'w');
                    if(color == 'w' && value > best_value) {
                        best_value = value;
                        if(depth == MAX_DEPTH) {
                            printf(" %c%c%c%c  |\n", j+'a', i+1+'0', l+'a', k+1+'0');
                        }
                        alpha = value > alpha ? value : alpha;
                    } else if(color == 'b' && value < best_value) {
                        best_value = value;
                        if(depth == MAX_DEPTH) {
                            printf(" %c%c%c%c  |\n", j+'a', i+1+'0', l+'a', k+1+'0');
                        }
                        beta = value < beta ? value : beta;
                    }
                    board[i][j] = origin;
                    board[k][l] = dest;
                    if(alpha >= beta) return best_value;
                }
            }
        }
    }
    return best_value;
}

void print_moves(char color) {
    printf("    ------------\n");
    printf("     moves  \n");
    printf("    ------------\n");
    minmax(MAX_DEPTH, -1000, 1000, color);
    printf("    ------------\n");
}

int main() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    board[0][0] = board[0][7] = 'R';
    board[1][0] = board[1][7] = 'N';
    board[2][0] = board[2][7] = 'B';
    board[3][0] = board[3][7] = 'Q';
    board[4][0] = board[4][7] = 'K';
    board[5][0] = board[5][7] = 'B';
    board[6][0] = board[6][7] = 'N';
    board[7][0] = board[7][7] = 'R';
    for(int i=0; i<BOARD_SIZE; i++) {
        board[i][1] = 'P';
        board[i][6] = 'p';
    }
    print_board();
    char color = 'w';
    while(1) {
        print_moves(color);
        printf(" %c's turn:\n", color);
        char input[10];
        scanf("%s", input);
        if(input[0] == 'q') {
            break;
        }
        int from_col = input[0]-'a';
        int from_row = input[1]-'0'-1;
        int to_col = input[2]-'a';
        int to_row = input[3]-'0'-1;
        char origin = board[from_row][from_col];
        char dest = board[to_row][to_col];
        board[to_row][to_col] = board[from_row][from_col];
        board[from_row][from_col] = ' ';
        print_board();
        color = color == 'w' ? 'b' : 'w';
    }
    return 0;
}