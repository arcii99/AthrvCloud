//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int BOARD_ROWS = 20;
int BOARD_COLS = 30;
int GAME_SPEED = 1000000;

int score = 0;
int lives = 3;
int game_over = 0;

int pac_man_row = 0;
int pac_man_col = 0;

char board[20][30] = {
    {"##############################"},
    {"#............##............#"},
    {"#.####.#####.##.#####.####.#"},
    {"#..........................#"},
    {"#.####.#.#######.#.####.#.#"},
    {"#......#....##....#......#.#"},
    {"######.#.#.##.##.#.#.######"},
    {"######.#.#.##.##.#.#.######"},
    {"######.#.#.##.##.#.#.######"},
    {"......#.#.....#.#.....#...."},
    {"######.#.#.##.##.#.#.######"},
    {"######.#.#.##.##.#.#.######"},
    {"######.#.#.##.##.#.#.######"},
    {"#............##............#"},
    {"#.####.#####.##.#####.####.#"},
    {"#..##............##........#"},
    {"##.##.#.#.#######.#.#.##.##"},
    {"##.##.#.#.#######.#.#.##.##"},
    {"#......#....##....#......#.#"},
    {"##############################"}
};

void display_board() {
    int i, j;
    printf("\nScore: %d   Lives: %d\n", score, lives);
    for(i = 0; i < BOARD_ROWS; i++) {
        printf("%s\n", board[i]);
    }
}

void get_pac_man_position() {
    int i, j;
    for(i = 0; i < BOARD_ROWS; i++) {
        for(j = 0; j < BOARD_COLS; j++) {
            if(board[i][j] == 'P') {
                pac_man_row = i;
                pac_man_col = j;
                break;
            }
        }
    }
}

void move_pac_man(int row, int col) {
    if(board[row][col] == '.') {
        score += 10;
        board[row][col] = 'P';
        board[pac_man_row][pac_man_col] = '.';
        pac_man_row = row;
        pac_man_col = col;
    } else if(board[row][col] == '#') {
        // hitting wall, do nothing
    } else if(board[row][col] == '@') {
        // power pellet
        score += 50;
        board[row][col] = 'P';
        board[pac_man_row][pac_man_col] = '.';
        pac_man_row = row;
        pac_man_col = col;
    } else if(board[row][col] == 'G') {
        // ghost
        lives--;
        if(lives == 0) {
            game_over = 1; // endgame
        } else {
            reset_game(); // reset game
        }
    }
}

void reset_game() {
    int i, j, row, col;
    score = 0;
    game_over = 0;
    
    // reset pac-man position
    pac_man_row = 0;
    pac_man_col = 0;
    
    // reset board
    for(i = 0; i < BOARD_ROWS; i++) {
        for(j = 0; j < BOARD_COLS; j++) {
            if(board[i][j] == 'P' || board[i][j] == '@') {
                board[i][j] = '.';
            } else if(board[i][j] == 'G') {
                board[i][j] = 'O';
            }
        }
    }
    
    // randomly place ghosts on board
    srand(time(NULL));
    for(i = 0; i < 3; i++) {
        row = rand() % BOARD_ROWS;
        col = rand() % BOARD_COLS;
        while(board[row][col] != '.') {
            row = rand() % BOARD_ROWS;
            col = rand() % BOARD_COLS;
        }
        board[row][col] = 'G';
    }
}

void update_board() {
    int i, j;
    int ghost_row, ghost_col;
    int ghost_moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // move ghosts randomly
    for(i = 0; i < BOARD_ROWS; i++) {
        for(j = 0; j < BOARD_COLS; j++) {
            if(board[i][j] == 'G') {
                ghost_row = i;
                ghost_col = j;
                board[ghost_row][ghost_col] = 'O'; // old position
                int move = rand() % 4;
                int new_row = ghost_row + ghost_moves[move][0];
                int new_col = ghost_col + ghost_moves[move][1];
                if(board[new_row][new_col] == '.') {
                    board[new_row][new_col] = 'G';
                } else if(board[new_row][new_col] == 'P') {
                    lives--;
                    if(lives == 0) {
                        game_over = 1; // endgame
                    } else {
                        reset_game(); // reset game
                    }
                } else {
                    // hit wall, do nothing
                    board[ghost_row][ghost_col] = 'G'; // reset position
                }
            }
        }
    }
}

int main() {
    int row_m, col_m;
    char move;

    printf("\n---WELCOME TO DECENZALIZED PAC-MAN---\n");
    printf("INSTRUCTIONS: Collect all the dots (@) to score points. Beware of ghosts (G)! You have 3 lives.\n");
    printf("CONTROLS: WASD/Arrow Keys\n\n");

    display_board();
    while(1) {
        move = getchar(); // read input from user
        switch (move) {
            // move pac-man up
            case 'w':
            case 'W':
            case 'A':
            case 'a':
            case 'S':
            case 's':
            case 'D':
            case 'd':
                row_m = pac_man_row;
                col_m = pac_man_col;
                switch (move) {
                    case 'w':
                    case 'W':
                        if(pac_man_row > 0) {
                            row_m--;
                        }
                        break;
                    case 'a':
                    case 'A':
                        if(pac_man_col > 0) {
                            col_m--;
                        }
                        break;
                    case 's':
                    case 'S':
                        if(pac_man_row < BOARD_ROWS - 1) {
                            row_m++;
                        }
                        break;
                    case 'd':
                    case 'D':
                        if(pac_man_col < BOARD_COLS - 1) {
                            col_m++;
                        }
                        break;
                }
                move_pac_man(row_m, col_m);
                break;
        }
        update_board();
        display_board();
        usleep(GAME_SPEED);
    }
    return 0;
}