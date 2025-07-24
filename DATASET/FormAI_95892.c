//FormAI DATASET v1.0 Category: Chess AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define EMPTY '.'
#define PLAYER1 'P'
#define PLAYER2 'C'

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    board[3][3] = PLAYER1;
    board[4][4] = PLAYER1;
    board[3][4] = PLAYER2;
    board[4][3] = PLAYER2;
}

void display_board() {
    printf(" ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %d", i+1);
    }
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%c", 'A'+i);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col, char player) {
    if(board[row][col] != EMPTY) {
        return 0;
    }
    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int i=0; i<8; i++) {
        int x = row + dx[i];
        int y = col + dy[i];
        if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            continue;
        }
        if(board[x][y] == player) {
            continue;
        }
        int found_player = 0;
        while(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] != EMPTY) {
            if(board[x][y] == player) {
                found_player = 1;
                break;
            }
            x += dx[i];
            y += dy[i];
        }
        if(found_player) {
            return 1;
        }
    }
    return 0;    
}

void make_move(int row, int col, char player) {
    board[row][col] = player;
    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int i=0; i<8; i++) {
        int x = row + dx[i];
        int y = col + dy[i];
        if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            continue;
        }
        if(board[x][y] == player) {
            continue;
        }
        int found_player = 0;
        while(x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] != EMPTY) {
            if(board[x][y] == player) {
                found_player = 1;
                break;
            }
            x += dx[i];
            y += dy[i];
        }
        if(found_player) {
            int x2 = row + dx[i];
            int y2 = col + dy[i];
            while(x2 != x || y2 != y) {
                board[x2][y2] = player;
                x2 += dx[i];
                y2 += dy[i];
            }
        }
    }
}

int count_pieces(char player) {
    int count = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                count++;
            }
        }
    }
    return count;
}

void computer_move() {
    int max_score = 0;
    int best_row = 0, best_col = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(is_valid_move(i, j, PLAYER2)) {
                char temp_board[BOARD_SIZE][BOARD_SIZE];
                for(int x=0; x<BOARD_SIZE; x++) {
                    for(int y=0; y<BOARD_SIZE; y++) {
                        temp_board[x][y] = board[x][y];
                    }
                }
                make_move(i, j, PLAYER2);
                int score = count_pieces(PLAYER2);
                if(score > max_score) {
                    max_score = score;
                    best_row = i;
                    best_col = j;
                }
                for(int x=0; x<BOARD_SIZE; x++) {
                    for(int y=0; y<BOARD_SIZE; y++) {
                        board[x][y] = temp_board[x][y];
                    } 
                }
            }
        }
    }
    printf("Computer plays %c%d\n", 'A'+best_row, best_col+1);
    make_move(best_row, best_col, PLAYER2);
}

int get_valid_move(char player, int *row, int *col) {
    char input[10];
    printf("Enter move for %c: ", player);
    scanf("%s", input);
    if(input[0] < 'A' || input[0] >= 'A'+BOARD_SIZE) {
        printf("Invalid row %c\n", input[0]);
        return 0;
    }
    if(input[1] < '1' || input[1] >= '1'+BOARD_SIZE) {
        printf("Invalid column %c\n", input[1]);
        return 0;
    }
    int r = input[0] - 'A';
    int c = input[1] - '1';
    if(!is_valid_move(r, c, player)) {
        printf("Invalid move %c%d\n", input[0], input[1]-'0');
        return 0;
    }
    *row = r;
    *col = c;
    return 1;
}

int main() {
    srand(time(NULL));
    init_board();
    display_board();
    char winner = EMPTY;
    while(winner == EMPTY) {
        int row, col;
        if(get_valid_move(PLAYER1, &row, &col)) {
            make_move(row, col, PLAYER1);
        }
        display_board();
        if(count_pieces(PLAYER1) == 0) {
            winner = PLAYER2;
        } else if(count_pieces(PLAYER2) == 0) {
            winner = PLAYER1;
        } else if(count_pieces(EMPTY) == 0) {
            int score1 = count_pieces(PLAYER1);
            int score2 = count_pieces(PLAYER2);
            if(score1 > score2) {
                winner = PLAYER1;
            } else if(score2 > score1) {
                winner = PLAYER2;
            } else {
                winner = '.';
            }
        }
        if(winner != EMPTY) {
            break;
        }
        computer_move();
        display_board();
        if(count_pieces(PLAYER1) == 0) {
            winner = PLAYER2;
        } else if(count_pieces(PLAYER2) == 0) {
            winner = PLAYER1;
        } else if(count_pieces(EMPTY) == 0) {
            int score1 = count_pieces(PLAYER1);
            int score2 = count_pieces(PLAYER2);
            if(score1 > score2) {
                winner = PLAYER1;
            } else if(score2 > score1) {
                winner = PLAYER2;
            } else {
                winner = '.';
            }
        }
        if(winner != EMPTY) {
            break;
        }
    }
    if(winner == '.') {
        printf("Tie game!\n");
    } else {
        printf("%c wins!\n", winner);
    }
    return 0;
}