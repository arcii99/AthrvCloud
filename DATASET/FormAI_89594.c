//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20

int pac_man_x, pac_man_y;
int ghost_x, ghost_y;
int score = 0;
char board[ROW][COL];

void init_board() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(i == 0 || i == ROW - 1 || j == 0 || j == COL - 1) {
                board[i][j] = '#';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }
    pac_man_x = ROW / 2;
    pac_man_y = COL / 2;
    ghost_x = 1;
    ghost_y = 1;
    board[pac_man_x][pac_man_y] = 'P';
    board[ghost_x][ghost_y] = 'G';
}

void display_board() {
    system("clear");
    printf("SCORE: %d\n", score);
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void update_board(char key) {
    switch(key) {
        case 'w':
            if(board[pac_man_x - 1][pac_man_y] != '#') {
                if(board[pac_man_x - 1][pac_man_y] == 'G') {
                    score += 10;
                    ghost_x = 1;
                    ghost_y = 1;
                    board[ghost_x][ghost_y] = 'G';
                }
                board[pac_man_x][pac_man_y] = ' ';
                board[--pac_man_x][pac_man_y] = 'P';
            }
            break;
        case 'a':
            if(board[pac_man_x][pac_man_y - 1] != '#') {
                if(board[pac_man_x][pac_man_y - 1] == 'G') {
                    score += 10;
                    ghost_x = 1;
                    ghost_y = 1;
                    board[ghost_x][ghost_y] = 'G';
                }
                board[pac_man_x][pac_man_y] = ' ';
                board[pac_man_x][--pac_man_y] = 'P';
            }
            break;
        case 's':
            if(board[pac_man_x + 1][pac_man_y] != '#') {
                if(board[pac_man_x + 1][pac_man_y] == 'G') {
                    score += 10;
                    ghost_x = 1;
                    ghost_y = 1;
                    board[ghost_x][ghost_y] = 'G';
                }
                board[pac_man_x][pac_man_y] = ' ';
                board[++pac_man_x][pac_man_y] = 'P';
            }
            break;
        case 'd':
            if(board[pac_man_x][pac_man_y + 1] != '#') {
                if(board[pac_man_x][pac_man_y + 1] == 'G') {
                    score += 10;
                    ghost_x = 1;
                    ghost_y = 1;
                    board[ghost_x][ghost_y] = 'G';
                }
                board[pac_man_x][pac_man_y] = ' ';
                board[pac_man_x][++pac_man_y] = 'P';
            }
            break;
        default:
            break;
    }

    int direction = rand() % 4;
    switch(direction) {
        case 0:
            if(board[ghost_x - 1][ghost_y] != '#') {
                board[ghost_x][ghost_y] = ' ';
                board[--ghost_x][ghost_y] = 'G';
            }
            break;
        case 1:
            if(board[ghost_x][ghost_y - 1] != '#') {
                board[ghost_x][ghost_y] = ' ';
                board[ghost_x][--ghost_y] = 'G';
            }
            break;
        case 2:
            if(board[ghost_x + 1][ghost_y] != '#') {
                board[ghost_x][ghost_y] = ' ';
                board[++ghost_x][ghost_y] = 'G';
            }
            break;
        case 3:
            if(board[ghost_x][ghost_y + 1] != '#') {
                board[ghost_x][ghost_y] = ' ';
                board[ghost_x][++ghost_y] = 'G';
            }
            break;
        default:
            break;
    }
}

int main() {
    srand(time(NULL));
    init_board();
    while(1) {
        display_board();
        char key = getchar();
        getchar();
        update_board(key);
    }
    return 0;
}